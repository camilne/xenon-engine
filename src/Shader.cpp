#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "Shader.hpp"

std::string xe::Shader::kRelativePath = "";
std::string xe::Shader::kVertexExtension = ".vs";
std::string xe::Shader::kFragmentExtension = ".fs";

xe::Shader::Shader(const std::string& name)
        : name_{name}, id_{0} {
    loadShaders(kRelativePath + name + kVertexExtension, kRelativePath + name + kFragmentExtension);
}

void xe::Shader::bind() const {
    glUseProgram(id_);
}

void xe::Shader::loadShaders(const std::string& vertexPath, const std::string& fragmentPath) {
    GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

    if(!loadAndCompileSource(vertexId, vertexPath) || !loadAndCompileSource(fragmentId, fragmentPath)) {
        std::cerr << "Failed to load shaders" << std::endl;
    }

    id_ = glCreateProgram();
    glAttachShader(id_, vertexId);
    glAttachShader(id_, fragmentId);

    glLinkProgram(id_);

    GLint result = GL_FALSE;
    glGetProgramiv(id_, GL_LINK_STATUS, &result);
    if (result == GL_FALSE) {
        int infoLogLength;
        glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> errorMessage(static_cast<unsigned int>(infoLogLength) + 1);
        glGetProgramInfoLog(id_, infoLogLength, nullptr, &errorMessage[0]);
        std::cerr << std::string(begin(errorMessage), end(errorMessage)) << std::endl;
    }

    glDetachShader(id_, vertexId);
    glDetachShader(id_, fragmentId);

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
}

bool xe::Shader::loadAndCompileSource(const GLuint& sid, const std::string& filePath) {
    std::ifstream fileIn(filePath);

    if (fileIn.fail()) {
        std::cerr << "Failed to open: " + filePath << std::endl;
        return false;
    }

    std::string source;
    std::string line;
    while (getline(fileIn, line)) {
        source += line + "\n";
    }

    fileIn.close();

    //std::cout << "Compiling Shader: " << filePath << std::endl;
    const char* c_src = source.c_str();
    glShaderSource(sid, 1, &c_src, nullptr);
    glCompileShader(sid);

    GLint result = GL_FALSE;
    glGetShaderiv(sid, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        int infoLogLength;
        glGetShaderiv(sid, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> errorMessage(static_cast<unsigned int>(infoLogLength) + 1);
        glGetShaderInfoLog(sid, infoLogLength, nullptr, &errorMessage[0]);
        std::cerr << std::string(begin(errorMessage), end(errorMessage)) << std::endl;

        return false;
    }

    return true;
}

void xe::Shader::createUniformIfNeeded(const std::string& name) {
    if (uniforms_.find(name) == end(uniforms_)) {

        GLint location = glGetUniformLocation(id_, name.c_str());
        if (location < 0) {
            std::cout << "Error locating uniform " << name << " in " << name_ << " shader." << std::endl;
        }

        uniforms_[name] = location;
    }
}

void xe::Shader::setUniform(const std::string& name, const glm::mat3& val) {
    createUniformIfNeeded(name);
    glUniformMatrix3fv(uniforms_[name], 1, GL_FALSE, &val[0][0]);
}

void xe::Shader::setUniform(const std::string& name, const glm::mat4& val) {
    createUniformIfNeeded(name);
    glUniformMatrix4fv(uniforms_[name], 1, GL_FALSE, &val[0][0]);
}

void xe::Shader::setUniform(const std::string& name, const glm::vec3& val) {
    createUniformIfNeeded(name);
    glUniform3f(uniforms_[name], val.x, val.y, val.z);
}

void xe::Shader::setUniform(const std::string& name, const glm::vec2& val) {
    createUniformIfNeeded(name);
    glUniform2f(uniforms_[name], val.x, val.y);
}

void xe::Shader::setUniform(const std::string& name, GLfloat val) {
    createUniformIfNeeded(name);
    glUniform1f(uniforms_[name], val);
}

void xe::Shader::setUniform(const std::string& name, GLint val) {
    createUniformIfNeeded(name);
    glUniform1i(uniforms_[name], val);
}
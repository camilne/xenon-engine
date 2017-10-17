#ifndef XENON_SHADER_HPP
#define XENON_SHADER_HPP

#include <string>
#include <glad/glad.h>
#include <unordered_map>
#include <glm/glm.hpp>

namespace xe {

class Shader {
public:
    explicit Shader(const std::string& name);

    void bind() const;

    void setUniform(const std::string& name, const glm::mat3& val);
    void setUniform(const std::string& name, const glm::mat4& val);
    void setUniform(const std::string& name, const glm::vec3& val);
    void setUniform(const std::string& name, const glm::vec2& val);
    void setUniform(const std::string& name, GLfloat val);
    void setUniform(const std::string& name, GLint val);
private:
    static std::string kRelativePath;
    static std::string kVertexExtension;
    static std::string kFragmentExtension;

    std::string name_;
    GLuint id_;
    std::unordered_map<std::string, GLint> uniforms_;

    void loadShaders(const std::string& vertexPath, const std::string& fragmentPath);
    bool loadAndCompileSource(const GLuint& sid, const std::string& filePath);
    void createUniformIfNeeded(const std::string& name);
};

}

#endif //XENON_SHADER_HPP

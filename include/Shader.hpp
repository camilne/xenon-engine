#ifndef XENON_SHADER_HPP
#define XENON_SHADER_HPP

#include <string>
#include <glad/glad.h>
#include <unordered_map>

namespace xe {

class Shader {
public:
    explicit Shader(const std::string& name);

    void bind() const;
private:
    static std::string kRelativePath;
    static std::string kVertexExtension;
    static std::string kFragmentExtension;

    std::string name_;
    GLuint id_;
    std::unordered_map<std::string, GLuint> uniforms;

    void loadShaders(const std::string& vertexPath, const std::string& fragmentPath);
    bool loadAndCompileSource(const GLuint& sid, const std::string& filePath);
};

}

#endif //XENON_SHADER_HPP

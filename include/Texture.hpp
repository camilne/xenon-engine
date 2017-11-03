#ifndef XENON_TEXTURE_HPP
#define XENON_TEXTURE_HPP

#include <string>
#include <glad/glad.h>

class Texture {
public:
    explicit Texture(const std::string& path);

    void bind() const;
private:
    GLuint id_;
    GLint width_;
    GLint height_;
};

#endif //XENON_TEXTURE_HPP

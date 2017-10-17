#ifndef XENON_IAPPLICATION_HPP
#define XENON_IAPPLICATION_HPP

#include <memory>
#include <glad/glad.h>

namespace xe {

class IApplication {
    friend class Engine;
public:
    IApplication(int width, int height);

    GLuint getFrame() const;
    void preRender() const;
    void postRender() const;
protected:
    int width_;
    int height_;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
private:
    GLuint frameBuffer_;
    GLuint renderedTexture_;

    void initFramebuffer();
};

}

#endif //XENON_IAPPLICATION_HPP

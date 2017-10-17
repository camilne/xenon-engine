#ifndef XENON_IRENDERER_HPP
#define XENON_IRENDERER_HPP

#include <glad/glad.h>
#include <functional>

namespace xe {

class IRenderer {
public:
    IRenderer(int width, int height);

    GLuint getFrame() const;
    void renderScene();
protected:
    int width_;
    int height_;

    virtual void render() = 0;
private:
    GLuint frameBuffer_;
    GLuint renderedTexture_;

    void init();
};

}

#endif //XENON_IRENDERER_HPP

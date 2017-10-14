#ifndef XENON_RENDERER_HPP
#define XENON_RENDERER_HPP

#include <glad/glad.h>
#include <functional>

namespace xe {

class Renderer {
public:
    Renderer(int width, int height, const std::function<void()>& renderFunction);

    GLuint getFrame() const;
    void renderScene();
private:
    int width_;
    int height_;
    std::function<void()> renderFunction_;
    GLuint frameBuffer_;
    GLuint renderedTexture_;

    void init();
};

}

#endif //XENON_RENDERER_HPP

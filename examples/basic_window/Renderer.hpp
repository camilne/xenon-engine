#ifndef XENON_RENDERER_HPP
#define XENON_RENDERER_HPP

#include <IRenderer.hpp>
#include <Shader.hpp>

class Renderer : public xe::IRenderer {
public:
    Renderer(int width, int height);
protected:
    void render();
private:
    GLuint mesh_;
    xe::Shader shader_;

    void init();
};


#endif //XENON_RENDERER_HPP

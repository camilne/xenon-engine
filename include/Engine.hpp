#ifndef XENON_ENGINE_HPP
#define XENON_ENGINE_HPP

#include <memory>
#include <glad/glad.h>
#include "Window.hpp"
#include "IRenderer.hpp"

namespace xe {

class Engine {
public:
    Engine();

    void createWindow(int width, int height, std::string title);
    void attachRenderer(IRenderer* renderer);
    void run();
private:
    std::unique_ptr<Window> window_;
    IRenderer* renderer_;
    GLuint frameMesh_;

    static void kDefaultErrorFun(int error, const char* description);
};

}

#endif //XENON_ENGINE_HPP

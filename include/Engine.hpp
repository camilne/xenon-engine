#ifndef XENON_ENGINE_HPP
#define XENON_ENGINE_HPP

#include <memory>
#include <glad/glad.h>
#include "Window.hpp"
#include "Renderer.hpp"

namespace xe {

class Engine {
public:
    Engine();

    void createWindow(int width, int height, std::string title);
    void attachRenderer(const std::function<void()>& renderFunction);
    void run();
private:
    std::unique_ptr<Window> window_;
    std::unique_ptr<Renderer> renderer_;
    GLuint frameMesh_;

    static void kDefaultErrorFun(int error, const char* description);
};

}

#endif //XENON_ENGINE_HPP

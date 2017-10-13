#include "Engine.hpp"
#include <iostream>
#include <glad/glad.h>

namespace xe {

Engine::Engine() : window_{nullptr} {
    Window::setErrorCallback(kDefaultErrorFun);
}

void Engine::createWindow(int width, int height, std::string title) {
    window_ = std::make_unique<Window>(width, height, title);
}

void Engine::run() {
    if(!window_)
        return;

    while (!window_->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        window_->update();
    }
}

void Engine::kDefaultErrorFun(int error, const char* description) {
    std::cerr << "GLFW error " << error << ": " << description << std::endl;
}

}
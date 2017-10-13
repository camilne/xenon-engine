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

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenBuffers(1, &frameMesh_);
    const GLfloat vertices[] = {
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, frameMesh_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    while (!window_->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, frameMesh_);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        window_->update();
    }
}

void Engine::kDefaultErrorFun(int error, const char* description) {
    std::cerr << "GLFW error " << error << ": " << description << std::endl;
}

}
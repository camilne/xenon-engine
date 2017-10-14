#include "Engine.hpp"
#include <iostream>

namespace xe {

Engine::Engine() : window_{nullptr}, renderer_{nullptr} {
    Window::setErrorCallback(kDefaultErrorFun);
}

void Engine::createWindow(int width, int height, std::string title) {
    window_ = std::make_unique<Window>(width, height, title);
}

void Engine::attachRenderer(const std::function<void()>& renderFunction) {
    renderer_ = std::make_unique<Renderer>(window_->getWidth(), window_->getHeight(), renderFunction);
}

void Engine::run() {
    if(!window_ || !renderer_)
        return;

    glEnable(GL_TEXTURE_2D);

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

    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    while (!window_->shouldClose()) {
        renderer_->renderScene();
        GLuint frame = renderer_->getFrame();
        glBindTexture(GL_TEXTURE_2D, frame);

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
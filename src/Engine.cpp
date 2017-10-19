#include "Engine.hpp"
#include <iostream>
#include <Shader.hpp>

namespace xe {

Engine::Engine() : window_{nullptr}, application_{nullptr} {
    Window::setErrorCallback(kDefaultErrorFun);
}

void Engine::createWindow(int width, int height, std::string title) {
    window_ = std::make_unique<Window>(width, height, title);
}

void Engine::attachApplication(std::unique_ptr<IApplication> application) {
    application_ = std::move(application);
}

void Engine::run() {
    if(!window_ || !application_)
        return;

    GLuint vertexArrayId;
    glGenVertexArrays(1, &vertexArrayId);
    glBindVertexArray(vertexArrayId);

    GLuint frameVertices;
    glGenBuffers(1, &frameVertices);
    const GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, frameVertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // TODO: Fix path hack
    Shader shader("../../shaders/pass_through");

    glClearColor(0.4f, 0.3f, 0.8f, 1);

    window_->setKeyCallback(IApplication::keyCallback);
    window_->setCursorPosCallback(Input::cursorPosCallback);
    window_->setWindowUserPointer(static_cast<void*>(application_.get()));

    application_->init();

    while (!window_->shouldClose()) {
        application_->update();

        application_->preRender();
        glClear(GL_COLOR_BUFFER_BIT);
        application_->render();
        application_->postRender();

        GLuint frame = application_->getFrame();
        glBindTexture(GL_TEXTURE_2D, frame);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.bind();

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, frameVertices);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

        glDrawArrays(GL_TRIANGLES, 0, 6);

        GLint error = glGetError();
        if(error != GL_NO_ERROR)
            std::cerr << "[opengl] Error: " << error << std::endl;

        window_->update();
    }
}

void Engine::kDefaultErrorFun(int error, const char* description) {
    std::cerr << "GLFW error " << error << ": " << description << std::endl;
}

}
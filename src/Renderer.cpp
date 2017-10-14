#include <iostream>
#include "Renderer.hpp"

xe::Renderer::Renderer(int width, int height, const std::function<void()>& renderFunction)
        : width_{width}, height_{height}, renderFunction_(renderFunction) {
    init();
}

GLuint xe::Renderer::getFrame() const {
    return renderedTexture_;
}

void xe::Renderer::init() {
    glGenFramebuffers(1, &frameBuffer_);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);

    glGenTextures(1, &renderedTexture_);
    glBindTexture(GL_TEXTURE_2D, renderedTexture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture_, 0);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        // Logger::log(Logger::ERROR, "Display framebuffer is not complete");
        std::cerr << "Display framebuffer is not complete" << std::endl;
    }
}

void xe::Renderer::renderScene() {
    glViewport(0, 0, width_, height_);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);

    renderFunction_();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

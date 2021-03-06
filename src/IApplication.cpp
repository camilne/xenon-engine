#include <glad/glad.h>
#include <iostream>
#include "IApplication.hpp"

xe::IApplication::IApplication(int width, int height)
        : width_{width}, height_{height} {
    initFramebuffer();
}

GLuint xe::IApplication::getFrame() const {
    return renderedTexture_;
}

void xe::IApplication::initFramebuffer() {
    glGenFramebuffers(1, &frameBuffer_);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);

    glGenTextures(1, &renderedTexture_);
    glBindTexture(GL_TEXTURE_2D, renderedTexture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture_, 0);

    GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBuffers);

    GLuint depthrenderbuffer;
    glGenRenderbuffers(1, &depthrenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width_, height_);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        // Logger::log(Logger::ERROR, "Display framebuffer is not complete");
        std::cerr << "Display framebuffer is not complete" << std::endl;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void xe::IApplication::preRender() const {
    glViewport(0, 0, width_, height_);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer_);
}

void xe::IApplication::postRender() const {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void xe::IApplication::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input::keyCallback(window, key, scancode, action, mods);
    IApplication* app = (IApplication*)glfwGetWindowUserPointer(window);

    if(action == GLFW_PRESS) {
        app->keyPressed(key, mods);
    } else if(action == GLFW_RELEASE) {
        app->keyReleased(key, mods);
    }
}

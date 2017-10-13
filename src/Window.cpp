#include "Window.hpp"
#include <glad/glad.h>
#include <iostream>

namespace xe {

Window::Window(int width, int height, const std::string& title)
        : handle_{nullptr}, width_{width}, height_{height}, title_{title} {
    init();
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(handle_) > 0;
}

void Window::update() const {
    glfwSwapBuffers(handle_);
    glfwPollEvents();
}

void Window::init() {
    if (!glfwInit()) {
        // Logger::log(Logger::ERROR, "Unable to initialize GLFW");
        // System::exit(1);
        std::cout << "Unable to initialize GLFW" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
    if (!handle_) {
        // Logger::log(Logger::ERROR, "Unable to create GLFW window");
        // System::exit(1);
        std::cout << "Unable to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(handle_);

    if (!gladLoadGL()) {
        // Logger::log(Logger::ERROR, "Unable to initialize GLAD");
        // System::exit(1);
        std::cout << "Unable to initialize GLAD" << std::endl;
        glfwDestroyWindow(handle_);
        glfwTerminate();
    }
}

}
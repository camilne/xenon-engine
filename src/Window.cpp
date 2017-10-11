#include "Window.hpp"
#include <glad/glad.h>
#include <iostream>

namespace xe {

    Window::Window(int width, int height, const std::string& title)
            : m_handle{nullptr}, m_width{width}, m_height{height}, m_title{title} {
        init();
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(m_handle) > 0;
    }

    void Window::update() const {
        glfwSwapBuffers(m_handle);
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

        m_handle = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_handle) {
            // Logger::log(Logger::ERROR, "Unable to create GLFW window");
            // System::exit(1);
            std::cout << "Unable to create GLFW window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(m_handle);

        if (!gladLoadGL()) {
            // Logger::log(Logger::ERROR, "Unable to initialize GLAD");
            // System::exit(1);
            std::cout << "Unable to initialize GLAD" << std::endl;
            glfwDestroyWindow(m_handle);
            glfwTerminate();
        }
    }

}
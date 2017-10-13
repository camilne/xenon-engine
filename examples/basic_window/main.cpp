#include "Window.hpp"

void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

int main(int argc, char* argv[]) {
    xe::Window window(1280, 720, "My Basic Window");
    xe::Window::setErrorCallback(errorCallback);

    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        window.update();
    }

    return 0;
}
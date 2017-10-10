#include "library.h"

#include <iostream>
#include <GLFW/glfw3.h>

void errorCallback(int error, const char* description) {
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

int main(int argc, char* argv[]) {
    glfwSetErrorCallback(errorCallback);

    GLFWwindow* window = createWindow();
    if (!window) {
        return 0;
    }

    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
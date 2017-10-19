#ifndef XENON_INPUT_HPP
#define XENON_INPUT_HPP

#include <GLFW/glfw3.h>

namespace xe {

class Input {
public:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

    static bool isKeyPressed(unsigned int key);
    static double getDx();
    static double getDy();
private:
    static const int kNumKeys = 1024;

    static bool keys_[kNumKeys];
    static double lastMouseX_;
    static double lastMouseY_;
    static double mouseX_;
    static double mouseY_;
};

}

#endif //XENON_INPUT_HPP

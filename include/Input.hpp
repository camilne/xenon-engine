#ifndef XENON_INPUT_HPP
#define XENON_INPUT_HPP

#include <GLFW/glfw3.h>

namespace xe {

class Input {
public:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static bool isKeyPressed(unsigned int key);
private:
    static const int kNumKeys = 1024;

    static bool keys_[kNumKeys];
};

}

#endif //XENON_INPUT_HPP

#include "Input.hpp"

bool xe::Input::keys_[];

void xe::Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

bool xe::Input::isKeyPressed(unsigned int key) {
    return keys_[key];
}

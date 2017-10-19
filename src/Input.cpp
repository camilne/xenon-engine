#include "Input.hpp"

bool xe::Input::keys_[];
double xe::Input::lastMouseX_ = 0;
double xe::Input::lastMouseY_ = 0;
double xe::Input::mouseX_ = 0;
double xe::Input::mouseY_ = 0;

void xe::Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS)
        keys_[key] = true;
    else if(action == GLFW_RELEASE)
        keys_[key] = false;
}

void xe::Input::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    lastMouseX_ = mouseX_;
    lastMouseY_ = mouseY_;

    mouseX_ = xpos;
    mouseY_ = ypos;
}

bool xe::Input::isKeyPressed(unsigned int key) {
    return keys_[key];
}

double xe::Input::getDx() {
    double dx = mouseX_ - lastMouseX_;
    lastMouseX_ = mouseX_;
    return dx;
}

double xe::Input::getDy() {
    double dy = mouseY_ - lastMouseY_;
    lastMouseY_ = mouseY_;
    return dy;
}

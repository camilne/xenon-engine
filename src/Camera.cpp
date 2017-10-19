#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Input.hpp"

namespace xe {

Camera Camera::createPerspective(float fovy, float aspect, float zNear, float zFar) {
    return Camera(glm::perspective(glm::radians(fovy), aspect, zNear, zFar));
}

Camera& Camera::lookAt(const glm::vec3& center) {
    forward_ = glm::normalize(center - position_);
    update();
    return *this;
}

void Camera::update() {
    view_ = glm::lookAt(position_, position_ + forward_, up_);
}

void Camera::processInput(double deltaTime) {
    yaw_ = glm::mod(yaw_ + Input::getDx() * sensitivity_, 360.0);
    pitch_ -= Input::getDy() * sensitivity_;

    if (pitch_ > 89.0)
        pitch_ = 89.0;
    if (pitch_ < -89.0)
        pitch_ = -89.0;

    forward_.x = static_cast<float>(cos(glm::radians(yaw_)) * cos(glm::radians(pitch_)));
    forward_.y = static_cast<float>(sin(glm::radians(pitch_)));
    forward_.z = static_cast<float>(sin(glm::radians(yaw_)) * cos(glm::radians(pitch_)));

    forward_ = glm::normalize(forward_);

    float frameSpeed = static_cast<float>(speed_ * deltaTime);

    if (Input::isKeyPressed(GLFW_KEY_W)) {
        position_ += frameSpeed * forward_;
    } else if (Input::isKeyPressed(GLFW_KEY_S)) {
        position_ -= frameSpeed * forward_;
    }

    if (Input::isKeyPressed(GLFW_KEY_A)) {
        position_ -= frameSpeed * glm::normalize(glm::cross(forward_, up_));
    } else if (Input::isKeyPressed(GLFW_KEY_D)) {
        position_ += frameSpeed * glm::normalize(glm::cross(forward_, up_));
    }

    if (Input::isKeyPressed(GLFW_KEY_SPACE)) {
        position_ += frameSpeed * up_;
    } else if (Input::isKeyPressed(GLFW_KEY_LEFT_SHIFT)) {
        position_ -= frameSpeed * up_;
    }

    update();
}

void Camera::setSensitivity(double sensitivity) {
    if(sensitivity < 0.0)
        sensitivity = 0.0;
    sensitivity_ = sensitivity;
}

void Camera::setSpeed(double speed) {
    if(speed < 0.0)
        speed = 0.0;
    speed_ = speed;
}

}
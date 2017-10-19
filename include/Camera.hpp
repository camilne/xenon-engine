#ifndef XENON_CAMERA_HPP
#define XENON_CAMERA_HPP

#include <glm/glm.hpp>

namespace xe {

class Camera {
public:
    static Camera createPerspective(float fov, float aspect, float zNear, float zFar);

    Camera& lookAt(const glm::vec3& center);

    void update();
    void processInput(double deltaTime);

    void setSensitivity(double sensitivity);
    void setSpeed(double speed);

    const Camera& setPosition(const glm::vec3& position) {
      this->position_ = position;
      return *this;
    }

    inline const glm::vec3& getPosition() const {
      return position_;
    }

    inline const glm::mat4& getView() const {
      return view_;
    }

    inline const glm::mat4& getProjection() const {
      return projection_;
    }
private:
    glm::mat4 view_;
    glm::mat4 projection_;

    glm::vec3 position_;
    glm::vec3 up_;
    glm::vec3 forward_;

    double yaw_;
    double pitch_;

    double sensitivity_;
    double speed_;

    explicit Camera(glm::mat4 projection)
            : view_{glm::mat4()}, projection_{projection}, position_(0.0f), up_(0.0f, 1.0f, 0.0f),
              forward_(0.0f, 0.0f, -1.0f), yaw_(-90.0), pitch_(0.0) {}
};

}

#endif
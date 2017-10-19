#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Application.hpp"

Application::Application(int width, int height)
        : IApplication(width, height), shader_(xe::Shader("free_camera")),
          camera_{xe::Camera::createPerspective(70.0f, static_cast<float>(width) / height, 0.01f, 100.0f)} {

}

void Application::init() {
    glGenBuffers(1, &mesh_);
    const GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.75f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, mesh_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    camera_.setSpeed(1.0);
    camera_.setSensitivity(0.3);
    camera_.setPosition(glm::vec3(1.0f, 1.0f, 2.0f));
    camera_.lookAt(glm::vec3(0.0f));
    camera_.update();

    model_ = glm::mat4(1.0f);

    shader_.bind();
    shader_.setUniform("m_proj", camera_.getProjection());
    shader_.setUniform("m_model", model_);
}

void Application::update() {
    camera_.processInput(1.0/60.0 * 0.1);
    camera_.update();
}

void Application::render() {
    shader_.bind();
    shader_.setUniform("m_view", camera_.getView());

    glBindBuffer(GL_ARRAY_BUFFER, mesh_);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

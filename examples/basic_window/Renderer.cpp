#include <glad/glad.h>
#include <IRenderer.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <Shader.hpp>
#include "Renderer.hpp"

Renderer::Renderer(int width, int height)
        : xe::IRenderer(width, height), shader_(xe::Shader("basic_window")), model_{glm::mat4(0.0f)},
          view_{glm::mat4(0.0f)}, proj_{glm::mat4(0.0f)} {
    init();
}

void Renderer::render() {
    shader_.bind();

    glBindBuffer(GL_ARRAY_BUFFER, mesh_);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::init() {
    glGenBuffers(1, &mesh_);
    const GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.75f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, mesh_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    model_ = glm::scale(glm::mat4(1.0f), glm::vec3(0.75f));

    view_ = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f));
    view_ = glm::rotate(view_, 0.5f, glm::vec3(-1.0f, 0.0f, 0.0f));
    view_ = glm::rotate(view_, 0.3f, glm::vec3(0.0f, 1.0f, 0.0f));

    proj_ = glm::perspective(glm::pi<float>() * 0.25f, static_cast<float>(width_)/height_, 0.1f, 100.0f);

    shader_.bind();
    shader_.setUniform("m_model", model_);
    shader_.setUniform("m_view", view_);
    shader_.setUniform("m_proj", proj_);
}
#include <glad/glad.h>
#include <IRenderer.hpp>
#include <Shader.hpp>
#include "Renderer.hpp"

Renderer::Renderer(int width, int height)
        : xe::IRenderer(width, height), shader_(xe::Shader("basic_window")) {
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
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, mesh_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
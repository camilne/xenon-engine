#include <Shader.hpp>
#include <io.h>
#include <cstdio>
#include "Engine.hpp"

GLuint mesh;
xe::Shader* shader;

void render();

int main(int argc, char* argv[]) {
    xe::Engine engine;

    engine.createWindow(1280, 720, "My Basic Window");
    engine.attachRenderer(render);
    shader = new xe::Shader("basic_window");

    glGenBuffers(1, &mesh);
    const GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, mesh);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    engine.run();

    return 0;
}

void render() {
    shader->bind();

    glBindBuffer(GL_ARRAY_BUFFER, mesh);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
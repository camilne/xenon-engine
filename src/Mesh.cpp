#include <iostream>
#include "Mesh.hpp"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLushort>& indices) {
    glGenBuffers(1, &vertexBufferId_);
    std::vector<GLfloat> arrVertices(vertices.size() * sizeof(Vertex));
    unsigned int offset = 0;
    for(const Vertex& v : vertices) {
        arrVertices[offset++] = v.position.x;
        arrVertices[offset++] = v.position.y;
        arrVertices[offset++] = v.position.z;

        arrVertices[offset++] = v.textureCoordinate.x;
        arrVertices[offset++] = v.textureCoordinate.y;

        arrVertices[offset++] = v.normal.x;
        arrVertices[offset++] = v.normal.y;
        arrVertices[offset++] = v.normal.z;

        arrVertices[offset++] = v.color.x;
        arrVertices[offset++] = v.color.y;
        arrVertices[offset++] = v.color.z;
    }
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId_);
    glBufferData(GL_ARRAY_BUFFER, arrVertices.size() * sizeof(GLfloat), &arrVertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &elementBufferId_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferId_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);

    count_ = indices.size();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(Mesh&& mesh) {
    vertexBufferId_ = mesh.vertexBufferId_;
    elementBufferId_ = mesh.elementBufferId_;
    count_ = mesh.count_;

    mesh.vertexBufferId_ = 0;
    mesh.elementBufferId_ = 0;
}

Mesh&& Mesh::createTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
    std::vector<Vertex> vertices = {v1, v2, v3};
    std::vector<GLushort> indices = {0, 1, 2};
    return std::move(Mesh(vertices, indices));
}

void Mesh::render() const {
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId_);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(GLfloat)));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(5 * sizeof(GLfloat)));
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(8 * sizeof(GLfloat)));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferId_);

    glDrawElements(GL_TRIANGLES, count_, GL_UNSIGNED_SHORT, (void*)0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
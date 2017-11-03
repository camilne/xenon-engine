#ifndef XENON_MESH_HPP
#define XENON_MESH_HPP

#include <glad/glad.h>
#include <vector>
#include "Vertex.hpp"

class Mesh {
public:
    Mesh(std::vector<Vertex>& vertices, std::vector<GLushort>& indices);
    Mesh(Mesh&& mesh);

    void render() const;

    static Mesh&& createTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);
private:
    GLuint vertexBufferId_;
    GLuint elementBufferId_;
    GLsizei count_;
};

#endif //XENON_MESH_HPP

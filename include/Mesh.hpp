#ifndef XENON_MESH_HPP
#define XENON_MESH_HPP

#include <glad/glad.h>
#include <vector>
#include "Vertex.hpp"
#include "Texture.hpp"

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices, const std::vector<Texture>& textures = {});
    Mesh(Mesh&& mesh);

    void render() const;

    static Mesh&& createTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);
private:
    GLuint vertexBufferId_;
    GLuint elementBufferId_;
    GLsizei count_;
    std::vector<Texture> textures_;
};

#endif //XENON_MESH_HPP

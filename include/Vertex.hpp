#ifndef XENON_VERTEX_HPP
#define XENON_VERTEX_HPP

#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 position;
    glm::vec2 textureCoordinate;
    glm::vec3 normal;
    glm::vec3 color;
};

#endif //XENON_VERTEX_HPP

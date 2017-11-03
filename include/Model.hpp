#ifndef XENON_MODEL_HPP
#define XENON_MODEL_HPP

#include <glm/glm.hpp>
#include <string>
#include <Mesh.hpp>
#include <assimp/scene.h>

class Model {
public:
    explicit Model(const std::string& path);

    void render() const;
private:
    glm::mat4 modelMatrix_;
    std::vector<Mesh> meshes_;

    void processNode(aiNode* node, const aiScene* scene);
    Mesh&& processMesh(aiMesh* mesh, const aiScene* scene) const;
};

#endif //XENON_MODEL_HPP

#ifndef XENON_MODEL_HPP
#define XENON_MODEL_HPP

#include <glm/glm.hpp>
#include <string>
#include <Mesh.hpp>
#include <assimp/scene.h>
#include "Texture.hpp"

class Model {
public:
    explicit Model(const std::string& path);

    void render() const;
private:
    std::string directory_;
    glm::mat4 modelMatrix_;
    std::vector<Mesh> meshes_;

    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene) const;
    std::vector<Texture> loadMaterialTextures(const aiMaterial* mat, aiTextureType type) const;
};

#endif //XENON_MODEL_HPP

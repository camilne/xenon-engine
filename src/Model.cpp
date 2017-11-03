#include "Model.hpp"
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <iostream>

Model::Model(const std::string& path) {
    Assimp::Importer importer;
    const auto scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_JoinIdenticalVertices);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        // Logger::log(Logger::ERROR, "Assimp loading error: " + importer.GetErrorString());
        std::cout << "Assimp loading error: " << importer.GetErrorString() << std::endl;
        return;
    }

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene) {
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        auto mesh = scene->mMeshes[node->mMeshes[i]];
        meshes_.push_back(processMesh(mesh, scene));
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

Mesh&& Model::processMesh(aiMesh* mesh, const aiScene* scene) const {
    std::vector<Vertex> vertices;
    std::vector<GLushort> indices;
    //std::vector<Texture> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        vertex.position = {
                mesh->mVertices[i].x,
                mesh->mVertices[i].y,
                mesh->mVertices[i].z
        };

        vertex.normal = {
                mesh->mNormals[i].x,
                mesh->mNormals[i].y,
                mesh->mNormals[i].z
        };

        if(mesh->mTextureCoords[0]) {
            vertex.textureCoordinate = {
                    mesh->mTextureCoords[0][i].x,
                    mesh->mTextureCoords[0][i].y
            };
        } else {
            vertex.textureCoordinate = glm::vec2(0.0f, 0.0f);
        }

        vertices.push_back(vertex);
    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        auto face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.emplace_back(face.mIndices[j]);
        }
    }

    /*if (mesh->mMaterialIndex >= 0)
    {
        auto material = scene->mMaterials[mesh->mMaterialIndex];
        auto diffuseMaps = loadMaterialTextures(material,
                                                aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        auto specularMaps = loadMaterialTextures(material,
                                                 aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }*/

    return std::move(Mesh(vertices, indices));
}

void Model::render() const {
    for(const Mesh& mesh : meshes_) {
        mesh.render();
    }
}

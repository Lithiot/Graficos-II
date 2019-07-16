#pragma once

#include "Exports.h"
#include "Node.h"
#include "TextureLoader.h"
#include "Material.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <assimp/Importer.hpp> 
#include <assimp/scene.h>           
#include <assimp/postprocess.h>

using namespace std;

class ENGINE_API MeshComponent : public Component
{
private:
	Node* myNode;
	string modelPath;
	string texturePath;
	InfoBMP texture;
	Material* material;
	unsigned int programID;
	std::vector<float> vertices;
	std::vector<float> uvs;
	std::vector<unsigned int> facesIndex;

	unsigned int vertexBufferID;
	unsigned int uvBufferID;
	unsigned int IndexBufferID;
	unsigned int textureBufferID;

public:
	MeshComponent(Node* node, Renderer* rend);
	~MeshComponent();

	void Start() override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	void SetVertices(std::vector<float> vertices);
	void SetUVS(std::vector<float> uvs);
	void SetFaces(std::vector<unsigned int> faces);
	void SetTexture(string texturePath);

	void LoadMaterial();
};


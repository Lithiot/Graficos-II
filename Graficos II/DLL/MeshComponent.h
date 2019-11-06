#pragma once

#include "Component.h"
#include "Exports.h"
#include "TextureLoader.h"
#include "Material.h"
#include "Collider3D.h"
#include "Camera.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <assimp/Importer.hpp> 
#include <assimp/scene.h>           
#include <assimp/postprocess.h>

using namespace std;

class ENGINE_API MeshComponent : public Component
{
private:
	string modelPath;
	string texturePath;
	InfoBMP texture;
	Material* material;
	Camera* cam;
	unsigned int programID;
	std::vector<float> vertices;
	std::vector<float> uvs;
	std::vector<unsigned int> facesIndex;

	unsigned int vertexBufferID;
	unsigned int uvBufferID;
	unsigned int IndexBufferID;
	unsigned int textureBufferID;

public:
	MeshComponent(Renderer* rend, Camera* cam);
	~MeshComponent();

	Collider3D* collider3d;

	void Start() override;
	void Update() override;
	bool Draw() override;
	void Destroy() override;

	void SetVertices(std::vector<float> vertices);
	void SetUVS(std::vector<float> uvs);
	void SetFaces(std::vector<unsigned int> faces);
	void SetTexture(string texturePath);

	void LoadMaterial();
	void GenerateCollider(glm::vec3 colliderMin, glm::vec3 colliderMax);
	void UpdateCollider(vec3 _collider3d[CANT_COLLIDER_VERTEX]);
};


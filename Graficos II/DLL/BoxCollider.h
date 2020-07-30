#pragma once

#include "Component.h"

using namespace std;

class Material;

#define CANT_COLLIDER_VERTEX 8

class ENGINE_API BoxCollider :	public Component
{
private:
	glm::vec3 colliderVertex[CANT_COLLIDER_VERTEX];
	glm::vec3 originalCollider[CANT_COLLIDER_VERTEX];
	Material* material;
	
	unsigned int programID;
	unsigned int IndexBufferID;
	unsigned int vertexBufferID;
	int indexCount;

public:
	BoxCollider(Renderer* renderer);
	~BoxCollider();

	void Start() override;
	void Update() override;
	bool Draw() override;
	void Destroy() override;

	void SetVertex(glm::vec3 colliderMin, glm::vec3 colliderMax);
	glm::vec3 GetVertex(int index);
	glm::vec3 GetRawVertex(int index);
	void UpdateVertex(glm::vec3 _collider3d[CANT_COLLIDER_VERTEX]);
	void SetFaces();
	void SetMaterial();
	bool loaded;
};


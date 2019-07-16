#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TextureLoader.h"
#include "Exports.h"
#include "MeshImporter.h"
#include "../external/assimp/include/assimp/Importer.hpp"
#include "../external/assimp/include/assimp/postprocess.h"
#include "../external/assimp/include/assimp/scene.h"
#include "../external/glew-2.1.0/include/GL/glew.h"
#include "../external/glfw-3.2.1/include/GLFW/glfw3.h"
#include "../external/glm-0.9.9.0/glm/glm.hpp"
#include "../external/glm-0.9.9.0/glm/glm.hpp"
#include "Node.h"
#include "MeshComponent.h"

using namespace std;
using namespace Assimp;

class ENGINE_API MeshLoader
{
private:
	MeshLoader();
	static MeshLoader *instance;
	void GenerateHierarchy(const aiScene* scene, Node* baseNode, aiNode* root, const string& texturePath, Renderer* rend, Camera* cam);
	void InitMesh(const aiMesh* mesh, MeshComponent* meshComponent, Renderer* rend);
	void GenerateCollider(Node* baseNode);
	vec3 colliderMin;
	vec3 colliderMax;

public:
	Node* LoadMesh(const string& modelPath, const string& texturePath, Renderer* rend, Camera* cam);


	static MeshLoader* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new MeshLoader();
		}
		return instance;
	}
};

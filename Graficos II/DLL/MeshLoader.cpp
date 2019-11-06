#include "MeshLoader.h"

MeshLoader* MeshLoader::instance = NULL;

MeshLoader::MeshLoader()
{
}

Node* MeshLoader::LoadMesh(const string& modelPath, const string& texturePath, Renderer* rend, Camera* cam)
{
	colliderMin = glm::vec3(1, 1, 1);
	colliderMax = glm::vec3(-1, -1, -1);

	Importer importer;
	const aiScene* scene = importer.ReadFile(modelPath, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);
	
	if (!scene || !scene->HasMeshes())
	{
		return nullptr;
	}

	Node* baseNode = new Node("baseNode", rend);
	GenerateHierarchy(scene, baseNode, scene->mRootNode, texturePath, rend, cam);

	return baseNode;

}

void MeshLoader::GenerateHierarchy(const aiScene* scene, Node* baseNode, aiNode* root, const string& texturePath, Renderer* rend, Camera* cam)
{
	for (int i = 0; i < root->mNumChildren; i++)
	{
		Node* childNode = new Node(root->mChildren[i]->mName.C_Str(), rend);
		baseNode->AddChild(childNode);
		if (root->mChildren[i]->mNumMeshes > 0)
		{
			MeshComponent* meshComponent = new MeshComponent(rend, cam);
			childNode->AddComponent(meshComponent);
			unsigned int index = root->mChildren[i]->mMeshes[0];
			InitMesh(scene->mMeshes[index], meshComponent, rend);
			meshComponent->GenerateCollider(colliderMin, colliderMax);
			meshComponent->SetTexture(texturePath);
			meshComponent->LoadMaterial();
			if (root->mChildren[i]->mNumChildren > 0)
			{
				GenerateHierarchy(scene, childNode, root->mChildren[i], texturePath, rend, cam);
			}
		}
	}
}

void MeshLoader::InitMesh(const aiMesh* mesh, MeshComponent* meshComponent, Renderer* rend)
{
	std::vector<float> vertices;
	std::vector<float> uvs;
	std::vector<unsigned int> facesIndexes;

	colliderMin = glm::vec3(99999, 99999, 99999);
	colliderMax = glm::vec3(-99999, -99999, -99999);

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		aiVector3D pos = mesh->mVertices[i];
		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);

		if (pos.x < colliderMin.x)
			colliderMin.x = pos.x;
		if (pos.x > colliderMax.x)
			colliderMax.x = pos.x;
		if (pos.y < colliderMin.y)
			colliderMin.y = pos.y;
		if (pos.y > colliderMax.y)
			colliderMax.y = pos.y;
		if (pos.z < colliderMin.z)
			colliderMin.z = pos.z;
		if (pos.z > colliderMax.z)
			colliderMax.z = pos.z;

		aiVector3D uv = mesh->mTextureCoords[0][i];
		uvs.push_back(uv.x);
		uvs.push_back(uv.y);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		facesIndexes.push_back(mesh->mFaces[i].mIndices[0]);
		facesIndexes.push_back(mesh->mFaces[i].mIndices[1]);
		facesIndexes.push_back(mesh->mFaces[i].mIndices[2]);
	}
	
	meshComponent->SetVertices(vertices);
	meshComponent->SetUVS(uvs);
	meshComponent->SetFaces(facesIndexes);
}
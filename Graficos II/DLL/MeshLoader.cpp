#include "MeshLoader.h"

MeshLoader* MeshLoader::instance = NULL;

MeshLoader::MeshLoader()
{
}

void MeshLoader::LoadMesh(const string& modelPath, const string& texturePath, vector<MeshEntry>& meshEntries, vector<InfoBMP>& meshTexture, Renderer* rend)
{
	Importer importer;
	const aiScene* pScene = importer.ReadFile(modelPath.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);
	if (pScene)
	{
		InitFromScene(pScene, texturePath, meshEntries, meshTexture, rend);
	}
	else
	{
		printf("Error parsing '%s': '%s'\n", modelPath.c_str(), importer.GetErrorString());
	}
}

void MeshLoader::InitFromScene(const aiScene* scene, const string& texturePath, vector<MeshEntry>& meshEntries, vector<InfoBMP>& meshTexture, Renderer* rend)
{
	meshEntries.resize(scene->mNumMeshes);
	meshTexture.resize(scene->mNumMaterials);

	for (int i = 0; i < meshEntries.size(); i++)
	{
		const aiMesh* aiMesh = scene->mMeshes[i];
		InitMesh(i, aiMesh, meshEntries, rend);
	}

	for (int i = 0; i < scene->mNumMaterials; i++)
	{
		meshTexture[i] = TextureLoader::LoadBMP(texturePath.c_str());
	}
}

void MeshLoader::InitMesh(unsigned int index, const aiMesh* paiMesh, vector<MeshEntry>& meshEntries , Renderer* rend)
{

	vector<Vertex> Vertices;
	vector<unsigned int> Indices;

	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < paiMesh->mNumVertices; i++)
	{
		const aiVector3D* pos = &(paiMesh->mVertices[i]);
		const aiVector3D* normal = &(paiMesh->mNormals[i]);
		const aiVector3D* texCoord = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTextureCoords[0][i]) : &Zero3D;

		Vertex v(vec3(pos->x, (float)pos->y, (float)pos->z), vec2((float)texCoord->x, (float)texCoord->y), vec3((float)normal->x, (float)normal->y, (float)normal->z));

		Vertices.push_back(v);
	}

	for (int i = 0; i < paiMesh->mNumFaces; i++)
	{
		const aiFace& Face = paiMesh->mFaces[i];
		assert(Face.mNumIndices == 3);
		Indices.push_back(Face.mIndices[0]);
		Indices.push_back(Face.mIndices[1]);
		Indices.push_back(Face.mIndices[2]);
	}

	meshEntries[index].Init(Vertices, Indices, rend);
}
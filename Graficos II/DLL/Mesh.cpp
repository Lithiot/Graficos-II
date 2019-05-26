#include "Mesh.h"
#pragma warning(disable:4996)

Mesh::Mesh(string modelPath, string _texturePath, Renderer* rend) : Shape(rend)
{
	this->texturePath = new char[_texturePath.size() + 1];
	_texturePath.copy(this->texturePath, _texturePath.size() + 1);
	this->texturePath[_texturePath.size()] = '\0';

	MeshLoader::GetInstance()->LoadMesh(modelPath, _texturePath, meshEntries, meshTextures, rend);

	for (int i = 0; i < meshTextures.size(); i++)
	{
		buffersTextureID.push_back(rend->GenTextureBuffer(meshTextures[i].width, meshTextures[i].height, meshTextures[i].data));
	}
}
Mesh::~Mesh()
{
}

void Mesh::Update()
{
	Entity::UpdateModel();
}

void Mesh::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModel(model);
	if (material != NULL) 
	{
		material->Bind();
		material->SetMatrixProperty("MVP", renderer->GetMVP());
		material->BindTexture("myTextureSampler", buffersTextureID[0]);
	}
	renderer->EnableAtribArray(0);
	renderer->EnableAtribArray(1);
	for (int i = 0; i < meshEntries.size(); i++) 
	{
		renderer->BindBuffer(meshEntries[i].vertexBuffer, 0);
		renderer->BindTextureBuffer(meshEntries[i].uvBuffer, 1);
		renderer->BindMeshBuffer(meshEntries[i].indexBuffer);
		renderer->DrawIndexBuffer(meshEntries[i].cantIndex);
	}
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
}
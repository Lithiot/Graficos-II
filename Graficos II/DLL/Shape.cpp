#include "Shape.h"

Shape::Shape(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexUVTexture = NULL;
	vertexBufferID = -1;
	colorBufferID = -1;
	textureBufferId - 1;
}

Shape::~Shape()
{
}

void Shape::SetVertex(float* vertex, int cant)
{
	vertexBufferID = renderer->GenVertexBuffer(vertex, sizeof(float) * cant * 3);
}

void Shape::SetColors(float* vColor, int cant)
{
	colorBufferID = renderer->GenColorBuffer(vColor, sizeof(float) * cant * 3);
}

void Shape::SetTextures(float* vertex, int cant)
{
	textureBufferId = renderer->GenVertexBuffer(vertex, sizeof(float)* cant * 3);
}

void Shape::LoadTexture(const char* name)
{
	header = TextureLoader::LoadBMP(name);
	textureBufferId = renderer->GenTextureBuffer(header.width, header.height, header.data);
}

void Shape::SetMaterial(Material* mat)
{
	material = mat;
}

void Shape::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModel(model);

	if (material != NULL)
	{
		material->Bind();
		material->SetMatrixProperty("MVP", renderer->GetMVP());
	}

	renderer->EnableAtribArray(0);
	renderer->EnableAtribArray(1);
	renderer->BindBuffer(vertexBufferID, 0);
	renderer->BindBufferColor(colorBufferID, 1);
	renderer->Draw(type, cantVertex);
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
}
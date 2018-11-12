#include "Shape.h"

Shape::Shape(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexTexture = NULL;
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
	//textreVtxCount = count;
	//textureBufferId = render->GenTextureBuffer(vertex, sizeof(float)* cant * 3); 
}

void Shape::SetMaterial(Material* mat)
{
	material = mat;
}
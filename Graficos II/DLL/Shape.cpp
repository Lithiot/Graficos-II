#include "Shape.h"

Shape::Shape(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexUVTexture = NULL;
	vertexBufferID = -1;
	colorBufferID = -1;
	textureBufferId = - 1;
	textureUVBufferId = -1;
	shouldDispose = true;
}

Shape::~Shape()
{
}

void Shape::SetVertex(float* vertex, int cant)
{
	Dispose();
	shouldDispose = true;
	vertexBufferID = renderer->GenVertexBuffer(vertex, sizeof(float) * cant* 3);
}

void Shape::SetColors(float* vColor, int cant)
{
	colorBufferID = renderer->GenColorBuffer(vColor, sizeof(float) * cant * 3);
}

void Shape::SetMaterial(Material* mat)
{
	material = mat;
}

void Shape::Dispose() 
{
	if(shouldDispose)
	{
		renderer->DeleteBuffers(vertexBufferID);
		renderer->DeleteBuffers(colorBufferID);
		
		shouldDispose = false;
	}
}
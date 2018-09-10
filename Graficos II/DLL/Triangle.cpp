#include "Triangle.h"

Triangle::Triangle(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	bufferID = -1;
	cantVertex = 3;

	setVertex(vertexes, cantVertex);
}

Triangle::~Triangle()
{
}

void Triangle::setVertex(float* vertex, int cant)
{
	vertex = new float[9]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	bufferID = renderer->GenBuffer(vertex, sizeof(float) * cant * 3);
}

void Triangle::Draw() 
{
	renderer->Draw(bufferID, cantVertex);
}
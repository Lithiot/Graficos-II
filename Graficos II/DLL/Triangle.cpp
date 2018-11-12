#include "Triangle.h"

Triangle::Triangle(Renderer* rend) : Shape(rend)
{
	type = 't';
	cantVertex = 3;

	vertexes = new float[9]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	SetVertex(vertexes, cantVertex);
}

Triangle::~Triangle()
{
}
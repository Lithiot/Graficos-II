#include "Circle.h"

Circle::Circle(Renderer* rend) : Shape(rend)
{
	type = 'c';
	cantVertex = 20;
	float radius = 1;

	vertexes = new float[cantVertex * 3];
	glm::vec3 vec;
	float angle = 0.0f;
	float PI = 3.14f;
	float degrees = 360.0f / cantVertex;

	for (int i = 0; i < cantVertex * 3; i += 3)
	{
		vec = glm::vec3(cos(angle), sin(angle), 0) * radius;
		vertexes[i] = vec.x;
		vertexes[i + 1] = vec.y;
		vertexes[i + 2] = vec.z;
		angle += degrees * PI / 180.0f;
	}

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Circle::~Circle()
{
}
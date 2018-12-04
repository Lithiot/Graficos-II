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

	vertexColors = new float[cantVertex * 3]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
	};

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Circle::~Circle()
{
	delete[] vertexes;
	delete[] vertexColors;
}

void Circle::Draw()
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
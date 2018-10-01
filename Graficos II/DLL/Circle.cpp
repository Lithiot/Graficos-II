#include "Circle.h"

Circle::Circle(Renderer* rend) : Shape(rend)
{
	type = 'c';
	cantVertex = 8;
	int radius = 5;

	vertexes = new float[cantVertex * 3];
	vertexes[0] = 0.0f;
	vertexes[1] = 0.0f;
	vertexes[2] = 0.0f;
	float degrees = (cantVertex - 2.0f / 360.0f);
	float auxAngle = 0.0f;
	for (int i = 1; i < cantVertex; i += 3) 
	{
		vertexes[i] = cos(auxAngle) * radius;
		vertexes[i + 1] = sin(auxAngle) * radius;
		vertexes[i + 2] = 0.0f;
		auxAngle += degrees;
	}

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Circle::~Circle()
{
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
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

	vertexColors = new float[cantVertex * 3]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
	};

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Triangle::~Triangle()
{
	delete[] vertexes;
	delete[] vertexColors;
}

void Triangle::Draw()
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
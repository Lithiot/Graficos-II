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
	renderer->BindBuffer(vertexBufferID, 0);
	renderer->Draw(type, cantVertex);
	renderer->DisableBuffer(0);
}
#include "Triangle.h"

Triangle::Triangle(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	bufferID = -1;

	vertexes = new float[9]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	setVertex(vertexes, 3);
}

Triangle::~Triangle()
{
}

void Triangle::setVertex(float* vertex, int cant)
{
	cantVertex = cant;

	bufferID = renderer->GenBuffer(vertex, sizeof(float) * cant * 3);
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
	renderer->Draw(bufferID, cantVertex);
}

void Triangle::SetMaterial(Material* mat) 
{
	material = mat;
}
#include "Triangle.h"

Triangle::Triangle(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexBufferID = -1;
	colorBufferID = -1;
	cantVertex = 3;

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Triangle::~Triangle()
{
}

void Triangle::SetVertex(float* vertex, int cant)
{
	vertex = new float[9]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	vertexBufferID = renderer->GenVertexBuffer(vertex, sizeof(float) * cant * 3);
}

void Triangle::SetColors(float* vColor, int cant)
{
	vColor = new float[9]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
	};

	colorBufferID = renderer->GenColorBuffer(vColor, sizeof(float) * cant * 3);
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
	renderer->Draw(vertexBufferID, colorBufferID, cantVertex);
}

void Triangle::SetMaterial(Material* mat) 
{
	material = mat;
}
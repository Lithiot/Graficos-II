#include "Square.h"



Square::Square(Renderer* rend) : Entity(rend)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexBufferID = -1;
	colorBufferID = -1;
	cantVertex = 4;

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Square::~Square()
{
}

void Square::SetVertex(float* vertex, int cant)
{
	vertex = new float[12]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	vertexBufferID = renderer->GenVertexBuffer(vertex, sizeof(float) * cant * 3);
}

void Square::SetColors(float* vColor, int cant) 
{
	vColor = new float[12]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
	};

	colorBufferID = renderer->GenColorBuffer(vColor, sizeof(float) * cant * 3);
}

void Square::Draw()
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

void Square::SetMaterial(Material* mat)
{
	material = mat;
}
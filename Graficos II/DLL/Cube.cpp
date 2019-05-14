#include "Cube.h"

Cube::Cube(Renderer* rend) : Shape(rend)
{
	type = 'm';
	cantVertex = 8;

	vertexes = new float[8 * 3]
	{
		// Front
		-1.0f, -1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		
		// Back
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
	};
	SetVertex(vertexes, cantVertex);

	vertexColors = new float[8 * 3]
	{
		// front colors
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		 1.0, 1.0, 1.0,
		// back colors
		 1.0, 0.0, 0.0,
		 0.0, 1.0, 0.0,
		 0.0, 0.0, 1.0,
		1.0, 1.0, 1.0
	};
	SetColors(vertexColors, cantVertex);


	unsigned int indexes[36] = 
	{
		// Front
		0, 1, 2,
		0, 2, 3,
		// Back
		4, 5, 6,
		4, 6, 7,
		// Right
		1, 5, 6,
		1, 6, 2,
		// Left
		0, 4, 7,
		0, 7, 3,
		// Upper
		3, 2, 6,
		3, 6, 7,
		// Bottom
		0, 1, 5,
		0, 5, 4
	};
	SetIndexes(indexes, 36);
	
}

Cube::~Cube()
{
}

void Cube::SetIndexes(unsigned int* indexes, int count)
{
	unsigned int indexCount = count;
	IndexBufferId = (renderer->GenIndexBuffer(indexes, indexCount * sizeof(unsigned int)));
}

void Cube::Draw()
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
	renderer->BindIndexBuffer(IndexBufferId);
	renderer->Draw(type, 36); // cambiar para que sea 36 el valor
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
}

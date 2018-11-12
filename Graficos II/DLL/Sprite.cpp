#include "Sprite.h"

Sprite::Sprite(Renderer* rend) : Shape(rend)
{
	type = 's';
	cantVertex = 4;

	vertexes = new float[12]
	{
		-1.0f,-1.0f , 0.0f ,
		1.0f,-1.0f , 0.0f ,
		-1.0f, 1.0f , 0.0f ,
		1.0f, 1.0f , 0.0f
	};
	SetVertex(vertexes, 4);

	vertexUVTexture = new float[8]
	{
		0.0f,0.0f,
		0.0f,1.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};
	SetTextures(vertexUVTexture, cantVertex);
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
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
	renderer->BindTextureBuffer(colorBufferID, 1);
	renderer->Draw(type, cantVertex);
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
}
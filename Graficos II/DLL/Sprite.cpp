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
	
	vertexUVTexture = new float[8]
	{
		0.0f,0.0f,
		1.0f,0.0f,
		0.0f,1.0f,
		1.0f,1.0f 
	};

	SetVertex(vertexes, 4);
	SetTextures(vertexUVTexture, 4);
}

Sprite::~Sprite()
{
}

void Sprite::SetTextures(float* vertex, int cant)
{
	textureUVBufferId = renderer->GenVertexBuffer(vertex, sizeof(float)* cant * 2);
}

void Sprite::LoadTexture(const char* name)
{
	header = TextureLoader::LoadBMP(name);
	textureBufferId = renderer->GenTextureBuffer(header.width, header.height, header.data);
}

void Sprite::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModel(model);

	if (material != NULL)
	{
		material->Bind();
		material->SetMatrixProperty("MVP", renderer->GetMVP());
		material->BindTexture("myTextureSampler", textureBufferId);
	}
	
	renderer->EnableAtribArray(0);
	renderer->EnableAtribArray(1);
	renderer->BindBuffer(vertexBufferID, 0);
	renderer->BindTextureBuffer(textureUVBufferId, 1);
	renderer->Draw(type, cantVertex);
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
	
}
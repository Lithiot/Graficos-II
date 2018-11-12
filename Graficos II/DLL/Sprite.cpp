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
	SetVertices(vertexes, 4);

	vertexTexture = new float[8]
	{
		0.0f,0.0f,
		0.0f,1.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};

	SetTextureVertices(vertexTexture, 4);
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
	renderer->BindBufferColor(colorBufferID, 1);
	renderer->Draw(type, cantVertex);
	renderer->DisableBuffer(0);
	renderer->DisableBuffer(1);
}

/*
#include "Sprite.h"

Sprite::Sprite(Renderer* render, const char* name): Shape (render)
{
	header = Importer::LoadBMP(name);
	txtrevertex = NULL;
	textureBufferId - 1;

	vertex = new float[12]
	{
		-1.0f,-1.0f , 0.0f ,
		1.0f,-1.0f , 0.0f ,
		-1.0f, 1.0f , 0.0f ,
		1.0f, 1.0f , 0.0f
	};

	SetVertices(vertex, 4);

	txtrevertex = new float[8]
	{
		0.0f,0.0f,
		0.0f,1.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};
	SetTextureVertices(txtrevertex, 4);
}

Sprite::~Sprite()
{
	DisposeTexture();
}

void Sprite::SetTextureVertices(float* vertices, int count)
{
	textreVtxCount = count;
	shouldDisposeTexture = true;
	textureBufferId = render->GenTextureBuffer(header.width,header.height,header.data);
}

void Sprite::DisposeTexture()
{
	if (shouldDisposeTexture)
	{
		render->DestroyBuffer(textureBufferId);
		shouldDispose = false;
	}
}

void Sprite::Draw()
{
	DrawMesh(GL_TRIANGLE_STRIP);
}

void Sprite::DrawMesh(int drawType)
{
	render->LoadIdentityMatrix();
	render->SetWorldMatrix(WorldMatrix);

	if (material != NULL) 
	{
		material->Bind();
		material->SetMatrixProperty("WVP", render->GetWvp());
	}

	render->BeginDraw(0);
	render->BeginDraw(1);
	render->BindBuffer(bufferId, 0);
	render->BindTextureBuffer(textureBufferId, 1);
	render->DrawBuffer(textreVtxCount, drawType);
	render->EndDraw(0);
	render->EndDraw(1);
}
*/

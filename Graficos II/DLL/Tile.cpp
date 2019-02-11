#include "Tile.h"

Tile::Tile(Renderer* rend, int tileId, float width, float height) : Shape(rend), id(tileId), tileW(1/width), tileH(1/height)
{
	tilesInX = width;
	tilesInY = height;

	type = 's';
	cantVertex = 4;

	vertexes = new float[12]
	{
		-1.0f, 1.0f , 0.0f ,
		1.0f, 1.0f , 0.0f ,
		-1.0f, -1.0f , 0.0f ,
		1.0f, -1.0f , 0.0f
	};

	CalculateTile();

	SetVertex(vertexes, 4);
	SetTextures(vertexUVTexture, 4);
}

Tile::~Tile()
{
}

void Tile::SetTextures(float* vertex, int cant)
{
	textureUVBufferId = renderer->GenVertexBuffer(vertex, sizeof(float)* cant * 2);
}

void Tile::LoadTexture(const char* name)
{
	header = TextureLoader::LoadBMP(name);
	textureBufferId = renderer->GenTextureBuffer(header.width, header.height, header.data);
}

void Tile::Draw()
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

void Tile::CalculateTile() 
{
	vertexUVTexture = new float[8];
	
	vertexUVTexture[0] = 0.0f;
	vertexUVTexture[1] = 0.0f;
	vertexUVTexture[2] = tileW;
	vertexUVTexture[3] = 0.0f;
	vertexUVTexture[4] = 0.0f;
	vertexUVTexture[5] = -tileH;
	vertexUVTexture[6] = tileW;
	vertexUVTexture[7] = -tileH;

	int row = 0;
	int column = id;

	while (column >= tilesInX)
	{
		column -= tilesInX;
		row++;
	}

	if (id > 29)
		row += 2;

	if(id < 20 && id > 9)
		row -= 2;

	vertexUVTexture[0] += tileW * column;
	vertexUVTexture[1] += tileH * row;
	vertexUVTexture[2] += tileW * column;
	vertexUVTexture[3] += tileH * row;
	vertexUVTexture[4] += tileW * column;
	vertexUVTexture[5] += tileH * row;
	vertexUVTexture[6] += tileW * column;
	vertexUVTexture[7] += tileH * row;
	
}

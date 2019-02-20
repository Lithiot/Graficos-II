#include "Tilemap.h"

Tilemap::Tilemap(Renderer* rend, float width, float height, const char* filename, float cantTilesX, float cantTilesY)
	: Shape(rend), mapWidth(width), mapHeight(height), cantX(cantTilesX), cantY(cantTilesY)
{
	type = 'q';
	cantVertex = width * height * 4 * 3;
	cantUVvertex = width * height * 4 * 2;

	vertexes = new float[cantVertex];
	
	/*
	indexes = vector<vector<int>>(width, vector<int>(height));
	vertexArrayPos.clear();
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{

			int col = j * 2;
			int row = i * 2;

			vertexArrayPos.push_back(-10.0f + col);
			vertexArrayPos.push_back(10.0f - row);
			vertexArrayPos.push_back(0.0f);

			vertexArrayPos.push_back(-10.0f + col);
			vertexArrayPos.push_back(8.0f - row);
			vertexArrayPos.push_back(0.0f);

			vertexArrayPos.push_back(-8.0f + col);
			vertexArrayPos.push_back(8.0f - row);
			vertexArrayPos.push_back(0.0f);

			vertexArrayPos.push_back(-8.0f + col);
			vertexArrayPos.push_back(10.0f - row);
			vertexArrayPos.push_back(0.0f);
		}
	}
	float* p = &vertexArrayPos[0];
	
	for (int i = 0; i < vertexArrayPos.size(); i++)
	{
		cout << vertexArrayPos[i] << endl;
	}
	*/
	
	float tileW = 2.0f;
	float tileH = 2.0f;

	float screenH = rend->GetWindow()->GetHeight();
	float screenW = rend->GetWindow()->GetWidth();

	int column = 0;
	int row = 0;
	
	// Debug variables
	int j = 1;
	int b = 1;

	cout << "Creating tilemap Vertexes" << endl;
	for (int i = 0; i < cantVertex; i = i + 12)
	{
		// Coordenada 1
		vertexes[i] = -10.0f + tileW * column;
		vertexes[i + 1] = 10.0f - tileH * row;
		vertexes[i + 2] = 0.0f;

		// Coordenada 2
		vertexes[i + 3] = -10.0f + tileW * column;
		vertexes[i + 4] = (10.0f - tileH) - tileH * row;
		vertexes[i + 5] = 0.0f;
		
		// Coordenada 3
		vertexes[i + 6] = (-10.0f + tileW) + tileW * column;
		vertexes[i + 7] = (10.0f - tileH) - tileH * row;
		vertexes[i + 8] = 0.0f;

		// Coordenada 4
		vertexes[i + 9] = (-10.0f + tileW) + tileW * column;
		vertexes[i + 10] = 10.0f - tileH * row;
		vertexes[i + 11] = 0.0f;
		
		if (column >= width - 1)
		{
			column = 0;
			row++;
		}
		else
			column++;

		cout << "|========== Tile " << b << " ==========|" << endl;
		cout << "Vertex " << j << " = X: " << vertexes[i] << ", Y: " << vertexes[i + 1] << ", Z: " << vertexes[i + 2] << endl;
		j++;
		cout << "Vertex " << j << " = X: " << vertexes[i + 3] << ", Y: " << vertexes[i + 4] << ", Z: " << vertexes[i + 5] << endl;
		j++;
		cout << "Vertex " << j << " = X: " << vertexes[i + 6] << ", Y: " << vertexes[i + 7] << ", Z: " << vertexes[i + 8] << endl;
		j++;
		cout << "Vertex " << j << " = X: " << vertexes[i + 9] << ", Y: " << vertexes[i + 10] << ", Z: " << vertexes[i + 11] << endl;
		b++;
	}
	
	mapIds = new vector<int>();
	LoadMapIDs(filename);

	vertexUVTexture = new float[cantUVvertex];
	LoadUVs();

	SetTilemapVertex(vertexes, cantVertex);
	
	SetTextures(vertexUVTexture, cantUVvertex);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

Tilemap::~Tilemap()
{
}

void Tilemap::SetTextures(float* vertex, int cant)
{
	textureUVBufferId = renderer->GenVertexBuffer(vertex, sizeof(float)* cant);
}

void Tilemap::LoadTexture(const char* name)
{
	header = TextureLoader::LoadBMP(name);
	textureBufferId = renderer->GenTextureBuffer(header.width, header.height, header.data);
}

void Tilemap::Draw()
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

void Tilemap::LoadMapIDs(const char* file) 
{
	string buffer;
	ifstream tileFile(file);

	while (getline(tileFile, buffer, ','))
	{
		mapIds->push_back(stoi(buffer));
	}
}

void Tilemap::LoadUVs()
{
	float textureW = 1 / cantX;
	float textureH = 1 / cantY;

	int idIndex = 0;

	for (int i = 0; i < cantUVvertex; i = i + 8)
	{
		// Coordenada 1
		vertexUVTexture[i] = 0.0f;
		vertexUVTexture[i + 1] = 1.0f;

		// Coordenada 2
		vertexUVTexture[i + 2] = 0.0f;
		vertexUVTexture[i + 3] = 1.0f - textureH;

		// Coordenada 3
		vertexUVTexture[i + 4] = textureW;
		vertexUVTexture[i + 5] = 1.0f - textureH;

		// Coordenada 4
		vertexUVTexture[i + 6] = textureW;
		vertexUVTexture[i + 7] = 1.0f;
		
		int row = 0;
		int column = mapIds->at(idIndex);

		while (column >= cantX)
		{
			column -= cantX;
			row++;
		}

		// Coordenada 1
		vertexUVTexture[i] += textureW * column;
		vertexUVTexture[i + 1] -= textureH * row;

		// Coordenada 2
		vertexUVTexture[i + 2] += textureW * column;
		vertexUVTexture[i + 3] -= textureH * row;

		// Coordenada 3
		vertexUVTexture[i + 4] += textureW * column;
		vertexUVTexture[i + 5] -= textureH * row;

		// Coordenada 4
		vertexUVTexture[i + 6] += textureW * column;
		vertexUVTexture[i + 7] -= textureH * row;

		idIndex++;
	}
}

void Tilemap::SetTilemapVertex(float* vertex, int cant)
{
	vertexBufferID = renderer->GenVertexBuffer(vertex, sizeof(float) * cant);
}
#include "Tilemap.h"

Tilemap::Tilemap(Renderer* rend, const char* filename, float levelW, float levelH, Material* mat,
				 const char* texturefile, float maxTilesX, float maxTilesY)
	   : file(filename), mapIds(new vector<int>()), width(levelW), height(levelH), tilesMat(mat),
		 tilesX(maxTilesX), tilesY(maxTilesY), texture(texturefile)
{
	Loadfile();
	tiles = new vector<Tile*>();

	for (int i = 0; i < mapIds->size(); i++)
	{
		Tile* x = new Tile(rend, mapIds->at(i), tilesX, tilesY);
		x->SetMaterial(tilesMat);
		x->LoadTexture(texture);
		tiles->push_back(x);
	}
}

Tilemap::~Tilemap()
{
}

void Tilemap::Loadfile() 
{
	string buffer;
	ifstream tileFile(file);

	while (getline(tileFile, buffer, ','))
	{
		mapIds->push_back(stoi(buffer));
	}
}

void Tilemap::Drawtiles()
{
	// esquinas son
	// -9, 9		9, 9
	//
	// -9, -9		9, -9

	int x = -9;
	int y = 9;

	for (int i = 0; i < tiles->size(); i++)
	{
		tiles->at(i)->SetTranslation(x, y, 0);
		tiles->at(i)->Draw();

		x += 2;
		if (x >= 9) 
		{
			x = -9;
			y -= 2;
		}
	}
}
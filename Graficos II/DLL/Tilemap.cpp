#include "Tilemap.h"

Tilemap::Tilemap(Renderer* rend, const char* filename, float levelW, float levelH, Material* mat,
				 const char* texturefile, float maxTilesX, float maxTilesY)
	   : file(filename), mapIds(new vector<int>()), width(levelW), height(levelH), tilesMat(mat),
		 tilesX(maxTilesX), tilesY(maxTilesY), texture(texturefile), renderer(rend)
{
	Loadfile();
	collisionableIds = new vector<int>();
	tiles = new vector<Tile*>();

	LoadTiles();

}

Tilemap::~Tilemap()
{
}

void Tilemap::LoadTiles() 
{
	for (int i = 0; i < mapIds->size(); i++)
	{
		Tile* x = new Tile(renderer, mapIds->at(i), tilesX, tilesY);
		x->SetMaterial(tilesMat);
		x->LoadTexture(texture);
		tiles->push_back(x);
	}
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
		if (x > 10) 
		{
			x = -9;
			y -= 2;
		}
	}
}

void Tilemap::RegisterCollisionableIds(int id) 
{
	collisionableIds->push_back(id);

	for (int i = 0; i < tiles->size(); i++)
	{
		for (int j = 0; j < collisionableIds->size(); j++)
		{
			if (tiles->at(i)->GetId() == collisionableIds->at(j)) 
			{
				tiles->at(i)->SetCollider(2.0f, 2.0f, Tiles, true);
				CollisionManager::Instance()->RegisterEntity(tiles->at(i));
			}
		}
	}
}
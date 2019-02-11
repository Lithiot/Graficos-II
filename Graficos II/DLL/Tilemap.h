#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Tile.h"
#include "Exports.h"
using namespace std;
class ENGINE_API Tilemap
{
private:
	const char* file;
	vector<int>* mapIds;
	vector<Tile*>* tiles;
	Material* tilesMat;
	float height;
	float width;
	float tilesX;
	float tilesY;
	const char* texture;
public:
	Tilemap(Renderer* rend, const char* filename, float levelW, float levelH,
			Material* mat,const char* texturefile, float maxTilesX, float maxTilesY);
	~Tilemap();
	void Loadfile();
	void Drawtiles();
};


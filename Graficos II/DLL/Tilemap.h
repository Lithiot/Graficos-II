#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ENGINE_API Tilemap : public Shape
{
private:
	int mapWidth;
	int mapHeight;
	int cantUVvertex;
	float cantX;
	float cantY;
	vector<int>* mapIds;
public:
	Tilemap(Renderer* rend, float width, float height, const char* filename, float cantTilesX, float cantTilesY);
	~Tilemap();
	void Draw() override;
	void SetTextures(float* vertex, int cant);
	void LoadTexture(const char* name);
	void LoadUVs();
	void LoadMapIDs(const char* file);
};


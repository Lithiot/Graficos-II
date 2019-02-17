#pragma once
#include "Shape.h"
class ENGINE_API Tile : public Shape
{
private:
	int id;
	float tileW;
	float tileH;
	int tilesInX;
	int tilesInY;
public:
	Tile(Renderer* rend, int tileId, float width, float height);
	~Tile();
	void Draw() override;
	void SetTextures(float* vertex, int cant);
	void LoadTexture(const char* name);
	void CalculateTile();
	int GetId();
};


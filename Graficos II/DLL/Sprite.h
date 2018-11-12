#pragma once
#include "Shape.h"
#include "TextureLoader.h"
class Sprite : public Shape
{
private:
	InfoBMP header;
	const char* file;
	unsigned int textureBufferId;
	unsigned int textureVtxCount;
	unsigned int uvVertex;

public:
	Sprite(Renderer* rend);
	~Sprite();
	void Draw() override;
};


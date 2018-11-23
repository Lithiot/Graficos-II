#pragma once
#include "Shape.h"
class ENGINE_API Sprite : public Shape
{
private:
	const char* file;
	unsigned int textureBufferId;
	unsigned int textureVtxCount;
public:
	Sprite(Renderer* rend);
	~Sprite();
	void Draw() override;
};


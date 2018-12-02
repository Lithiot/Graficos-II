#pragma once
#include "Shape.h"
#include "Animacion.h"
class ENGINE_API Sprite : public Shape
{
private:
	const char* file;
	Animacion* animator;
	unsigned int textureBufferId;
	unsigned int textureVtxCount;
public:
	Sprite(Renderer* rend, float x, float y, int totalFrames);
	~Sprite();
	void Draw() override;
	void SetTextures(float* vertex, int cant);
	void LoadTexture(const char* name);
	void UpdateFrame();
};


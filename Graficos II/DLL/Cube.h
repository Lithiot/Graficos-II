#pragma once
#include "Exports.h"
#include "Shape.h"
class ENGINE_API Cube : public Shape
{
private:
	const char* file;
	unsigned int textureBufferId;
	unsigned int textureVtxCount;
	unsigned int IndexBufferId;
public:
	Cube(Renderer* rend);
	~Cube();
	void Draw() override;
	void SetIndexes(unsigned int* _indexes, int count);
};


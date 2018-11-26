#pragma once
#include "Exports.h"
#include "CollisionManager.h"
class ENGINE_API BoundingBox
{
protected:
	float heigth;
	float width;
	Layers layer;
public:
	BoundingBox(float w, float h, Layers lyr);
	~BoundingBox();
	Layers GetLayer();
	float GetHeigth();
	float GetWidth();
};


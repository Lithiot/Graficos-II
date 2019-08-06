#pragma once
#include "Shape.h"
class ENGINE_API Triangle : public Shape
{
public:
	Triangle (Renderer* rend);
	~Triangle ();
	void Draw() override;
};


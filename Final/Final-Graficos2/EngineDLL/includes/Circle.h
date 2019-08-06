#pragma once
#include "Shape.h"
class ENGINE_API Circle : public Shape
{
public:
	Circle(Renderer* rend);
	~Circle();
	void Draw() override;
};


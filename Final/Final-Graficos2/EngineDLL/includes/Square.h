#pragma once
#include "Shape.h"
#include "Material.h"
class ENGINE_API Square : public Shape
{
public:
	Square(Renderer* rend);
	~Square();
	void Draw() override;
};


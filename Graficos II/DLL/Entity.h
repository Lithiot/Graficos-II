#pragma once
#include "Renderer.h"
class ENGINE_API Entity
{
protected:
	Renderer* renderer;
public:
	virtual void Draw() = 0;

	Entity(Renderer* rend);
	~Entity();
};


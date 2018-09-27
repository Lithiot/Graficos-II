#pragma once
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>

class ENGINE_API Entity
{
protected:
	Renderer* renderer;
	glm::mat4 mvp;
public:
	virtual void Draw() = 0;

	Entity(Renderer* rend);
	~Entity();

	glm::mat4 GenerateMVP();
};


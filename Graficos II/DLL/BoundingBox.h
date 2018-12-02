#pragma once
#include "Exports.h"
#include "Layers.h"
#include "glm/gtc/matrix_transform.hpp"
class ENGINE_API BoundingBox
{
protected:
	float heigth;
	float width;
	Layers layer;
	bool isStatic;
	glm::vec3 pivot;
	glm::vec3 position;
public:
	BoundingBox(float w, float h, Layers lyr, bool staticState);
	~BoundingBox();
	Layers GetLayer();
	float GetHeigth();
	float GetWidth();
	bool GetIsStatic();
	void SetPosition(glm::vec3 pos);
	void SetPivot(glm::vec3 piv);
};


#include "BoundingBox.h"

BoundingBox::BoundingBox(float w, float h, Layers lyr, bool staticState, bool triggerState) : width(w), heigth(h), layer(lyr), isStatic(staticState), isTrigger(triggerState)
{
}

BoundingBox::~BoundingBox()
{
}

Layers BoundingBox::GetLayer() 
{
	return layer;
}

float BoundingBox::GetHeigth() 
{
	return heigth;
}

float BoundingBox::GetWidth() 
{
	return width;
}

bool BoundingBox::GetIsStatic() 
{
	return isStatic;
}

bool BoundingBox::GetIsTrigger()
{
	return isTrigger;
}

void BoundingBox::SetPosition(glm::vec3 pos) 
{
	position = pos;
}

void BoundingBox::SetPivot(glm::vec3 piv) 
{
	pivot = piv;
}
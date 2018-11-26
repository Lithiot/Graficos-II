#include "BoundingBox.h"

BoundingBox::BoundingBox(float w, float h, Layers lyr) : width(w), heigth(h), layer(lyr)
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
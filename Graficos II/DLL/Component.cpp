#include "Component.h"

Component::Component(Renderer* renderer) : rend(renderer)
{
}

Component::~Component()
{
}

void Component::Update() 
{
}

string Component::GetName() 
{
	return name;
}
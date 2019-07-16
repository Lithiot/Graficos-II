#include "Component.h"

Component::Component(Renderer* renderer, Type type) : rend(renderer), type(type)
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

Type Component::GetType() 
{
	return type;
}
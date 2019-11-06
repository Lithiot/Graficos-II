#include "Component.h"
#include "Node.h"

Component::Component(Renderer* renderer, Type type) : rend(renderer), type(type)
{
}

Component::~Component()
{
}

void Component::Update() 
{
}

bool Component::Draw() 
{
	return true;
}

string Component::GetName() 
{
	return name;
}

Type Component::GetType()
{
	return type;
}

Node* Component::GetOwner() 
{
	return owner;
}

void Component::SetOwner(Node* _owner) 
{
	owner = _owner;
}
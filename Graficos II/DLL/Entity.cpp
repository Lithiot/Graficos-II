#include "Entity.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

Entity::Entity(Renderer* rend) : renderer(rend), model(1.0f), 
								 translation(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f),
								 scale(1.0f, 1.0f, 1.0f), translationMatrix(1.0f),
								 rotationMatrix(1.0f), scaleMatrix(1.0f), collider(NULL), isActive(true)
{
}
Entity::~Entity()
{
	delete collider;
}
void Entity::SetTranslation(float x, float y, float z)
{
	translation[0] = x;
	translation[1] = y;
	translation[2] = z;

	translationMatrix = glm::translate(glm::mat4(1.0f), translation);
	if(collider)
		collider->SetPosition(translation);
	UpdateModel();
}
void Entity::SetRotationX(float x) 
{
	rotation[0] = x;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1, 0, 0));
	UpdateModel();
}
void Entity::SetRotationY(float y) 
{
	rotation[1] = y;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), y, glm::vec3(0, 1, 0));
	UpdateModel();
}
void Entity::SetRotationZ(float z) 
{
	rotation[2] = z;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), z, glm::vec3(0, 0, 1));
	UpdateModel();
}
void Entity::SetScale(float x, float y, float z) 
{
	scale[0] = x;
	scale[1] = y;
	scale[2] = z;

	scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
	UpdateModel();
}
void Entity::UpdateModel()
{
	model = translationMatrix * rotationMatrix * scaleMatrix;
}
glm::vec3 Entity::GetTranslation()
{
	return translation;
}
float Entity::GetPosX() 
{
	return translation[0];
}
float Entity::GetPosY() 
{
	return translation[1];
}
float Entity::GetPosZ() 
{
	return translation[2];
}
float Entity::GetRotationX() 
{
	return rotation[0];
}
float Entity::GetRotationY() 
{
	return rotation[1];
}
float Entity::GetRotationZ() 
{
	return rotation[2];
}
glm::vec3 Entity::GetScale() 
{
	return scale;
}
int Entity::GetLayer() 
{
	return collider->GetLayer();
}
BoundingBox* Entity::GetCollider() 
{
	return collider;
}
bool Entity::GetIsActive()
{
	return isActive;
}
void Entity::SetIsActive(bool state) 
{
	isActive = state;
}

void Entity::SetCollider(float width, float height, Layers layer, bool staticState, bool triggerState) 
{
	collider = new BoundingBox(width, height, layer, staticState, triggerState);
	collider->SetPosition(translation);
}

void Entity::AddEvent(int key, int value, int* valueToChange)
{
	EventManager::Instance()->AddNewEvent(key, value, valueToChange);
	eventKeys.push_back(key);
}

void Entity::AddEvent(int key, float value, float* valueToChange)
{
	EventManager::Instance()->AddNewEvent(key, value, valueToChange);
	eventKeys.push_back(key);
}

void Entity::AddEvent(int key, bool value, bool* valueToChange)
{
	EventManager::Instance()->AddNewEvent(key, value, valueToChange);
	eventKeys.push_back(key);
}

void Entity::fireEvents() 
{
	for (int i = 0; i < eventKeys.size(); i++)
	{
		EventManager::Instance()->ExecuteEvent(eventKeys.at(i));
	}
}
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
	for (int i = 0; i < (int)Layers::Count; i++)
	{
		registeredEntities.push_back(new list<Entity*>());
	}
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::RegisterEntity(Entity* entity)
{
	registeredEntities[entity->GetLayer()]->push_back(entity);
}

void CollisionManager::CheckCollisions()
{
	for (int i = 0; i < registeredEntities.size; i++)
	{
		for (int j = i + 1; j < registeredEntities.size; j++)
		{
			CollisionResolver(i, j);
		}
	}
}

void CollisionManager::CollisionResolver(int i, int j)
{
	for (list<Entity*>::iterator iter = registeredEntities[i]->begin(); iter != registeredEntities[i]->end(); iter++) 
	{
		
	}
}

void CollisionManager::ResolveCollision(Entity* A, Entity* B)
{
	
}
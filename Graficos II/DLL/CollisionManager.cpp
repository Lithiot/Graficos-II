#include "CollisionManager.h"
#include <list>

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager()
{
	for (int i = 0; i < (int)Layers::Count; i++)
	{
		registeredEntities.push_back(new list<Entity*>());
	}
}

CollisionManager::~CollisionManager()
{
	registeredEntities.clear();
}

void CollisionManager::RegisterEntity(Entity* entity)
{
	registeredEntities[entity->GetLayer()]->push_back(entity);
}

void CollisionManager::CheckCollisions()
{
	for (int i = 0; i < registeredEntities.size(); i++)
	{
		for (int j = i + 1; j < registeredEntities.size(); j++)
		{
			CollisionResolver(i, j);
		}
	}
}

void CollisionManager::CollisionResolver(int i, int j)
{
	for (list<Entity*>::iterator iter1 = registeredEntities[i]->begin(); iter1 != registeredEntities[i]->end(); iter1++)
	{
		for (list<Entity*>::iterator iter2 = registeredEntities[j]->begin(); iter2 != registeredEntities[j]->end(); iter2++)
		{
			ResolveCollision(*iter1, *iter2);
		}
	}
}

void CollisionManager::ResolveCollision(Entity* A, Entity* B)
{
	if (A->GetIsActive() == false)
		return;
	if (B->GetIsActive() == false)
		return;

	glm::vec3 dist = (A->GetTranslation() - B->GetTranslation());
	glm::vec3 module = abs(dist);

	float totalWidth = (A->GetCollider()->GetWidth() + B->GetCollider()->GetWidth()) / 2;
	float totalHeigth = (A->GetCollider()->GetHeigth() + B->GetCollider()->GetHeigth()) / 2;

	if (module.x < totalWidth && module.y < totalHeigth) 
	{
		float penetrationX = totalWidth - module.x;
		float penetrationY = totalHeigth - module.y;

		if (A->GetCollider()->GetIsTrigger())
			A->fireEvents();
		if (B->GetCollider()->GetIsTrigger())
			B->fireEvents();

		if (penetrationX > penetrationY)
		{
			if (A->GetCollider()->GetIsStatic()) 
			{
				if (B->GetPosY() < A->GetPosY())
					B->SetTranslation(B->GetPosX(), B->GetPosY() - penetrationY, B->GetPosZ());
				else
					B->SetTranslation(B->GetPosX(), B->GetPosY() + penetrationY, B->GetPosZ());
			}
			else if (B->GetCollider()->GetIsStatic()) 
			{
				if (A->GetPosY() < B->GetPosY())
					A->SetTranslation(A->GetPosX(), A->GetPosY() - penetrationY, A->GetPosZ());
				else
					A->SetTranslation(A->GetPosX(), A->GetPosY() + penetrationY, A->GetPosZ());
			}
			else
			{
				if (B->GetPosY() < A->GetPosY())
				{
					A->SetTranslation(A->GetPosX(), A->GetPosY() + (penetrationY / 2), A->GetPosZ());
					B->SetTranslation(B->GetPosX(), B->GetPosY() - (penetrationY / 2), B->GetPosZ());
				}
				else
				{
					A->SetTranslation(A->GetPosX(), A->GetPosY() - (penetrationY / 2), A->GetPosZ());
					B->SetTranslation(B->GetPosX(), B->GetPosY() + (penetrationY / 2), B->GetPosZ());
				}
			}
		}
		else if (penetrationX < penetrationY) 
		{
			if (A->GetCollider()->GetIsStatic()) 
			{
				if (B->GetPosX() < A->GetPosX())
					B->SetTranslation(B->GetPosX() - penetrationX, B->GetPosY(), B->GetPosZ());
				else
					B->SetTranslation(B->GetPosX() + penetrationX, B->GetPosY(), B->GetPosZ());
			}
			else if (B->GetCollider()->GetIsStatic()) 
			{
				if (A->GetPosX() < B->GetPosX())
					A->SetTranslation(A->GetPosX() - penetrationX, A->GetPosY(), A->GetPosZ());
				else				  
					A->SetTranslation(A->GetPosX() + penetrationX, A->GetPosY(), A->GetPosZ());
			}
			else
			{
				if (B->GetPosX() < A->GetPosX())
				{
					A->SetTranslation(A->GetPosX() + (penetrationX / 2), A->GetPosY(), A->GetPosZ());
					B->SetTranslation(B->GetPosX() - (penetrationX / 2), B->GetPosY() , B->GetPosZ());
				}
				else
				{
					A->SetTranslation(A->GetPosX() - (penetrationX / 2), A->GetPosY(), A->GetPosZ());
					B->SetTranslation(B->GetPosX() + (penetrationX / 2), B->GetPosY() , B->GetPosZ());
				}
			}
		}
	}
}

void CollisionManager::DestroyInstance() 
{
	delete instance;
}
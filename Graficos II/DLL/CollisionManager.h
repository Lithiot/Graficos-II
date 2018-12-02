#pragma once
#include "Exports.h"
#include "Entity.h"
#include "Layers.h"
#include <list>
#include <vector>

using namespace std;

class ENGINE_API CollisionManager
{
private:
	static CollisionManager* instance;
	vector<list<Entity*>*> registeredEntities;
public:
	CollisionManager();
	~CollisionManager();
	void RegisterEntity(Entity* entity);
	void CheckCollisions();
	void ResolveCollision(Entity* A, Entity* B);
	void CollisionResolver(int i, int j);

	static CollisionManager* Instance()
	{
		if (instance == NULL)
		{
			instance = new CollisionManager();
		}
		return instance;
	}
};


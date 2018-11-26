#pragma once
#include "Exports.h"
#include "Entity.h"
#include <vector>
#include <list>
#include <iterator>

using namespace std;

enum Layers
{
	player,	Enemy, Count
};

class ENGINE_API CollisionManager
{
private:
	vector<list<Entity*>*> registeredEntities;
public:
	CollisionManager();
	~CollisionManager();
	void RegisterEntity(Entity* entity);
	void CheckCollisions();
	void ResolveCollision(Entity* A, Entity* B);
	void CollisionResolver(int i, int j);
};


#pragma once
#include <iostream>
#include <Sprite.h>
#include <InputManager.h>
#include <CollisionManager.h>

class Tilemap;

class Player
{
private:
	Sprite* sprite;
	Material* mat;
	unsigned int programID;
	float vel;
	bool isActive;
public:
	Player(Renderer* rend, const char* file, float cantSpritesX, float cantSpritesY, int cantSpritesTotal);
	~Player();

	bool Update(Tilemap* tilemap);
	void Draw();
	void ToggleActive();

	void SetPosition(float x, float y, float z);
	glm::vec3 GetPosition();
};


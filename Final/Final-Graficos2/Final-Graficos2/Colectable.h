#pragma once
#include <iostream>
#include <Sprite.h>
#include <CollisionManager.h>

class Colectable
{
private:
	Sprite* sprite;
	Material* mat;
	unsigned int programID;
	bool isActive;
public:
	Colectable(Renderer* rend, const char* file, float cantSpritesX, float cantSpritesY, int cantSpritesTotal, bool isStatic, bool isTrigger);
	~Colectable();

	void Update();
	void Draw();

	void SetPosition(float x, float y, float z);
	glm::vec3 GetPosition();

	void createPickUpEvent(int key);
};


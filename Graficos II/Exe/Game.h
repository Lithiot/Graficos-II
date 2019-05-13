#pragma once
#include <GameBase.h>
#include <CollisionManager.h>
#include <TextureLoader.h>
#include <Triangle.h>
#include <Square.h>
#include <Circle.h>
#include <Sprite.h>
#include <DeltaTime.h>
#include <Camera.h>
#include <Cube.h>
class Game : public GameBase
{
private:
	Triangle* triangle1;
	Square* square1;
	Circle* circle1;
	Sprite* sprite1;
	Sprite* sprite2;
	Sprite* sprite3;
	Material* mat1;
	Material* mat2;
	Material* mat3;
	Material* mat4;
	Material* mat5;
	Camera* cam;
	Cube* cube1;
	unsigned int programID;
	float vel;
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
	bool OnDraw() override;
};






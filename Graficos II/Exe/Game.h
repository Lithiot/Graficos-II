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
#include <Mesh.h>

class Game : public GameBase
{
private:
	Material* mat1;
	Material* mat2;
	Camera* cam;
	Mesh* mesh1;
	Mesh* mesh2;
	Cube* cube;
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






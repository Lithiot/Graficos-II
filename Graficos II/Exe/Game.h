#pragma once
#include <GameBase.h>
#include <CollisionManager.h>
#include <TextureLoader.h>
#include <Triangle.h>
#include <Square.h>
#include <Circle.h>
#include <Sprite.h>
#include <Tilemap.h>
#include <DeltaTime.h>
#include <InputManager.h>
class Game : public GameBase
{
private:
	Sprite* sprite3;
	Sprite* sprite2;
	Material* mat3;
	Material* tileMat;
	Tilemap* tileMap;
	unsigned int programID;
	float vel;
	bool sprite2ActiveState;
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
	bool OnDraw() override;
};






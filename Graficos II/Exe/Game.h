#pragma once
#include <GameBase.h>
#include <CollisionManager.h>
#include <TextureLoader.h>
#include <DeltaTime.h>
#include <Camera.h>
#include <InputManager.h>
#include <MeshLoader.h>

class Game : public GameBase
{
private:
	Camera* cam;
	Node* nodeForCamera;
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






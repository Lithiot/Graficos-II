#pragma once
#include <GameBase.h>
#include <Tilemap.h>
#include <DeltaTime.h>
#include "Player.h"
#include "Colectable.h"

#define CANT_COLECTABLES 5

class Game : public GameBase
{
private:
	Player* player;
	vector<Colectable*> colectables;
	Material* tileMat;
	Tilemap* tileMap;
	Sprite* youWin;
	Sprite* youLose;
	Sprite* endTrigger;
	Material* mat;
	bool gameOver;
	bool win;
	bool lose;
	unsigned int programID;
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
	bool OnDraw() override;
};


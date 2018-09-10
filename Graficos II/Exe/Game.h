#pragma once
#include <GameBase.h>
#include <Triangle.h>
class Game : public GameBase
{
private:
	Triangle* triangle1;
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
	bool OnDraw() override;
};






#pragma once
#include <GameBase.h>
class Game : public GameBase
{
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
};


#pragma once
#include <GameBase.h>
#include <Triangle.h>
#include <Square.h>
class Game : public GameBase
{
private:
	Triangle* triangle1;
	Square* square1;
	Material* mat1;
	unsigned int programID;
public:
	Game();
	~Game();
	bool OnStart() override;
	bool OnStop() override;
	bool OnLoop() override;
	bool OnDraw() override;
};






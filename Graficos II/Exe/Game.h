#pragma once
#include <GameBase.h>
#include <Triangle.h>
#include <Square.h>
#include <Circle.h>
class Game : public GameBase
{
private:
	Triangle* triangle1;
	Square* square1;
	Circle* circle1;
	Material* mat1;
	Material* mat2;
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






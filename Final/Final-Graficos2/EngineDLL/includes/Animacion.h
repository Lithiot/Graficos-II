#pragma once
#include "Exports.h"
#include "DeltaTime.h"
class ENGINE_API Animacion
{
private:
	int actualFrame;
	int frameTotal;
	float timer;
	float cantY;
	float cantX;
	float row;
	float column;
	float frameWidth;
	float frameHeight;
	float* frame;
public:
	Animacion(float x, float y, int totalframes);
	~Animacion();
	void SetActualFrame(int frame);
	int GetActualFrame();
	float* CalculateFrame();
};


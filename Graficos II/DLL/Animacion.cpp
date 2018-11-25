#include "Animacion.h"

Animacion::Animacion(float x, float y, int totalframes) : cantX(x), cantY(y), actualFrame(0), frame(new float[8]), frameTotal(totalframes)
{
	frameWidth = 1 / cantX;
	frameHeight = 1 / cantY;
}

Animacion::~Animacion()
{
}

void Animacion::SetActualFrame(int frame)
{
	actualFrame = frame;
}

int Animacion::GetActualFrame()
{
	return actualFrame;
}

float* Animacion::CalculateFrame()
{
	if (timer >= 15)
	{
		frame[0] = 0.0f;
		frame[1] = 0.0f;

		frame[2] = frameWidth;
		frame[3] = 0.0f;

		frame[4] = 0.0f;
		frame[5] = frameHeight;

		frame[6] = frameWidth;
		frame[7] = frameHeight;

		for (int i = 0; i < actualFrame; i++)
		{
			frame[0] += frameWidth;
			frame[2] += frameWidth;
			frame[4] += frameWidth;
			frame[6] += frameWidth;
		}
		actualFrame++;

		if (actualFrame > frameTotal)
			actualFrame = 0;

		timer = 0;
	}
	else
	{
		timer += 1;
	}

	return frame;
}
#pragma once
#include "Exports.h"
#include <GLFW\glfw3.h>
#include <iostream>
class ENGINE_API DeltaTime
{
private:
	static DeltaTime* instance;
	double lastTime;
	double currentTime;
	double deltaTime;
public:
	DeltaTime();
	~DeltaTime();
	double GetDeltaTime();
	void SetLastTime(double time);
	void SetCurrentTime(double time);
	double CalculateDeltaTime();
	void Update();

	static DeltaTime* Instance()
	{
		if (instance == NULL)
		{
			instance = new DeltaTime();
		}
		return instance;
	}
};


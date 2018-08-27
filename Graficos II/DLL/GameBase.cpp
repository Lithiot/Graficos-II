#include "GameBase.h"

GameBase::GameBase() :wind(new Window()), rend(new Renderer()), quit(false)
{
}

GameBase::~GameBase()
{
}

bool GameBase::Start()
{
	if (!wind->Start(800, 600, "Prueva"))
		return false;
	if (!rend->Start())
		return false;
	return OnStart();
}

bool GameBase::Stop()
{
	OnStop();
	rend->Stop();
	wind->Stop();
	return true;
}

void GameBase::loop() 
{
	do
	{
		quit = OnLoop();
		wind->PollEvents();
	} while (!wind->ShouldClose && quit);
}
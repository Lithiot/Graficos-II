#include "GameBase.h"

GameBase::GameBase() :rend(new Renderer()), quit(false)
{
}

GameBase::~GameBase()
{
}

bool GameBase::Start()
{
	if (!rend->Start())
		return false;
	return OnStart();
}

bool GameBase::Stop()
{
	OnStop();
	rend->Stop();
	return true;
}

void GameBase::loop() 
{
	do
	{
		quit = OnLoop();
	} while (!quit);
}
#pragma once
#include "Exports.h"
#include "Renderer.h"
class ENGINE_API GameBase
{
private:
	int quit;
	Renderer* rend;
protected:
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0;
	virtual bool OnLoop() = 0;
public:
	GameBase();
	~GameBase();
	bool Start();
	bool Stop();
	void loop();
};
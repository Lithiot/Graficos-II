#pragma once
#include "Exports.h"
#include "Renderer.h"
//#include "Window.h"
#include "Node.h"

class ENGINE_API GameBase
{
private:
	int quit;
	Window* wind;
protected:
	virtual bool OnStart() = 0;
	virtual bool OnStop() = 0;
	virtual bool OnLoop() = 0;
	virtual bool OnDraw() = 0;
	Renderer* rend;
	Node* sceneNode;

public:
	GameBase();
	~GameBase();
	bool Start();
	bool Stop();
	void loop();
	void PrintNodeChilds(Node* node, int offset);

	Window* GetWindow();
};
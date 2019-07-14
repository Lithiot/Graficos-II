#pragma once
#include <string>
#include "Exports.h"
#include "Renderer.h"

using namespace std;

class ENGINE_API Component
{
private:
	string name;

protected:
	Renderer* rend;

public:
	Component(Renderer* renderer);
	~Component();

	virtual void Start() = 0;
	virtual void Destroy() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;

	string GetName();
};


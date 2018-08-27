#pragma once
#include "Exports.h"
#include <iostream>
#include "Window.h"

class ENGINE_API Renderer
{
public:
	Renderer();
	~Renderer();
	bool Start(Window* window);
	bool Stop();
	void SetClearColor();
	void SwapBuffer();
	void ClearWindow();
};


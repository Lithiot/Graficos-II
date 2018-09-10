#pragma once
#include "Exports.h"
#include <iostream>
#include "Window.h"

class ENGINE_API Renderer
{
private:
	Window* _window;

	void* VertexArrayID;
public:
	Renderer();
	~Renderer();
	bool Start(Window* window);
	bool Stop();
	void SetClearColor(float r, float g, float b, float a);
	void SwapBuffer();
	void ClearWindow();
	unsigned int GenBuffer(float* buffer, int size);
	void Draw(unsigned int vtxbuffer, int size);
};


#pragma once
#include "Exports.h"
#include <iostream>
class ENGINE_API Window
{
private:
	void* window;
	int _width;
	int _height;
	const char* _name;
public:
	Window();
	~Window();
	bool Start(int width, int height, const char* name);
	bool Stop();
	void* GetWindowPtr();
	bool ShouldClose();
	void PollEvents();
	int GetWidth();
	int GetHeight();
	const char* GetName();
};
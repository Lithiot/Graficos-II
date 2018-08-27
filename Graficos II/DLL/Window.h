#pragma once
#include "Exports.h"
#include <iostream>
class ENGINE_API Window
{
private:
	void* window;
public:
	Window();
	~Window();
	bool Start(int width, int height, const char* name);
	bool Stop();
	void* GetWindowPtr();
	bool ShouldClose();
	void PollEvents();
};
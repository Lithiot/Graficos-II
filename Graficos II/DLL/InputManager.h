#pragma once
#include "Exports.h"
#include "Window.h"

enum Key
{
	RightKey = 262,
	LeftKey = 263,
	DownKey = 264,
	UpKey = 265,
	Space = 32,
	Escape = 256

};

class ENGINE_API InputManager
{
private:
	static InputManager* instance;
	Window* window;

	InputManager();
	~InputManager();
public:
	static InputManager* GetInstance();

	void SetWindow(Window* _window);
	bool GetKeyDown(Key _key);
};


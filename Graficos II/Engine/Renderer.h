#pragma once
#include "Exports.h"
#include <iostream>
class ENGINE_API Renderer
{
public:
	Renderer();
	~Renderer();
	bool Start();
	bool Stop();
};


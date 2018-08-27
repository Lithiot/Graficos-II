#include "Renderer.h"
#include <GLFW\glfw3.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::Start(Window* window)
{	
	glfwMakeContextCurrent((GLFWwindow*) window->GetWindowPtr());
	std::cout << "Renderer::Start()" << std::endl;
	return true;
}

bool Renderer::Stop()
{
	std::cout << "Renderer::Stop()" << std::endl;
	return true;
}

void Renderer::SetClearColor() 
{
	
}
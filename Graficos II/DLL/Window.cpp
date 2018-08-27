#include "Window.h"
#include <GLFW\glfw3.h>

Window::Window()
{
}

Window::~Window()
{
}

bool Window::Start(int width,  int height, const char* name) 
{
	if (!glfwInit()) 
	{
		std::cout << "gflwInit() no pudo ser iniciado" << std::endl;
		return false;
	}
	

	window = glfwCreateWindow(width, height, name, NULL, NULL);
	
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	std::cout << "Ventana iniciada" << std::endl;
	return true;
}

bool Window::Stop() 
{
	if (window != NULL)
		glfwDestroyWindow((GLFWwindow*)window);
	std::cout << "Ventana cerrada" << std::endl;
	glfwTerminate();
	return true;
}

bool Window::ShouldClose() 
{
	if (window)
		return glfwWindowShouldClose((GLFWwindow*)window);
	
	return true;
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void* Window::GetWindowPtr() 
{
	return window;
}
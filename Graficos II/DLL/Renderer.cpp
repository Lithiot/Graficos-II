#include "Renderer.h"
#include <GLFW\glfw3.h>
#include <GL\glew.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::Start(Window* window)
{	
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*) window->GetWindowPtr());
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	std::cout << "Renderer::Start()" << std::endl;
	return true;
}

bool Renderer::Stop()
{
	std::cout << "Renderer::Stop()" << std::endl;
	return true;
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::SwapBuffer()
{
	glfwSwapBuffers((GLFWwindow*)_window->GetWindowPtr());
}

void Renderer::ClearWindow() 
{
	glClear(GL_COLOR_BUFFER_BIT);
}

unsigned int Renderer::GenBuffer(float* buffer, int size) 
{
	unsigned int vertexbuffer;

	glGenBuffers(1, &vertexbuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	return vertexbuffer;
}

void Renderer::Draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  
		3,                  
		GL_FLOAT,           
		GL_FALSE,           
		0,                  
		(void*)0            
	);

	glDrawArrays(GL_TRIANGLES, 0, 3); 
	glDisableVertexAttribArray(0);
}

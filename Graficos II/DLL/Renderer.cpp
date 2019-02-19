#include "Renderer.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>

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
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Falló al inicializar GLEW\n");
		return -1;
	}

	glGenVertexArrays(1, (GLuint*)&VertexArrayID);
	glBindVertexArray((GLuint)VertexArrayID);

	projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);

	view = glm::lookAt(
		glm::vec3(0, 0, 3), 
		glm::vec3(0, 0, 0), 
		glm::vec3(0, 1, 0)
	);
	
	model = glm::mat4(1.0f);

	UpdateMVP();

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

unsigned int Renderer::GenVertexBuffer(float* buffer, int size) 
{
	unsigned int vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	return vertexbuffer;
}

unsigned int Renderer::GenColorBuffer(float* buffer, int size)
{
	unsigned int colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
	return colorbuffer;
}

unsigned int Renderer::GenTextureBuffer(int width, int height, const void* data)
{
	// Se Crea una textura OpenGL 
	unsigned int  texturebuffer;
	glGenTextures(1, &texturebuffer);

	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura 
	glBindTexture(GL_TEXTURE_2D, texturebuffer);

	// Se le pasa la imagen a OpenGL 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);

	return texturebuffer;
}

void Renderer::EnableAtribArray(int id) 
{
	glEnableVertexAttribArray(id);
}

void Renderer::BindBuffer(unsigned int vtxbuffer, int id)
{
	glBindBuffer(GL_ARRAY_BUFFER, vtxbuffer);
	glVertexAttribPointer(
		id,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
}

void Renderer::BindBufferColor(unsigned int colorBuffer, int id)
{
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glVertexAttribPointer(
		id,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
}

void Renderer::BindTextureBuffer(unsigned int txtrebuffer, unsigned int id)
{
	glBindBuffer(GL_ARRAY_BUFFER, txtrebuffer);
	glVertexAttribPointer(
		id,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
}

void Renderer::Draw(char type, int size) 
{
	if(type == 't')
		glDrawArrays(GL_TRIANGLE_STRIP, 0, size);
	else if(type == 's')
		glDrawArrays(GL_TRIANGLE_STRIP, 0, size);
	else if(type == 'c')
		glDrawArrays(GL_TRIANGLE_FAN, 0, size);
}

void Renderer::DisableBuffer(int id) 
{
	glDisableVertexAttribArray(id);
}

void Renderer::UpdateMVP()
{
	mvp = projection * view * model;
}

glm::mat4& Renderer::GetMVP()
{
	return mvp;
}

void Renderer::SetModel(glm::mat4 mod)
{
	model = mod;
	UpdateMVP();
}

void Renderer::MultiplyModel(glm::mat4 mod) 
{
	model *= mod;
	UpdateMVP();
}

void Renderer::LoadIdentityMatrix() 
{
	model = glm::mat4(1.0f);
}

Window* Renderer::GetWindow()
{
	return _window;
}
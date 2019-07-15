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

	SetProjectionOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);

	SetViewMatrix(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	model = glm::mat4(1.0f);

	UpdateMVP();

	std::cout << "Renderer::Start()" << std::endl;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	unsigned int  texturebuffer;
	glGenTextures(1, &texturebuffer);
	
	glBindTexture(GL_TEXTURE_2D, texturebuffer);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);

	return texturebuffer;
}

unsigned int Renderer::GenIndexBuffer(unsigned int* buffer, int size)
{
	unsigned int IndexBuffer;
	glGenBuffers(1, &IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), &buffer[0], GL_STATIC_DRAW);
	return IndexBuffer;
}

unsigned int Renderer::GenIndexBuffer(std::vector<unsigned int> index)
{
	unsigned int IndexBuffer;
	glGenBuffers(1, &IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(unsigned int), &index[0], GL_STATIC_DRAW);
	return IndexBuffer;
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

void Renderer::BindMeshBuffer(unsigned int indexbuffer)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
}

void Renderer::BindIndexBuffer(unsigned int bufferID)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void Renderer::DrawIndexBuffer(int indexcount)
{
	glDrawElements(GL_TRIANGLES, indexcount, GL_UNSIGNED_INT, (void*)0);
}

void Renderer::Draw(char type, int size) 
{
	if (type == 't')
		glDrawArrays(GL_TRIANGLE_STRIP, 0, size);
	else if (type == 's')
		glDrawArrays(GL_TRIANGLE_STRIP, 0, size);
	else if (type == 'c')
		glDrawArrays(GL_TRIANGLE_FAN, 0, size);
	else if (type == 'm')
		glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, (void*)0);
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

glm::mat4 Renderer::GetModel() 
{
	return model;
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

void Renderer::SetProjectionOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	projection = glm::ortho(left, right, bottom, top, zNear, zFar);
	UpdateMVP();
}

void Renderer::SetProjectionPerspective(float fovy, float aspect, float zNear, float zFar)
{
	projection = glm::perspective(fovy, aspect, zNear, zFar);
	UpdateMVP();
}

void Renderer::SetProjectionMatrix(glm::mat4 projection) 
{
	this->projection = projection;
	UpdateMVP();
}

glm::mat4 Renderer::GetProjection() 
{
	return projection;
}

void Renderer::SetViewMatrix(glm::vec3 eye, glm::vec3 center, glm::vec3 up) 
{
	view = glm::lookAt(eye, center, up);
	UpdateMVP();
}

void Renderer::SetViewMatrix(glm::mat4 view)
{
	this->view = view;
	UpdateMVP();
}

glm::mat4 Renderer::GetViewMatrix() 
{
	return view;
}
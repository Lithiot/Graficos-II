#pragma once
#include "Exports.h"
#include <iostream>
#include "Window.h"
#include <glm/gtc/matrix_transform.hpp>

class ENGINE_API Renderer
{
private:
	Window* _window;
	void* VertexArrayID;
	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 mvp;
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
	void UpdateMVP();
	void SetModel(glm::mat4 mod);
	glm::mat4& GetMVP();
	void LoadIdentityMatrix();
	glm::mat4 GenerateMVP(glm::mat4 model);
	void MultiplyModel(glm::mat4 mod);
	void BeginDraw();
	void EndDraw();
	void BindBuffer();
};


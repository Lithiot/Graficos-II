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
	unsigned int GenVertexBuffer(float* buffer, int size);
	unsigned int GenColorBuffer(float* buffer, int size);
	unsigned int GenTextureBuffer(int width, int height, const void* data);
	void EnableAtribArray(int id);
	void BindBuffer(unsigned int vtxbuffer, int id);
	void BindBufferColor(unsigned int colorBuffer, int id);
	void BindTextureBuffer(unsigned int txtrebuffer, unsigned int atribId);
	void Draw(char type, int size);
	void DisableBuffer(int id);
	void UpdateMVP();
	void SetModel(glm::mat4 mod);
	void LoadIdentityMatrix();
	void MultiplyModel(glm::mat4 mod);
	Window* GetWindow();
	glm::mat4& GetMVP();
	void DeleteBuffers(unsigned int _buffer);
	void CameraFollow(glm::vec3 lookAt);

};


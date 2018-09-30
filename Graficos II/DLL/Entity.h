#pragma once
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>


class ENGINE_API Entity
{
private:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
protected:
	glm::mat4 model;
	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
	Renderer* renderer;
	void UpdateModel();
	virtual void Draw() = 0;
public:
	Entity(Renderer* rend);
	~Entity();
	void SetTranslation(float x, float y, float z);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);
	void SetScale(float x, float y, float z);
	glm::vec3 GetTranslation();
	float GetRotationX();
	float GetRotationY();
	float GetRotationZ();
	glm::vec3 GetScale();
};


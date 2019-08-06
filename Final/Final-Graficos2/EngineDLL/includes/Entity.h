#pragma once
#include "Renderer.h"
#include "BoundingBox.h"
#include "Layers.h"
#include "EventManager.h"
#include <glm/gtc/matrix_transform.hpp>


class ENGINE_API Entity
{
private:
	bool isActive;
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
	BoundingBox* collider;
	std::vector<int> eventKeys;
protected:
	glm::vec3 pivot;
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
	float GetPosX();
	float GetPosY();
	float GetPosZ();
	float GetRotationX();
	float GetRotationY();
	float GetRotationZ();
	glm::vec3 GetScale();
	int GetLayer();
	BoundingBox* GetCollider();
	bool GetIsActive();
	void SetIsActive(bool state);
	void SetCollider(float width, float height, Layers layer, bool staticState, bool triggerState);
	void AddEvent(int key, int value, int* valueToChange);
	void AddEvent(int key, float value, float* valueToChange);
	void AddEvent(int key, bool value, bool* valueToChange);
	void fireEvents();
};


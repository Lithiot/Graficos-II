#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "DeltaTime.h"
class ENGINE_API Camera
{
private:
	Renderer* rend;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 foward;
	glm::vec3 right;
	glm::vec3 up;
public:
	Camera(Renderer* rend);
	~Camera();
	void Walk(float velocity);
	void Strafe(float velocity);
	void Roll(float velocity);
	void Yaw(float velocity);
	void Pitch(float velocity);
	void UpdateViewMatrix();
};


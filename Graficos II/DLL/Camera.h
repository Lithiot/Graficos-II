#pragma once
#include "Exports.h"
#include "Renderer.h"
#include "Component.h"
#include "DeltaTime.h"

class ENGINE_API Camera : public Component
{
private:

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 foward;
	glm::vec3 right;
	glm::vec3 up;
public:
	Camera(Renderer* rend);
	~Camera();

	void Start() override;
	void Update() override;
	void Draw() override;
	void Destroy() override;

	void Walk(float velocity);
	void Strafe(float velocity);
	void Roll(float velocity);
	void Yaw(float velocity);
	void Pitch(float velocity);
	void UpdateViewMatrix();
	void SetPosition(glm::vec3 pos);
};


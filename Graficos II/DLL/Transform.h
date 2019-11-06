#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>
using namespace glm;
#include "Component.h"
#include "Renderer.h"

class ENGINE_API Transform : public Component
{
private:
	mat4 model;
	mat4 translationMatrixLocal;
	mat4 rotationMatrixLocal;
	mat4 scaleMatrixLocal;

public:
	Transform(Renderer* rend);
	~Transform();

	vec3 position;
	vec3 rotation;
	vec3 scale;

	void Start() override;
	void Update() override;
	bool Draw() override;
	void Destroy() override;

	void UpdateModel();

	void Translate(float x, float y, float z);
	void SetRotationX(float x);
	void SetRotationY(float y);
	void SetRotationZ(float z);
	void Scale(float x, float y, float z);

	void Move(float x, float y, float z);
	void RotateX(float velocity);
	void RotateY(float velocity);
	void RotateZ(float velocity);

	mat4 GetModel();
	float GetRotX();
	float GetRotY();
	float GetRotZ();
};
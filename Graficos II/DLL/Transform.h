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

class Transform : public Component
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
	void Draw() override;
	void Destroy() override;

	void UpdateModel();

	void Translate(float x, float y, float z);
	void RotateX(float x);
	void RotateY(float y);
	void RotateZ(float z);
	void Scale(float x, float y, float z);
};
#include "Transform.h"

Transform::Transform(Renderer* rend) : Component(rend), model(mat4(1.0f)), translationMatrixLocal(mat4(1.0f)), rotationMatrixLocal(mat4(1.0f)),
						 scaleMatrixLocal(mat4(1.0f))
{
}

Transform::~Transform()
{
}

void Transform::Start() 
{
	position = rotation = scale = vec3(0.0f);

	UpdateModel();
}

void Transform::UpdateModel() 
{
	model = translationMatrixLocal * rotationMatrixLocal * scaleMatrixLocal;
}

void Transform::Translate(float x, float y, float z) 
{
	position[0] = x;
	position[1] = y;
	position[2] = z;

	translationMatrixLocal = translate(glm::mat4(1.0f), position);

	UpdateModel();
}

void Transform::RotateX(float x) 
{
	rotation[0] = x;
	
	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1, 0, 0));
	
	UpdateModel();
}

void Transform::RotateY(float x)
{
	rotation[0] = x;

	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1, 0, 0));

	UpdateModel();
}

void Transform::RotateZ(float x)
{
	rotation[0] = x;

	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1, 0, 0));

	UpdateModel();
}

void Transform::Scale(float x, float y, float z) 
{
	scale[0] = x;
	scale[1] = y;
	scale[2] = z;

	scaleMatrixLocal = glm::scale(glm::mat4(1.0f), scale);

	UpdateModel();
}
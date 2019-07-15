#include "Transform.h"

Transform::Transform(Renderer* rend) : Component(rend), model(mat4(1.0f)), translationMatrixLocal(mat4(1.0f)), rotationMatrixLocal(mat4(1.0f)),
									   scaleMatrixLocal(mat4(1.0f))
{
	position = rotation = scale = vec3(0.0f);
}

Transform::~Transform()
{
}

void Transform::Start() 
{
	

	UpdateModel();
}

void Transform::Update() 
{
	
}

void Transform::Draw() 
{
	
}

void Transform::Destroy() 
{
	
}

void Transform::UpdateModel() 
{
	model = translationMatrixLocal * rotationMatrixLocal * scaleMatrixLocal;
}

void Transform::Translate(float x, float y, float z) 
{
	position = glm::vec3(x, y, z);

	translationMatrixLocal = translate(glm::mat4(1.0f), position);

	UpdateModel();
}

void Transform::Move(float x, float y, float z) 
{
	position[0] += x;
	position[1] += y;
	position[2] += z;

	Translate(position[0], position[1], position[2]);
}

void Transform::SetRotationX(float x) 
{
	rotation[0] = x;
	
	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1, 0, 0));
	
	UpdateModel();
}

void Transform::RotateX(float velocity) 
{
	rotation[0] += velocity;
	SetRotationX(rotation[0]);
}

void Transform::SetRotationY(float y)
{
	rotation[1] = y;

	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), y, glm::vec3(0, 1, 0));

	UpdateModel();
}

void Transform::RotateY(float velocity)
{
	rotation[1] += velocity;
	SetRotationY(rotation[1]);
}

void Transform::SetRotationZ(float z)
{
	rotation[2] = z;

	rotationMatrixLocal = glm::rotate(glm::mat4(1.0f), z, glm::vec3(0, 0, 1));

	UpdateModel();
}

void Transform::RotateZ(float velocity)
{
	rotation[2] += velocity;
	SetRotationZ(rotation[2]);
}

void Transform::Scale(float x, float y, float z) 
{
	scale[0] = x;
	scale[1] = y;
	scale[2] = z;

	scaleMatrixLocal = glm::scale(glm::mat4(1.0f), scale);

	UpdateModel();
}

float Transform::GetRotX() 
{
	return rotation.x;
}

float Transform::GetRotY() 
{
	return rotation.y;
}

float Transform::GetRotZ() 
{
	return rotation.z;
}

mat4 Transform::GetModel()
{
	return model;
}
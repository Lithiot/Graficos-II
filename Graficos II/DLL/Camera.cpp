#include "Camera.h"
#include <glm/gtx/transform.hpp>

Camera::Camera(Renderer* rend) : rend(rend), position(0.0f,0.0f,-1.0f), foward(0.0f,0.0f,1.0f), right(1.0f,0.0f,0.0f),
								 up(0.0f, 1.0f, 0.0f), rotation(position + foward)
{
	
}

Camera::~Camera()
{

}

void Camera::Walk(float velocity) 
{
	position += glm::vec3(0.0f, 0.0f, velocity * DeltaTime::Instance()->GetDeltaTime());
	updateViewMatrix();
}

void Camera::Strafe(float velocity) 
{
	position -= glm::vec3(velocity * DeltaTime::Instance()->GetDeltaTime(), 0.0f, 0.0f);
	updateViewMatrix();
}

void Camera::Roll(float velocity) 
{
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), velocity, right);
	rotation *= rot;
	updateViewMatrix();
}

void Camera::Yaw(float velocity) 
{
	
}

void Camera::Pitch(float velocity) 
{
	
}

void Camera::updateViewMatrix() 
{
	rend->SetViewMatrix(position, rotation + foward, up);
}


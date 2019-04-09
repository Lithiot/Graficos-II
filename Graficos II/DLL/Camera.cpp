#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
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
	position += foward * velocity * (float)DeltaTime::Instance()->GetDeltaTime();
	UpdateViewMatrix();
}

void Camera::Strafe(float velocity) 
{
	position -= right * velocity * (float)DeltaTime::Instance()->GetDeltaTime();
	UpdateViewMatrix();
}

void Camera::Roll(float velocity) 
{
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), (float)(velocity * DeltaTime::Instance()->GetDeltaTime()), foward);
	glm::vec4 aux = glm::vec4(foward.x, foward.y, foward.z, 0.0f);
	aux = rot * aux;
	foward.x = aux.x;
	foward.y = aux.y;
	foward.z = aux.z;

	aux = glm::vec4(up.x, up.y, up.z, 0.0f);
	aux = rot * aux;
	up.x = aux.x;
	up.y = aux.y;
	up.z = aux.z;

	UpdateViewMatrix();
}

void Camera::Yaw(float velocity) 
{
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), (float)(velocity * DeltaTime::Instance()->GetDeltaTime()), up);
	glm::vec4 aux = glm::vec4(foward.x, foward.y, foward.z, 0.0f);
	aux = rot * aux;
	foward.x = aux.x;
	foward.y = aux.y;
	foward.z = aux.z;

	aux = glm::vec4(up.x, up.y, up.z, 0.0f);
	aux = rot * aux;
	up.x = aux.x;
	up.y = aux.y;
	up.z = aux.z;

	UpdateViewMatrix();
}

void Camera::Pitch(float velocity) 
{
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), (float)(velocity * DeltaTime::Instance()->GetDeltaTime()), right);
	glm::vec4 aux = glm::vec4(foward.x, foward.y, foward.z, 0.0f);
	aux = rot * aux;
	foward.x = aux.x;
	foward.y = aux.y;
	foward.z = aux.z;

	aux = glm::vec4(up.x, up.y, up.z, 0.0f);
	aux = rot * aux;
	up.x = aux.x;
	up.y = aux.y;
	up.z = aux.z;

	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix() 
{
	rend->SetViewMatrix(position, position + foward, up);
}


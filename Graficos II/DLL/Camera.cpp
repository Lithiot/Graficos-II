#include "Camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

Camera::Camera(Renderer* rend) : Component(rend, Type::CAMERA), position(0.0f,0.0f,-1.0f, 0.0f), forward(0.0f,0.0f,1.0f, 0.0f), right(1.0f,0.0f,0.0f, 0.0f),
								 up(0.0f, 1.0f, 0.0f, 0.0f), rotation(position + forward)
{
	point = (position + forward);
	upVector = up;
	UpdateViewMatrix();

	nearDistance = 0.1f;
	farDistance = 10000.0f;
	aspectRatio = 4.0f / 3.0f;
	angle = glm::radians(45.0f);

	rend->SetProjectionPerspective(angle, aspectRatio, nearDistance, farDistance);
	SetCameraInternals();
	UpdateViewMatrix();
}

Camera::~Camera()
{

}

void Camera::Start() 
{
	
}

void Camera::Update() 
{
	UpdateViewMatrix();
}

bool Camera::Draw() 
{
	return true;
}

void Camera::Destroy() 
{
	
}

void Camera::Walk(float velocity) 
{
	position += forward * velocity * (float)DeltaTime::Instance()->GetDeltaTime();
	UpdateViewMatrix();
}

void Camera::Strafe(float velocity) 
{
	position -= right * velocity * (float)DeltaTime::Instance()->GetDeltaTime();
	UpdateViewMatrix();
}

void Camera::Roll(float velocity) 
{
	right = glm::rotate(mat4(1.0f), velocity, (glm::vec3)forward) * right;
	up = glm::rotate(mat4(1.0f), velocity, (glm::vec3)forward) * up;

	UpdateViewMatrix();
}

void Camera::Yaw(float velocity) 
{
	forward = glm::rotate(glm::mat4(1.0f), velocity, (glm::vec3)up) * forward;
	right = glm::rotate(glm::mat4(1.0f), velocity, (glm::vec3)up) * right;

	UpdateViewMatrix();
}

void Camera::Pitch(float velocity) 
{
	forward = glm::rotate(glm::mat4(1.0f), velocity, (glm::vec3)right) * forward;
	up = glm::rotate(glm::mat4(1.0f), velocity, (glm::vec3)right) * up;
	
	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix() 
{
	SetCameraDefinitions();
	rend->SetViewMatrix(position, position + forward, up);
}

void Camera::SetPosition(glm::vec3 pos) 
{
	position = glm::vec4(pos.x, pos.y, pos.z, 0.0f);
	UpdateViewMatrix();
}

void Camera::SetCameraInternals() 
{
	tang = tan(angle * 0.5f);
	nearHight = nearDistance * tang;
	nearWidht = nearHight * aspectRatio;
}

void Camera::SetCameraDefinitions()
{
	vec3 rightFrustrum = (vec3)right;
	vec3 upFrustrum = (vec3)up;

	vec3 nearCenter = (vec3)position + (vec3)forward * nearDistance;
	vec3 farCenter = (vec3)position + (vec3)forward * farDistance;

	vec3 leftPlaneVec = (nearCenter - rightFrustrum * nearWidht) - (vec3)position;
	vec3 rightPlaneVec = (nearCenter + rightFrustrum * nearWidht) - (vec3)position;
	vec3 topPlaneVec = (nearCenter + upFrustrum * nearHight) - (vec3)position;
	vec3 bottomPlaneVec = (nearCenter - upFrustrum * nearHight) - (vec3)position;

	vec3 normalLeft = normalize(glm::cross(leftPlaneVec, upFrustrum));
	vec3 normalRight = -normalize(glm::cross(rightPlaneVec, upFrustrum));
	vec3 normalTop = normalize(glm::cross(topPlaneVec, rightFrustrum));
	vec3 normalBottom = -normalize(glm::cross(bottomPlaneVec, rightFrustrum));

	planes[NEARP] = GeneratePlane(-(vec3)forward, nearCenter);
	planes[FARP] = GeneratePlane((vec3)forward, farCenter);
	planes[LEFT] = GeneratePlane(normalLeft, (vec3)position);
	planes[RIGHT] = GeneratePlane(normalRight, (vec3)position);
	planes[TOP] = GeneratePlane(normalTop, (vec3)position);
	planes[BOTTOM] = GeneratePlane(normalBottom, (vec3)position);
}

glm::vec4 Camera::GeneratePlane(glm::vec3 _normal, glm::vec3 _point)
{
	glm::vec4 plane;

	plane.x = _normal.x;
	plane.y = _normal.y;
	plane.z = _normal.z;
	plane.w = -glm::dot(_normal, _point);

	return plane;
}

bool Camera::BoxInFrustum(BoxCollider* _collider3d)
{
	if (!_collider3d->loaded)
	{
		return true;
	}

	bool isInsideFrustum = true;
	bool allOutsideCurrentPlane = false;
	for (int i = 0; i < (int)Planes::COUNT; i++)
	{
		allOutsideCurrentPlane = false;
		float dist[8];

		for (int j = 0; j < 8; j++)
		{
			vec3 vertexPosition = _collider3d->GetVertex(j);
			vec3 planeNormal = glm::vec3(planes[i]);

			dist[j] = glm::dot(planeNormal, vertexPosition) + planes[i].w;
			if (dist[j] < 0.0f)
				break;
			if (j == CANT_COLLIDER_VERTEX - 1)
			{
				allOutsideCurrentPlane = true;
			}
		}
		if (allOutsideCurrentPlane)
		{
			isInsideFrustum = false;
			break;
		}
	}
	return isInsideFrustum;
}


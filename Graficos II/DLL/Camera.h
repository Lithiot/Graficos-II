#pragma once
#include "Exports.h"
#include "DeltaTime.h"
#include "Collider3D.h"
#include "BoxCollider.h"

enum Planes 
{
	TOP = 0, BOTTOM, LEFT, RIGHT, NEARP, FARP, COUNT
};

class ENGINE_API Camera : public Component
{
private:
	glm::vec4 position;
	glm::vec4 rotation;
	glm::vec4 forward;
	glm::vec4 right;
	glm::vec4 up;

	glm::vec4 upVector;
	glm::vec4 point;
	glm::vec4 planes[COUNT];

	glm::vec3 nearTopLeft;
	glm::vec3 nearTopRight;
	glm::vec3 nearBottomLeft;
	glm::vec3 nearBottomRight;
	glm::vec3 farTopLeft;
	glm::vec3 farTopRight;
	glm::vec3 farBottomLeft;
	glm::vec3 farBottomRight;

	float nearDistance;
	float farDistance;
	float aspectRatio;
	float angle;
	float tang;
	float nearWidht;
	float nearHight;

	std::vector<glm::vec4>* bspPlanes;
	std::vector<glm::vec3>* bspNormals;

	std::vector<glm::vec3>* bspPoints;

public:
	Camera(Renderer* rend);
	~Camera();

	void Start() override;
	void Update() override;
	bool Draw() override;
	void Destroy() override;

	void Walk(float velocity);
	void Strafe(float velocity);
	void Roll(float velocity);
	void Yaw(float velocity);
	void Pitch(float velocity);
	void UpdateViewMatrix();
	void SetPosition(glm::vec3 pos);

	void SetCameraInternals();
	void SetCameraDefinitions();
	glm::vec4 GeneratePlane(glm::vec3 _normal, glm::vec3 _point);
	bool BoxInFrustum(BoxCollider* _collider3d);

	void AddBSP(vec3 forward, vec3 pos);
	bool BoxInBSP(BoxCollider* _collider3d);
	float GetDistanceToPlane(vec3 point, vec4 _plane, vec3 _planeNormal);
};


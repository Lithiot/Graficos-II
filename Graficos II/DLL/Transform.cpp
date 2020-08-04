#include "Transform.h"

Transform::Transform(Renderer* rend) : Component(rend, Type::TRANSFORM), model(mat4(1.0f)), translationMatrixLocal(mat4(1.0f)), rotationMatrixLocal(mat4(1.0f)),
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

bool Transform::Draw() 
{
	return true;
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

mat4 Transform::GetRotMatrix()
{
	return rotationMatrixLocal;
}

vec3 Transform::GetPosition()
{
	return position;
}

void Transform::SetRotationMatrix(float x, float y, float z, float w)
{
	float pitch, yaw, roll;

	vec4 quaternion = normalize(vec4(x, y, z, w));

	ConvertToEulerAngles(quaternion, pitch, yaw, roll);

	rotation = vec3(pitch, yaw, roll);

	mat4 mat1 = mat4
	{
		quaternion.w, quaternion.z, -quaternion.y, quaternion.x,
		-quaternion.z, quaternion.w, quaternion.x, quaternion.y,
		quaternion.y, -quaternion.x, quaternion.w, quaternion.z,
		-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w
	};

	mat4 mat2 = mat4
	{
		quaternion.w, quaternion.z, -quaternion.y, -quaternion.x,
		-quaternion.z, quaternion.w, quaternion.x, -quaternion.y,
		quaternion.y, -quaternion.x, quaternion.w, -quaternion.z,
		quaternion.x, quaternion.y, quaternion.z, quaternion.w
	};

	rotationMatrixLocal = mat1 * mat2;

	ClampEulerRotation();
	UpdateModel();
}

void Transform::ConvertToEulerAngles(const vec4 quaternion, float& pitch, float& yaw, float& roll)
{
	float sinPitchCosYaw = 2.0f * (quaternion.w * quaternion.x + quaternion.y * quaternion.z);
	float cosPitchCosYaw = 1.0f - 2.0f * (quaternion.x * quaternion.x + quaternion.y * quaternion.y);
	pitch = atan(sinPitchCosYaw, cosPitchCosYaw);

	float sinYaw = 2.0f * (quaternion.w * quaternion.y - quaternion.z * quaternion.x);
	yaw = (abs(sinYaw) >= 1.0f) ? sign(sinYaw) * half_pi<float>() : asin(sinYaw);

	float sinRollCosYaw = 2.0f * (quaternion.w * quaternion.z + quaternion.x * quaternion.y);
	float cosRollCosYaw = 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z);
	roll = atan(sinRollCosYaw, cosRollCosYaw);

	pitch = degrees(pitch);
	yaw = degrees(yaw);
	roll = degrees(roll);
}

void Transform::ClampEulerRotation()
{
	if (rotation.x < 0.0f || rotation.x >= 360.0f)
		rotation.x = rotation.x - (floor(rotation.x / 360.0f) * 360.0f);

	if (rotation.y < 0.0f || rotation.y >= 360.0f)
		rotation.y = rotation.y - (floor(rotation.y / 360.0f) * 360.0f);

	if (rotation.z < 0.0f || rotation.z >= 360.0f)
		rotation.z = rotation.z - (floor(rotation.z / 360.0f) * 360.0f);
}
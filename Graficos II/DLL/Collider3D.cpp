#include "Collider3D.h"

Collider3D::Collider3D(Renderer* rend)
{
	this->rend = rend;
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		collider3d[i] = vec3(0.0f, 0.0f, 0.0f);
	}
	loaded = false;
}

Collider3D::~Collider3D()
{
}

vec3 Collider3D::GetVertex(int index) 
{
	vec4 globalRotatedPos(collider3d[index].x, collider3d[index].y, collider3d[index].z, 1.0f);

	globalRotatedPos = rend->GetModel() * globalRotatedPos;

	return (vec3)globalRotatedPos;
}

void Collider3D::SetVertex(vec3 _collider3d[CANT_COLLIDER_VERTEX])
{
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		collider3d[i] = _collider3d[i];
	}
	loaded = true;
}
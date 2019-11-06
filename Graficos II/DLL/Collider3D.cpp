#include "Collider3D.h"
#include "Cube.h"

Collider3D::Collider3D(Renderer* rend)
{
	this->rend = rend;
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		collider3d[i] = vec3(0.0f, 0.0f, 0.0f);
	}
	wireCube = new Cube(rend);
	loaded = false;
}

Collider3D::~Collider3D()
{
}

void Collider3D::Draw() 
{
	wireCube->Draw();
}

vec3 Collider3D::GetVertex(int index)
{
	vec4 globalRotatedPos(collider3d[index].x, collider3d[index].y, collider3d[index].z, 1.0f);

	globalRotatedPos = rend->GetModel() * globalRotatedPos;

	return (vec3)globalRotatedPos;
}

void Collider3D::UpdateVertex(vec3 _collider3d[CANT_COLLIDER_VERTEX]) 
{
	// pos [0]
	if (_collider3d[0].x < collider3d[0].x)
		collider3d[0].x = _collider3d[0].x;
	if (_collider3d[0].y < collider3d[0].y)
		collider3d[0].y = _collider3d[0].y;
	if (_collider3d[0].z < collider3d[0].z)
		collider3d[0].z = _collider3d[0].z;

	// pos [1]
	if (_collider3d[1].x < collider3d[1].x)
		 collider3d[1].x = _collider3d[1].x;
	if (_collider3d[1].y > collider3d[1].y)
		 collider3d[1].y = _collider3d[1].y;
	if (_collider3d[1].z < collider3d[1].z)
		 collider3d[1].z = _collider3d[1].z;

	// pos [2]
	if (_collider3d[2].x < collider3d[2].x)
		 collider3d[2].x = _collider3d[2].x;
	if (_collider3d[2].y < collider3d[2].y)
		 collider3d[2].y = _collider3d[2].y;
	if (_collider3d[2].z > collider3d[2].z)
		 collider3d[2].z = _collider3d[2].z;

	// pos [3]
	if (_collider3d[3].x < collider3d[3].x)
		 collider3d[3].x = _collider3d[3].x;
	if (_collider3d[3].y > collider3d[3].y)
		 collider3d[3].y = _collider3d[3].y;
	if (_collider3d[3].z > collider3d[3].z)
		 collider3d[3].z = _collider3d[3].z;

	// pos [4]
	if (_collider3d[4].x >  collider3d[4].x)
		 collider3d[4].x = _collider3d[4].x;
	if (_collider3d[4].y <  collider3d[4].y)
		 collider3d[4].y = _collider3d[4].y;
	if (_collider3d[4].z <  collider3d[4].z)
		 collider3d[4].z = _collider3d[4].z;

	// pos [5]
	if (_collider3d[5].x > collider3d[5].x)
		 collider3d[5].x =_collider3d[5].x;
	if (_collider3d[5].y > collider3d[5].y)
		 collider3d[5].y =_collider3d[5].y;
	if (_collider3d[5].z < collider3d[5].z)
		 collider3d[5].z =_collider3d[5].z;

	// pos [6]
	if (_collider3d[6].x > collider3d[6].x)
		 collider3d[6].x =_collider3d[6].x;
	if (_collider3d[6].y < collider3d[6].y)
		 collider3d[6].y =_collider3d[6].y;
	if (_collider3d[6].z > collider3d[6].z)
		 collider3d[6].z =_collider3d[6].z;

	// pos [7]
	if (_collider3d[7].x > collider3d[7].x)
		 collider3d[7].x =_collider3d[7].x;
	if (_collider3d[7].y > collider3d[7].y)
		 collider3d[7].y =_collider3d[7].y;
	if (_collider3d[7].z > collider3d[7].z)
		 collider3d[7].z =_collider3d[7].z;

	// Updates collider wireBox
	float* vertexes = new float[CANT_COLLIDER_VERTEX * 3]
	{
		// Front
		collider3d[0].x, collider3d[0].y, collider3d[0].z,
		collider3d[1].x, collider3d[1].y, collider3d[1].z,
		collider3d[2].x, collider3d[2].y, collider3d[2].z,
		collider3d[3].x, collider3d[3].y, collider3d[3].z,

		// Back
		collider3d[4].x, collider3d[4].y, collider3d[4].z,
		collider3d[5].x, collider3d[5].y, collider3d[5].z,
		collider3d[6].x, collider3d[6].y, collider3d[6].z,
		collider3d[7].x, collider3d[7].y, collider3d[7].z,
	};
	wireCube->SetVertex(vertexes, CANT_COLLIDER_VERTEX * 3);
}

void Collider3D::SetVertex(vec3 _collider3d[CANT_COLLIDER_VERTEX])
{
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		collider3d[i] = _collider3d[i];
	}

	float* vertexes = new float[CANT_COLLIDER_VERTEX * 3]
	{
		// Front
		collider3d[0].x, collider3d[0].y, collider3d[0].z,
		collider3d[1].x, collider3d[1].y, collider3d[1].z,
		collider3d[2].x, collider3d[2].y, collider3d[2].z,
		collider3d[3].x, collider3d[3].y, collider3d[3].z,

		// Back
		collider3d[4].x, collider3d[4].y, collider3d[4].z,
		collider3d[5].x, collider3d[5].y, collider3d[5].z,
		collider3d[6].x, collider3d[6].y, collider3d[6].z,
		collider3d[7].x, collider3d[7].y, collider3d[7].z,
	};
	wireCube->SetVertex(vertexes, CANT_COLLIDER_VERTEX * 3);

	loaded = true;
}
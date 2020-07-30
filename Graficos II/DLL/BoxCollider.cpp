#include "BoxCollider.h"
#include "Material.h"
#include "Node.h"

BoxCollider::BoxCollider(Renderer* renderer) : Component(renderer, Type::BOX_COLLIDER)
{
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		colliderVertex[i] = originalCollider[i] = vec3(0.0f, 0.0f, 0.0f);
	}
	loaded = false;
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Start() 
{
}

void BoxCollider::SetVertex(vec3 colliderMin, vec3 colliderMax)
{
	glm::vec3 colliderVertices[CANT_COLLIDER_VERTEX] =
	{
		vec3(colliderMin.x, colliderMin.y, colliderMin.z),
		vec3(colliderMin.x, colliderMax.y, colliderMin.z),
		vec3(colliderMin.x, colliderMin.y, colliderMax.z),
		vec3(colliderMin.x, colliderMax.y, colliderMax.z),
		vec3(colliderMax.x, colliderMin.y, colliderMin.z),
		vec3(colliderMax.x, colliderMax.y, colliderMin.z),
		vec3(colliderMax.x, colliderMin.y, colliderMax.z),
		vec3(colliderMax.x, colliderMax.y, colliderMax.z)
	};

	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		colliderVertex[i] = originalCollider[i] = colliderVertices[i];
	}

	SetFaces();
	SetMaterial();
	
	float* vertexes = new float[CANT_COLLIDER_VERTEX * 3]
	{
		// Front
		colliderVertex[0].x, colliderVertex[0].y, colliderVertex[0].z,
		colliderVertex[1].x, colliderVertex[1].y, colliderVertex[1].z,
		colliderVertex[2].x, colliderVertex[2].y, colliderVertex[2].z,
		colliderVertex[3].x, colliderVertex[3].y, colliderVertex[3].z,

		// Back
		colliderVertex[4].x, colliderVertex[4].y, colliderVertex[4].z,
		colliderVertex[5].x, colliderVertex[5].y, colliderVertex[5].z,
		colliderVertex[6].x, colliderVertex[6].y, colliderVertex[6].z,
		colliderVertex[7].x, colliderVertex[7].y, colliderVertex[7].z,
	};
	vertexBufferID = rend->GenVertexBuffer(vertexes, sizeof(float) * CANT_COLLIDER_VERTEX * 3);

	// Atualizo el collider de los padres para que me incluyan
	if (owner && owner->GetParent()) 
	{
		if (owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER))
		{
			BoxCollider* collider = (BoxCollider*)owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER);
			if (collider != NULL)
			{
				collider->UpdateVertex(colliderVertex);
			}
		}
	}
	
	loaded = true;
}

vec3 BoxCollider::GetVertex(int index)
{
	vec4 globalRotatedPos(colliderVertex[index].x, colliderVertex[index].y, colliderVertex[index].z, 1.0f);

	globalRotatedPos = rend->GetModel() * globalRotatedPos;

	return (vec3)globalRotatedPos;
}

vec3 BoxCollider::GetRawVertex(int index)
{
	vec4 globalRotatedPos(colliderVertex[index].x, colliderVertex[index].y, colliderVertex[index].z, 1.0f);
	return (vec3)globalRotatedPos;
}

void BoxCollider::Update() 
{
	// Actualizar collider actual con la posicion actual del objeto (GetModel())
	glm::vec3 colliderVertices[CANT_COLLIDER_VERTEX];
	
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		vec4 aux = vec4(GetVertex(i), 0.0f);
		colliderVertices[i] = rend->GetModel() * aux;
	}

	// Atualizo el collider de los padres para que me incluyan
	if (owner && owner->GetParent())
	{
		if (owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER))
		{
			BoxCollider* collider = (BoxCollider*)owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER);
			if (collider != NULL)
			{
				collider->UpdateVertex(colliderVertices);
			}
		}
	}
}

void BoxCollider::UpdateVertex(vec3 _collider3d[CANT_COLLIDER_VERTEX])
{
	for (int i = 0; i < CANT_COLLIDER_VERTEX; i++)
	{
		colliderVertex[i] = originalCollider[i];
	}

	// pos [0]
	if (_collider3d[0].x < colliderVertex[0].x)
		colliderVertex[0].x = _collider3d[0].x;
	if (_collider3d[0].y < colliderVertex[0].y)
		colliderVertex[0].y = _collider3d[0].y;
	if (_collider3d[0].z < colliderVertex[0].z)
		colliderVertex[0].z = _collider3d[0].z;

	// pos [1]
	if (_collider3d[1].x < colliderVertex[1].x)
		colliderVertex[1].x = _collider3d[1].x;
	if (_collider3d[1].y > colliderVertex[1].y)
		colliderVertex[1].y = _collider3d[1].y;
	if (_collider3d[1].z < colliderVertex[1].z)
		colliderVertex[1].z = _collider3d[1].z;

	// pos [2]
	if (_collider3d[2].x < colliderVertex[2].x)
		colliderVertex[2].x = _collider3d[2].x;
	if (_collider3d[2].y < colliderVertex[2].y)
		colliderVertex[2].y = _collider3d[2].y;
	if (_collider3d[2].z > colliderVertex[2].z)
		colliderVertex[2].z = _collider3d[2].z;

	// pos [3]
	if (_collider3d[3].x < colliderVertex[3].x)
		colliderVertex[3].x = _collider3d[3].x;
	if (_collider3d[3].y > colliderVertex[3].y)
		colliderVertex[3].y = _collider3d[3].y;
	if (_collider3d[3].z > colliderVertex[3].z)
		colliderVertex[3].z = _collider3d[3].z;

	// pos [4]
	if (_collider3d[4].x > colliderVertex[4].x)
		colliderVertex[4].x = _collider3d[4].x;
	if (_collider3d[4].y < colliderVertex[4].y)
		colliderVertex[4].y = _collider3d[4].y;
	if (_collider3d[4].z < colliderVertex[4].z)
		colliderVertex[4].z = _collider3d[4].z;

	// pos [5]
	if (_collider3d[5].x > colliderVertex[5].x)
		colliderVertex[5].x = _collider3d[5].x;
	if (_collider3d[5].y > colliderVertex[5].y)
		colliderVertex[5].y = _collider3d[5].y;
	if (_collider3d[5].z < colliderVertex[5].z)
		colliderVertex[5].z = _collider3d[5].z;

	// pos [6]
	if (_collider3d[6].x > colliderVertex[6].x)
		colliderVertex[6].x = _collider3d[6].x;
	if (_collider3d[6].y < colliderVertex[6].y)
		colliderVertex[6].y = _collider3d[6].y;
	if (_collider3d[6].z > colliderVertex[6].z)
		colliderVertex[6].z = _collider3d[6].z;

	// pos [7]
	if (_collider3d[7].x > colliderVertex[7].x)
		colliderVertex[7].x = _collider3d[7].x;
	if (_collider3d[7].y > colliderVertex[7].y)
		colliderVertex[7].y = _collider3d[7].y;
	if (_collider3d[7].z > colliderVertex[7].z)
		colliderVertex[7].z = _collider3d[7].z;

	float* vertexes = new float[CANT_COLLIDER_VERTEX * 3]
	{
		// Front
		colliderVertex[0].x, colliderVertex[0].y, colliderVertex[0].z,
		colliderVertex[1].x, colliderVertex[1].y, colliderVertex[1].z,
		colliderVertex[2].x, colliderVertex[2].y, colliderVertex[2].z,
		colliderVertex[3].x, colliderVertex[3].y, colliderVertex[3].z,

		// Back
		colliderVertex[4].x, colliderVertex[4].y, colliderVertex[4].z,
		colliderVertex[5].x, colliderVertex[5].y, colliderVertex[5].z,
		colliderVertex[6].x, colliderVertex[6].y, colliderVertex[6].z,
		colliderVertex[7].x, colliderVertex[7].y, colliderVertex[7].z,
	};
	vertexBufferID = rend->GenVertexBuffer(vertexes, sizeof(float) * CANT_COLLIDER_VERTEX * 3);

	// Atualizo el collider de los padres para que me incluyan
	if (owner && owner->GetParent())
	{
		if (owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER))
		{
			BoxCollider* collider = (BoxCollider*)owner->GetParent()->GetComponentByType(Type::BOX_COLLIDER);
			if (collider != NULL)
			{
				collider->UpdateVertex(colliderVertex);
			}
		}
	}
}

bool BoxCollider::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (material != NULL)
	{
		material->Bind();
		material->SetMatrixProperty("MVP", rend->GetMVP());
	}

	rend->EnableAtribArray(0);
	rend->BindBuffer(vertexBufferID, 0);
	rend->BindIndexBuffer(IndexBufferID);
	rend->Draw('m', indexCount);
	rend->DisableBuffer(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	return true;
}

void BoxCollider::Destroy()
{
}

void BoxCollider::SetFaces()
{
	indexCount = 36;
	unsigned int indexes[36] =
	{
		// Front
		0, 1, 2,
		0, 2, 3,
		// Back
		4, 5, 6,
		4, 6, 7,
		// Right
		1, 5, 6,
		1, 6, 2,
		// Left
		0, 4, 7,
		0, 7, 3,
		// Upper
		3, 2, 6,
		3, 6, 7,
		// Bottom
		0, 1, 5,
		0, 5, 4
	};

	IndexBufferID = (rend->GenIndexBuffer(indexes, indexCount * sizeof(unsigned int)));
}

void BoxCollider::SetMaterial()
{
	material = new Material();
	programID = material->LoadShaders("VertexShader.txt", "FragmentShader.txt");
}
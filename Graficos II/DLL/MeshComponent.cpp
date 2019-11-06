#include "MeshComponent.h"
#include "Node.h"

MeshComponent::MeshComponent(Renderer* rend, Camera* cam) : Component(rend, Type::MESH_COMPONENT), collider3d(new Collider3D(rend)), cam(cam)
{
}

MeshComponent::~MeshComponent()
{

}

void MeshComponent::Start() 
{
	
}

void MeshComponent::Update() 
{
	glm::vec3 colliderVertices[CANT_COLLIDER_VERTEX] =
	{
		collider3d->GetVertex(0), collider3d->GetVertex(1),
		collider3d->GetVertex(2), collider3d->GetVertex(3),
		collider3d->GetVertex(4), collider3d->GetVertex(5),
		collider3d->GetVertex(6), collider3d->GetVertex(7),
	};

	if (owner && owner->GetParent())
		if (owner->GetParent()->GetComponentByType(Type::MESH_COMPONENT))
		{
			MeshComponent* meh = (MeshComponent*)owner->GetParent()->GetComponentByType(Type::MESH_COMPONENT);
			if (meh != NULL)
			{
				meh->UpdateCollider(colliderVertices);
			}
		}
}

bool MeshComponent::Draw()
{
	if (cam->BoxInFrustum(collider3d))
	{
		if (material != NULL)
		{
			material->Bind();
			material->SetMatrixProperty("MVP", rend->GetMVP());
			material->BindTexture("myTextureSampler", textureBufferID);
		}
		rend->EnableAtribArray(0);
		rend->EnableAtribArray(1);
		rend->BindBuffer(vertexBufferID, 0);
		rend->BindTextureBuffer(uvBufferID, 1);
		rend->BindIndexBuffer(IndexBufferID);
		rend->DrawIndexBuffer(facesIndex.size());
		rend->DisableBuffer(0);
		rend->DisableBuffer(1);

		collider3d->Draw();

		DeltaTime::Instance()->AddMeshDrawn();
		return true;
	}
	else
	{
		return false;
	}
}

void MeshComponent::Destroy() 
{
	
}

void MeshComponent::SetVertices(std::vector<float> vertices)
{
	this->vertices = vertices;
	vertexBufferID = rend->GenVertexBuffer(&vertices[0], vertices.size() * sizeof(float));
}

void MeshComponent::SetUVS(std::vector<float> uvs)
{
	this->uvs = uvs;
	uvBufferID = rend->GenVertexBuffer(&uvs[0], uvs.size() * sizeof(float));
}

void MeshComponent::SetFaces(std::vector<unsigned int> faces)
{
	facesIndex = faces;
	IndexBufferID = rend->GenIndexBuffer(facesIndex);
}

void MeshComponent::LoadMaterial() 
{
	material = new Material();
	programID = material->LoadShaders("TextureVertexShader.txt", "TextureFragmentShader.txt");
}

void MeshComponent::SetTexture(string texturePath) 
{
	texture = TextureLoader::LoadBMP(texturePath.c_str());
	textureBufferID = rend->GenTextureBuffer(texture.width, texture.height, texture.data);
}

void MeshComponent::GenerateCollider(glm::vec3 colliderMin, glm::vec3 colliderMax)
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

	if(owner && owner->GetParent())
		if (owner->GetParent()->GetComponentByType(Type::MESH_COMPONENT)) 
		{
			MeshComponent* meh = (MeshComponent*)owner->GetParent()->GetComponentByType(Type::MESH_COMPONENT);
			if (meh != NULL)
			{
				meh->UpdateCollider(colliderVertices);
			}
		}

	collider3d->SetVertex(colliderVertices);
}

void MeshComponent::UpdateCollider(vec3 _collider3d[CANT_COLLIDER_VERTEX])
{
	collider3d->UpdateVertex(_collider3d);
}
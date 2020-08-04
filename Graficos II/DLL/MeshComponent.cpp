#include "MeshComponent.h"
#include "Node.h"

MeshComponent::MeshComponent(Renderer* rend, Camera* cam) : Component(rend, Type::MESH_COMPONENT) ,cam(cam)
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
}

bool MeshComponent::Draw()
{
	BoxCollider* collider = (BoxCollider*)owner->GetComponentByType(Type::BOX_COLLIDER);

	if (cam->BoxInBSP(collider))
	{
		if (cam->BoxInFrustum(collider))
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

			DeltaTime::Instance()->AddMeshDrawn();
			return true;
		}
	}
	return false;
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
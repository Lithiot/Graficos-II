#include "Colectable.h"

Colectable::Colectable(Renderer* rend, const char* file, float cantSpritesX, float cantSpritesY, int cantSpritesTotal, bool isStatic, bool isTrigger) : isActive(true)
{
	mat = new Material();
	programID = mat->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite = new Sprite(rend, cantSpritesX, cantSpritesY, cantSpritesTotal);
	sprite->SetMaterial(mat);
	sprite->LoadTexture(file);
	sprite->SetCollider(1.8f, 1.8f, Entities, isStatic, isTrigger);
	CollisionManager::Instance()->RegisterEntity(sprite);
}

Colectable::~Colectable()
{
}

void Colectable::Update() 
{
	sprite->UpdateFrame();
	sprite->SetIsActive(isActive);
}

void Colectable::Draw()
{
	if (sprite->GetIsActive())
		sprite->Draw();
}

void Colectable::SetPosition(float x, float y, float z)
{
	sprite->SetTranslation(x, y, z);
}

glm::vec3 Colectable::GetPosition()
{
	return glm::vec3(sprite->GetPosX(), sprite->GetPosY(), sprite->GetPosZ());
}

void Colectable::createPickUpEvent(int key) 
{
	sprite->AddEvent(key, false, &isActive);
}
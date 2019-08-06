#include "Player.h"
#include <Tilemap.h>

Player::Player(Renderer* rend, const char* file, float cantSpritesX, float cantSpritesY, int cantSpritesTotal) : vel(2.0f)
{
	InputManager::GetInstance()->SetWindow(rend->GetWindow());

	mat = new Material();
	programID = mat->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite = new Sprite(rend, cantSpritesX, cantSpritesY, cantSpritesTotal);
	sprite->SetMaterial(mat);
	sprite->LoadTexture(file);
	sprite->SetCollider(1.8f, 1.8f, player, false, false);
	CollisionManager::Instance()->RegisterEntity(sprite);
}

Player::~Player() 
{
}

bool Player::Update(Tilemap* tilemap)
{
	if (!sprite->GetIsActive())
		return false;

	sprite->UpdateFrame();

	if (!tilemap->IsNextTileCollisionable(sprite->GetPosX(), sprite->GetPosY(), 1.8f, RIGHT))
		sprite->SetTranslation(sprite->GetPosX() + vel * DeltaTime::Instance()->GetDeltaTime(), sprite->GetPosY(), 0.0f);
	else
		ToggleActive();

	if (InputManager::GetInstance()->GetKeyDown(UpKey))
	{
		if (!tilemap->IsNextTileCollisionable(sprite->GetPosX(), sprite->GetPosY(), 1.8f, UP))
			sprite->SetTranslation(sprite->GetPosX(), sprite->GetPosY() + 1.0f * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(DownKey))
	{
		if (!tilemap->IsNextTileCollisionable(sprite->GetPosX(), sprite->GetPosY(), 1.8f, DOWN))
			sprite->SetTranslation(sprite->GetPosX(), sprite->GetPosY() - 1.0f * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}

	return true;
}

void Player::Draw() 
{
	if (sprite->GetIsActive())
		sprite->Draw();
}

void Player::SetPosition(float x, float y, float z)
{
	sprite->SetTranslation(x, y, z);
}

glm::vec3 Player::GetPosition()
{
	return glm::vec3(sprite->GetPosX(), sprite->GetPosY(), sprite->GetPosZ());
}

void Player::ToggleActive()
{
	isActive = !isActive;

	sprite->SetIsActive(isActive);
}
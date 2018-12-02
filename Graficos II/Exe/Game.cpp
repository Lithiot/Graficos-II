#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
}

bool Game::OnStart()
{	
	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite1 = new Sprite(rend, 8.0f, 2.0f, 14);
	sprite1->SetMaterial(mat3);
	sprite1->LoadTexture("megaman.bmp");
	sprite1->SetCollider(2.0f, 2.0f, player, false);
	CollisionManager::Instance()->RegisterEntity(sprite1);

	mat2 = new Material();
	programID = mat2->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite2 = new Sprite(rend, 1.0f, 1.0f, 1);
	sprite2->SetMaterial(mat2);
	sprite2->LoadTexture("uvtemplate.bmp");
	sprite2->SetCollider(2.0f, 2.0f, Enemy, true);
	CollisionManager::Instance()->RegisterEntity(sprite2);

	sprite1->SetTranslation(-5, 0, 0);
	sprite2->SetTranslation(0, 0, 0);


	std::cout << "Game::Start()" << std::endl;
	return true;
} 

bool Game::OnStop()
{
	std::cout << "Game::Stop()" << std::endl;
	return true;
}

bool Game::OnLoop()
{
	DeltaTime::Instance()->Update();

	sprite1->UpdateFrame();
	sprite2->UpdateFrame();

	sprite1->SetTranslation(sprite1->GetPosX() + 0.01f, 0.0f, 0.0f);

	CollisionManager::Instance()->CheckCollisions();
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	sprite1->Draw();
	sprite2->Draw();
	return true;
}
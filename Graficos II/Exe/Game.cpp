#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
	delete mat3;
	delete sprite1;
	DeltaTime::Instance()->DestroyInstance();
	CollisionManager::Instance()->DestroyInstance();
}

bool Game::OnStart()
{
	/*
	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite1 = new Sprite(rend, 8.0f, 2.0f, 14);
	sprite1->SetMaterial(mat3);
	sprite1->LoadTexture("megaman.bmp");
	sprite1->SetCollider(1.8f, 1.8f, player, false);
	CollisionManager::Instance()->RegisterEntity(sprite1);
	*/

	cube1 = new Cube(rend);

	cam = new Camera(rend);

	vel = 0.0f;

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

	//sprite1->UpdateFrame();

	//sprite1->SetTranslation(sprite1->GetPosX() + 0.01f, sprite1->GetPosY(), 0.0f);

	rend->SetProjectionPerspective(glm::radians(45.0f), 16.0f/4.0f, 0.0f, 100.0f);

	cam->Strafe(1.0f);

	CollisionManager::Instance()->CheckCollisions();
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	//sprite1->Draw();
	cube1->Draw();
	return true;
}
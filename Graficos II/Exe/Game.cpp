#include "Game.h"
#include "MeshImporter.h"

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

	MeshImporter* meshimp = new MeshImporter();

	mat3 = new Material();
	programID = mat3->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	cube1 = new Cube(rend);
	cube1->SetMaterial(mat3);

	cam = new Camera(rend);

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
	rend->SetProjectionPerspective(45.0f, 16.0f/4.0f, 0.1f, 1000.0f);
	cam->Walk(-1.0f);
	cube1->SetRotationY(cube1->GetRotationY() + 0.01f);

	CollisionManager::Instance()->CheckCollisions();
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	cube1->Draw();
	return true;
}
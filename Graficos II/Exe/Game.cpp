#include "Game.h"
#include "MeshImporter.h"

Game::Game()
{	
}

Game::~Game()
{
	delete mat1;
	DeltaTime::Instance()->DestroyInstance();
	CollisionManager::Instance()->DestroyInstance();
}

bool Game::OnStart()
{
	cam = new Camera(rend);
	

	mat1 = new Material();
	programID = mat1->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	mesh1 = new Mesh("rose.fbx", "rose_texture.bmp", rend);
	mesh1->SetMaterial(mat1);
	mesh1->SetTranslation(5.0f, 0.0f, 0.0f);

	mat2 = new Material();
	programID = mat2->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	mesh2 = new Mesh("Pikachu.obj", "pikachu_texture.bmp", rend);
	mesh2->SetMaterial(mat2);
	mesh2->SetScale(0.1f, 0.1f, 0.1f);

	rend->SetProjectionPerspective(45.0f, 16.0f / 4.0f, 0.1f, 1000.0f);

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
	cam->Walk(-1.0f);

	mesh2->SetRotationY(mesh2->GetRotationY() + 0.01f);

	mesh1->SetRotationY(mesh1->GetRotationY() + 0.01f);

	CollisionManager::Instance()->CheckCollisions();
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	mesh1->Draw();
	mesh2->Draw();
	return true;
}
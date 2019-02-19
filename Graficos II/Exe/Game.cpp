#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
	delete mat4;
	delete mat3;
	delete mat2;
	delete mat1;
	delete sprite1;
	delete sprite2;
	delete sprite3;
	delete triangle1;
	delete square1;
	delete circle1;
	DeltaTime::Instance()->DestroyInstance();
	CollisionManager::Instance()->DestroyInstance();
}

bool Game::OnStart()
{	
	
	mat1 = new Material();
	programID = mat1->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	square1 = new Square(rend);
	square1->SetMaterial(mat1);
	square1->SetCollider(2.0f, 2.0f, Entities, true);
	CollisionManager::Instance()->RegisterEntity(square1);

	mat2 = new Material();
	programID = mat2->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	circle1 = new Circle(rend);
	circle1->SetMaterial(mat2);
	circle1->SetCollider(2.0f, 2.0f, Entities, true);
	CollisionManager::Instance()->RegisterEntity(circle1);

	triangle1 = new Triangle(rend);
	triangle1->SetMaterial(mat1);
	triangle1->SetCollider(2.0f, 2.0f, Entities, true);
	CollisionManager::Instance()->RegisterEntity(triangle1);

	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite1 = new Sprite(rend, 8.0f, 2.0f, 14);
	sprite1->SetMaterial(mat3);
	sprite1->LoadTexture("megaman.bmp");
	sprite1->SetCollider(1.8f, 1.8f, player, false);
	CollisionManager::Instance()->RegisterEntity(sprite1);

	mat4 = new Material();
	programID = mat4->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite2 = new Sprite(rend, 1.0f, 1.0f, 1);
	sprite2->SetMaterial(mat4);
	sprite2->LoadTexture("uvtemplate.bmp");
	sprite2->SetCollider(2.0f, 2.0f, Enemy, false);
	CollisionManager::Instance()->RegisterEntity(sprite2);

	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite3 = new Sprite(rend, 8.0f, 2.0f, 14);
	sprite3->SetMaterial(mat3);
	sprite3->LoadTexture("megaman.bmp");
	sprite3->SetCollider(1.8f, 1.8f, Entities, false);
	CollisionManager::Instance()->RegisterEntity(sprite3);
	
	tileMat = new Material();
	programID = tileMat->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	tileMap = new Tilemap(rend, 10, 10, "mapaGraficos.csv", 9.0f, 5.0f);
	tileMap->SetMaterial(tileMat);
	tileMap->LoadTexture("Tileset.bmp");

	//tileMap->SetScale(1, 1, 0);
	cout << "Tilemap position is " << tileMap->GetPosX() << ", " << tileMap->GetPosY() << ", " << tileMap->GetPosZ() << endl;
	
	sprite1->SetTranslation(-5, 0, 0);
	sprite2->SetTranslation(0, 0, 0);
	sprite3->SetTranslation(0, 5, 0);
	triangle1->SetTranslation(-5, 5, 0);
	square1->SetTranslation(5, 5, 0);
	circle1->SetTranslation(-5, -5, 0);
	

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
	sprite3->UpdateFrame();

	sprite1->SetTranslation(sprite1->GetPosX() + 0.01f, sprite1->GetPosY(), 0.0f);
	sprite3->SetTranslation(sprite3->GetPosX(), sprite3->GetPosY() - 0.01f, 0.0f);
	
	CollisionManager::Instance()->CheckCollisions();
	
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	/*
	sprite1->Draw();
	sprite2->Draw();
	triangle1->Draw();
	circle1->Draw();
	square1->Draw();
	sprite3->Draw();
	*/

	tileMap->Draw();

	return true;
}
#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
}

bool Game::OnStart()
{
	//mat1 = new Material();
	//programID = mat1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	//triangle1 = new Triangle(rend);
	//triangle1->SetMaterial(mat1);
	
	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite1 = new Sprite(rend);
	sprite1->SetMaterial(mat3);
	sprite1->LoadTexture("meh.bmp");
	
	//mat2 = new Material();
	//programID = mat2->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	//square1 = new Square(rend);
	//square1->SetMaterial(mat2);

	//circle1 = new Circle(rend);
	//circle1->SetMaterial(mat1);
	

	//triangle1->SetTranslation(6, 0, 0);
	//square1->SetTranslation(3, 0, 0);
	//circle1->SetTranslation(0, 0, 0);
	sprite1->SetTranslation(0, 0, 0);
	//sprite1->SetRotationZ(3.0f);
	sprite1->SetScale(3, 3, 3);


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
	//triangle1->SetTranslation(5, 0, 0);
	//square1->SetTranslation(-5, 0, 0);
	//sprite1->SetRotationZ(sprite1->GetRotationZ() - 0.08);
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	//circle1->Draw();
	//triangle1->Draw();
	//square1->Draw();
	sprite1->Draw();
	return true;
}
#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
}

bool Game::OnStart()
{
	mat1 = new Material();
	mat2 = new Material();
	programID = mat1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	triangle1 = new Triangle(rend);
	triangle1->SetMaterial(mat1);
	circle1 = new Circle(rend);
	circle1->SetMaterial(mat1);
	programID = mat2->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	square1 = new Square(rend);
	square1->SetMaterial(mat2);
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
	triangle1->SetTranslation(5, 0, 0);
	square1->SetTranslation(-5, 0, 0);
	square1->SetRotationZ(square1->GetRotationZ() - 0.08);
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	circle1->Draw();
	triangle1->Draw();
	square1->Draw();
	return true;
}
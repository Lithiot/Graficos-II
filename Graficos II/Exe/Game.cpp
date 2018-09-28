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
	programID = mat1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	triangle1 = new Triangle(rend);
	triangle1->SetMaterial(mat1);
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
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	triangle1->Draw();
	return true;
}
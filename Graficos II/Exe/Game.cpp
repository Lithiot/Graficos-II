#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{

}

bool Game::OnStart()
{
	triangle1 = new Triangle(rend);
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
#include "Game.h"
Game::Game()
{
}
Game::~Game()
{
}
bool Game::OnStart()
{
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
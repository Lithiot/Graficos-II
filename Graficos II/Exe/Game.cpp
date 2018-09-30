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
	square1 = new Square(rend);
	square1->SetMaterial(mat1);
	square1->SetTranslation(-5, 0, 0);
	vel = 0.08f;
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
	glm::vec3 newTranslate = square1->GetTranslation();
	if (newTranslate[0] >= 10)
		vel *= -1;
	else if (newTranslate[0] <= -10)
		vel *= -1;
	square1->SetTranslation(newTranslate[0] + vel, 0, 0);
	square1->SetRotationZ(square1->GetRotationZ() - vel);
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	triangle1->Draw();
	square1->Draw();
	return true;
}
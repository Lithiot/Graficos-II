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
	
	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	square1 = new Square(rend);
	square1->SetMaterial(mat3);
	//circle1 = new Circle(rend);
	//circle1->SetMaterial(mat1);
	
	//mat2 = new Material();
	//programID = mat2->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");

	

	triangle1->SetTranslation(6, 0, 0);
	//square1->SetTranslation(3, 0, 0);
	circle1->SetTranslation(0, 0, 0);

	unsigned char i = TextureLoader::LoadBMP("uvtemplate.bmp");

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
	//circle1->Draw();
	//triangle1->Draw();
	//square1->Draw();
	return true;
}
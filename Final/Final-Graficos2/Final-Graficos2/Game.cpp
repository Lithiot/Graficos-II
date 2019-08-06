#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	DeltaTime::Instance()->DestroyInstance();
	CollisionManager::Instance()->DestroyInstance();
}

bool Game::OnStart()
{
	gameOver = win = lose = false;

	mat = new Material();
	programID = mat->LoadShaders("Texturevertexshader.txt", "Texturefragmentshader.txt");

	youWin = new Sprite(rend, 1.0f, 1.0f, 1);
	youWin->SetScale(5, 5, 5);
	youWin->SetMaterial(mat);
	youWin->LoadTexture("youWin.bmp");
	
	youLose = new Sprite(rend, 1.0f, 1.0f, 1);
	youLose->SetScale(5, 5, 5);
	youLose->SetMaterial(mat);
	youLose->LoadTexture("youLose.bmp");

	endTrigger = new Sprite(rend, 1.0f, 1.0f, 1);
	endTrigger->SetMaterial(mat);
	endTrigger->LoadTexture("noTexture.bmp");
	endTrigger->SetTranslation(86, -11, 0);
	endTrigger->SetCollider(1.8f, 1.8f, Entities, false, true);
	CollisionManager::Instance()->RegisterEntity(endTrigger);

	endTrigger->AddEvent(10, true, &gameOver);
	endTrigger->AddEvent(11, true, &win);

	// 86, -10

	player = new Player(rend, "megaman.bmp", 3.0f, 1.0f, 3);
	player->SetPosition(11, -11.7f, 0);

	for (int i = 0; i < CANT_COLECTABLES; i++)
	{
		Colectable* c = new Colectable(rend, "coin.bmp", 3.0f, 8.0f, 24, false, true);
		c->createPickUpEvent(i);
		colectables.push_back(c);
	}

	colectables.at(0)->SetPosition(20, -11.7f, 0);
	colectables.at(1)->SetPosition(25, -9.0f, 0);
	colectables.at(2)->SetPosition(36, -12.0f, 0);
	colectables.at(3)->SetPosition(50, -11.0f, 0);
	colectables.at(4)->SetPosition(64 , -9.0f, 0);

	tileMat = new Material();
	programID = tileMat->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	tileMap = new Tilemap(rend, 53, 12, "mapa.csv", 9.0f, 5.0f);
	tileMap->SetMaterial(tileMat);
	tileMap->LoadTexture("tileset.bmp");
	cout << "Tilemap position is " << tileMap->GetPosX() << ", " << tileMap->GetPosY() << ", " << tileMap->GetPosZ() << endl;

	tileMap->SetCollisionableTiles(0);
	tileMap->SetCollisionableTiles(11);
	tileMap->SetCollisionableTiles(30);
	tileMap->SetCollisionableTiles(32);
	tileMap->SetCollisionableTiles(33);
	tileMap->SetCollisionableTiles(35);
	tileMap->SetCollisionableTiles(36);

	tileMap->SetLastPositions(player->GetPosition().x, player->GetPosition().y);

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

	if (!player->Update(tileMap)) 
	{
		gameOver = true;
		lose = true;
	}
	
	youWin->SetTranslation(player->GetPosition().x, player->GetPosition().y, 0.0f);
	youLose->SetTranslation(player->GetPosition().x, player->GetPosition().y, 0.0f);

	for (int i = 0; i < colectables.size(); i++)
	{
		colectables.at(i)->Update();
	}

	tileMap->UpdateTilemap(player->GetPosition().x, player->GetPosition().y);

	CollisionManager::Instance()->CheckCollisions();

	rend->CameraFollow(glm::vec3(player->GetPosition().x, -11, 0.0f));

	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	tileMap->Draw();

	if (!gameOver)
	{
		player->Draw();

		endTrigger->Draw();

		for (int i = 0; i < colectables.size(); i++)
		{
			colectables.at(i)->Draw();
		}
	}
	else if (win)
		youWin->Draw();
	else if(lose)
		youLose->Draw();

	return true;
}
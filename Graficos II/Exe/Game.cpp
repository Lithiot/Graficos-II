#include "Game.h"

Game::Game()
{	
}

Game::~Game()
{
	delete mat3;
	delete sprite3;
	DeltaTime::Instance()->DestroyInstance();
	CollisionManager::Instance()->DestroyInstance();
}

bool Game::OnStart()
{
	sprite2ActiveState = true;
	vel = 2.0f;

	mat3 = new Material();
	programID = mat3->LoadShaders("texturevertexshader.txt", "texturefragmentshader.txt");
	sprite3 = new Sprite(rend, 8.0f, 2.0f, 14);
	sprite3->SetMaterial(mat3);
	sprite3->LoadTexture("megaman.bmp");
	sprite3->SetCollider(1.8f, 1.8f, player, false, false);
	CollisionManager::Instance()->RegisterEntity(sprite3);
	
	sprite2 = new Sprite(rend, 1.0f, 1.0f, 1.0f);
	sprite2->SetMaterial(mat3);
	sprite2->LoadTexture("uvtemplate.bmp");
	sprite2->SetCollider(1.8f, 1.8f, Entities, false, true);
	CollisionManager::Instance()->RegisterEntity(sprite2);

	sprite2->AddEvent(1, false, &sprite2ActiveState);

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

	sprite3->SetTranslation(11, -11.7f, 0);
	sprite2->SetTranslation(20, -11.7f, 0);
	tileMap->SetLastPositions(sprite3->GetPosX(), sprite3->GetPosY());

	InputManager::GetInstance()->SetWindow(rend->GetWindow());

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
	
	sprite3->UpdateFrame();

	if(!tileMap->IsNextTileCollisionable(sprite3->GetPosX(), sprite3->GetPosY(), 1.8f, RIGHT))
		sprite3->SetTranslation(sprite3->GetPosX() + vel * DeltaTime::Instance()->GetDeltaTime(), sprite3->GetPosY() , 0.0f);

	if (InputManager::GetInstance()->GetKeyDown(UpKey)) 
	{
		if (!tileMap->IsNextTileCollisionable(sprite3->GetPosX(), sprite3->GetPosY(), 1.8f, UP))
			sprite3->SetTranslation(sprite3->GetPosX(), sprite3->GetPosY() + 1.0f * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(DownKey))
	{
		if (!tileMap->IsNextTileCollisionable(sprite3->GetPosX(), sprite3->GetPosY(), 1.8f, DOWN))
			sprite3->SetTranslation(sprite3->GetPosX(), sprite3->GetPosY() - 1.0f * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}


	tileMap->UpdateTilemap(sprite3->GetPosX(), sprite3->GetPosY());

	CollisionManager::Instance()->CheckCollisions();

	rend->CameraFollow(glm::vec3(sprite3->GetPosX(), -11, 0.0f));
	
	sprite2->SetIsActive(sprite2ActiveState);

	std::cout << "Game::Loop()" <<  std::endl;
	return true;
}

bool Game::OnDraw()
{
	tileMap->Draw();
	sprite3->Draw();

	if (sprite2->GetIsActive())
		sprite2->Draw();

	return true;
}
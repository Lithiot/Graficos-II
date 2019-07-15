#include "Game.h"
#include "MeshImporter.h"

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
	cam = new Camera(rend);
	InputManager::GetInstance()->SetWindow(GetWindow());

	sceneNode = new Node("Scene Node", rend);

	sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("Rifle.fbx", "rifle_texture.bmp", rend));

	

	rend->SetProjectionPerspective(45.0f, 16.0f / 4.0f, 0.1f, 1000.0f);

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
	CollisionManager::Instance()->CheckCollisions();

	sceneNode->GetChildAtIndex(0)->GetTransform()->RotateY(5.0f * DeltaTime::Instance()->GetDeltaTime());
	sceneNode->GetChildAtIndex(0)->GetTransform()->Move(0, 0, -10.0f * DeltaTime::Instance()->GetDeltaTime());
	

	if (InputManager::GetInstance()->GetKeyDown(DownKey))
	{
		cam->Walk(-1000.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(UpKey))
	{
		cam->Walk(1000.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(LeftKey))
	{
		cam->Strafe(-1000.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(RightKey))
	{
		cam->Strafe(1000.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(AKey))
	{
		cam->Roll(10.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(DKey))
	{
		cam->Roll(-10.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(WKey))
	{
		cam->Pitch(10.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(SKey))
	{
		cam->Pitch(-10.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(QKey))
	{
		cam->Yaw(10.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(EKey))
	{
		cam->Yaw(-10.0F * DeltaTime::Instance()->GetDeltaTime());
	}

	
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	sceneNode->Draw();
	return true;
}
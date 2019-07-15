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
	InputManager::GetInstance()->SetWindow(GetWindow());

	nodeForCamera = new Node("Node for Camera", rend);
	sceneNode->AddChild(nodeForCamera);
	cam = new Camera(rend);
	nodeForCamera->AddComponent(cam);

	sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("Rifle.fbx", "Rifle_texture.bmp", rend));
	
	sceneNode->GetChildAtIndex(1)->GetTransform()->Move(0.0f, 0.0f, 70.0f);

	rend->SetProjectionPerspective(45.0f, 2.4f, 0.1f, 100000.0f);
	
	sceneNode->GetChildAtIndex(1)->GetChildAtIndex(1)->GetTransform()->Move(0.0f, -20.0f, 0.0f);

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

	sceneNode->GetChildAtIndex(1)->GetTransform()->RotateY(1.0f * DeltaTime::Instance()->GetDeltaTime());
	sceneNode->GetChildAtIndex(1)->GetChildAtIndex(1)->GetTransform()->RotateY(-3.0f * DeltaTime::Instance()->GetDeltaTime());
	
	

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
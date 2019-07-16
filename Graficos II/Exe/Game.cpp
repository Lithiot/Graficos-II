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

	sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("Rifle.fbx", "Rifle_texture.bmp", rend, cam));
	//sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("rose.fbx", "rose_texture.bmp", rend));
	
	sceneNode->GetChildAtIndex(1)->Move(0.0f, 0.0f, 70.0f);
	
	sceneNode->GetChildAtIndex(1)->GetChildAtIndex(1)->Move(0.0f, -20.0f, 0.0f);

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

	sceneNode->GetChildAtIndex(1)->RotateY(1.0f * DeltaTime::Instance()->GetDeltaTime());
	sceneNode->GetChildAtIndex(1)->GetChildAtIndex(1)->RotateZ(-3.0f * DeltaTime::Instance()->GetDeltaTime());
	

	if (InputManager::GetInstance()->GetKeyDown(DownKey))
	{
		nodeForCamera->Move(0.0f, 0.0f, -100 * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(UpKey))
	{
		nodeForCamera->Move(0.0f, 0.0f, 100 * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(LeftKey))
	{
		nodeForCamera->Move(100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f, 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(RightKey))
	{
		nodeForCamera->Move(-100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f, 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(AKey))
	{
		nodeForCamera->RotateX(20.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(DKey))
	{
		nodeForCamera->RotateX(-20.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(WKey))
	{
		nodeForCamera->RotateY(-20.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(SKey))
	{
		nodeForCamera->RotateY(20.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(QKey))
	{
		nodeForCamera->RotateZ(20.0F * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(EKey))
	{
		nodeForCamera->RotateZ(-20.0F * DeltaTime::Instance()->GetDeltaTime());
	}

	
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	sceneNode->Draw();
	return true;
}
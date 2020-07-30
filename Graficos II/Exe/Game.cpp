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

	sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("Scene.fbx", "rifle_texture.bmp", rend, cam));
	//sceneNode->AddChild(MeshLoader::GetInstance()->LoadMesh("myRifle.fbx", "rifle_texture.bmp", rend, cam));

	nodeForCamera->Move(0.0f, 0.0f, -100.0f);
	
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
		//nodeForCamera->RotateX(5.0f * DeltaTime::Instance()->GetDeltaTime());
		sceneNode->GetChildAtIndex(1)->GetChildAtIndex(0)->GetChildAtIndex(0)->Move(100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f, 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(DKey))
	{
		//nodeForCamera->RotateX(-5.0f * DeltaTime::Instance()->GetDeltaTime());
		sceneNode->GetChildAtIndex(1)->GetChildAtIndex(0)->GetChildAtIndex(0)->Move(-100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f, 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(WKey))
	{
		//nodeForCamera->RotateY(-5.0F * DeltaTime::Instance()->GetDeltaTime());
		sceneNode->GetChildAtIndex(1)->GetChildAtIndex(0)->GetChildAtIndex(0)->Move(0.0f, 100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(SKey))
	{
		//nodeForCamera->RotateY(5.0F * DeltaTime::Instance()->GetDeltaTime());
		sceneNode->GetChildAtIndex(1)->GetChildAtIndex(0)->GetChildAtIndex(0)->Move(0.0f, -100 * DeltaTime::Instance()->GetDeltaTime(), 0.0f);
	}
	else if (InputManager::GetInstance()->GetKeyDown(QKey))
	{
		nodeForCamera->RotateZ(5.0f * DeltaTime::Instance()->GetDeltaTime());
	}
	else if (InputManager::GetInstance()->GetKeyDown(EKey))
	{
		nodeForCamera->RotateZ(-5.0f * DeltaTime::Instance()->GetDeltaTime());
	}

	
	std::cout << "Game::Loop()" << std::endl;
	return true;
}

bool Game::OnDraw()
{
	sceneNode->Draw();

	std::cout << "Meshes Drawn: " << DeltaTime::Instance()->GetMeshDrawn() << endl;
	DeltaTime::Instance()->SetMeshDrawn(0);

	return true;
}
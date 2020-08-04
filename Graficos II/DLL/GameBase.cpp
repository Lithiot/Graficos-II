#include "GameBase.h"
#include "TextureLoader.h"

GameBase::GameBase() :wind(new Window()), rend(new Renderer()), quit(false)
{
}

GameBase::~GameBase()
{
	delete wind;
	delete rend;
}

bool GameBase::Start()
{
	if (!wind->Start(800, 600, "Prueva"))
		return false;
	if (!rend->Start(wind))
		return false;

	sceneNode = new Node("SceneNode", rend);

	rend->SetClearColor(0, 0, 1, 1);

	return OnStart();
}

bool GameBase::Stop()
{
	OnStop();
	rend->Stop();
	wind->Stop();
	return true;
}

void GameBase::loop() 
{
	do
	{
		quit = OnLoop();
		rend->ClearWindow();
		sceneNode->Update();
		OnDraw();
		rend->SwapBuffer();
		wind->PollEvents();
	} while (!wind->ShouldClose() && quit);
}

Window* GameBase::GetWindow() 
{
	return wind;
}

void GameBase::PrintNodeChilds(Node* node, int offset)
{
	if (offset != 0) 
	{
		for (int j = 0; j < offset; j++)
		{
			cout << " ";
		}

		cout << "|_ ";
	}

	cout << node->GetName() << endl;

	if (!node->GetChildsVector()) return;

	for (int i = 0; i < node->GetChildsVector()->size(); i++)
	{
		PrintNodeChilds(node->GetChildAtIndex(i), offset + 1);
	}
}
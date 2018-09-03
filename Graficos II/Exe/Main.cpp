#include <iostream>
#include "Game.h"
using namespace std;
void main()
{
	GameBase* game = new Game();
	if (game->Start())
	{
		game->loop();
	}
	game->Stop();
	delete game;
	cin.get();
}
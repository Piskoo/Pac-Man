#define _CRTDBG_MAP_ALLOC
#include "Game.h"
#include <cstdlib>
#include <crtdbg.h>



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//int* test = new int(5);
	Game game;
	game.run();
	return 0;
}
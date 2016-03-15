
#include "Game.h"
#include <time.h>
#include <stdlib.h>

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{

	srand((int)time(NULL));

	// create Game
	Game *pGame = new Game();    
	assert(pGame);

	// start the game
	pGame->run();                                  

	delete pGame;
	return 0;                                       
}


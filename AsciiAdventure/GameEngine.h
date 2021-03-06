/*

	The main logic for running our game is housed here.

	Use it as a central hub for calling functions.

*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H



/* Debugging purposes */
#include<iostream>
#include<curses.h>
#include<vector>

#include "Map.h"
#include "Player.h"
#include "MakeColors.h"
#include "Bear.h"
#include "ActorFactory.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void gameLoop();
	void gameInit();

	int getHeight();
	int getWidth();

private:
	const int MAP_WIDTH = 80, MAP_HEIGHT = 25, MAP_DEPTH= 1; /* The size of the map that we will play on */
	const int SCREEN_WIDTH = 80, SCREEN_HEIGHT = 25;

	
	ActorFactory factory;
	Player hero; /* The default hero for our game! */
	WINDOW* gameWin;
	
	bool mainLoop; /* The main loop for our game */

	/* For rendering da game */
	int getScrollX();
	int getScrollY();

	void getInput(Map& gameMap, char input); /* Will decide what to do based on the users input */
};


#endif 
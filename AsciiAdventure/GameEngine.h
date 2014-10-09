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

class GameEngine
{
public:

	

	GameEngine(int gameHeight, int gameWidth);
	~GameEngine();

	void gameLoop();
	void gameInit();

	int getHeight();
	int getWidth();

private:
	const int MAP_WIDTH = 160, MAP_HEIGHT = 50; /* The size of the map that we will play on */
	const int SCREEN_WIDTH = 80, SCREEN_HEIGHT = 25;

	Player hero; /* The default hero for our game! */

	WINDOW* gameWin;
	WINDOW* playerHUD;
	
	
	bool mainLoop; /* The main loop for our game */

	/* For rendering da game */
	int getScrollX();
	int getScrollY();

	void getInput(Map map, char input); /* Will decide what to do based on the users input */
};


#endif 
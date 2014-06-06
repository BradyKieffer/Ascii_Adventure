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
#include"Screen.h"
#include"Player.h"

// Used to display a certain tile type depending on the
// given value in the map!
enum Tiles
{
	TILE_FLOOR = 0,
	TILE_WALL = 1,
	TILE_TREE = 2
};

enum ColPairNums
{
	COL_PLAYER = 100,
	COL_TREE = 101
};

class GameEngine
{
public:
	GameEngine(int gameHeight, int gameWidth);
	~GameEngine();

	void gameLoop();
	void gameInit();

private:
	Player hero; /* The default hero for our game! */
	Screen gameScreen;
	std::vector<std::vector<int>> gameMap;
	bool mainLoop; /* The main loop for our game */


	const int MAP_WIDTH = 80, MAP_HEIGHT = 25; /* The size of the map that we will play on */

	void displayMap();
	void getInput(char input); /* Will decide what to do based on the users input */
	void moveChar(int deltaY, int deltaX); /* Add in the deltaX and deltaY and this function will add them to a char's 
											  coordinates and ensure they are within bounds!!						  */

	void colorPairs();
};

#endif 
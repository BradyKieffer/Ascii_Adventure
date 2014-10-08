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

struct TileType
{
	chtype symbol;
	short colCode;
	bool isPassable;
};

class GameEngine
{
public:

	/* Tile types so that the code is easier to read */
	enum TileTypes
	{
		TILE_ROCK_FLOOR = 0,
		TILE_TREE = 1,
		TILE_WALL = 2
	};

	GameEngine(int gameHeight, int gameWidth);
	~GameEngine();

	void gameLoop();
	void gameInit();

	int getHeight();
	int getWidth();

private:
	Player hero; /* The default hero for our game! */
	
	std::vector<Bear> enemies;

	WINDOW* gameWin;
	WINDOW* playerHUD;
	
	std::vector<std::vector<int>> gameMap;
	std::vector<TileType> tileIndex;
	bool mainLoop; /* The main loop for our game */

	
	const int MAP_WIDTH = 80, MAP_HEIGHT = 25; /* The size of the map that we will play on */
	
	const int NUM_ENEMIES = 10; /* How many enemies will spawn */

	void displayMap();
	void getInput(char input); /* Will decide what to do based on the users input */
	void moveChar(int deltaY, int deltaX); /* Add in the deltaX and deltaY and this function will add them to a char's 
											  coordinates and ensure they are within bounds!!						  */
	void initTiles();
	void setPlayerCoords();

	void renderEnemies(); /* Takes are enemies array and renders the enemies based on their location */
	void makeEnemies(); /* Creates our enemies HAHA */
};


#endif 
/*

	The main logic for running our game is housed here.

	Use it as a central hub for calling functions.

*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include<curses.h>
#include<vector>
#include "Map.h"
#include"Screen.h"

// Used to display a certain tile type depending on the
// given value in the map!
enum Tiles
{
	TILE_FLOOR = 0,
	TILE_WALL = 1,
	TILE_TREE = 2
};


class GameEngine
{
public:
	GameEngine(int gameHeight, int gameWidth);
	~GameEngine();

	void gameLoop();
	void gameInit();

private:
	Screen gameScreen;
	std::vector<std::vector<int>> gameMap;
	void displayMap();
};

#endif 
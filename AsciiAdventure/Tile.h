/*
	
	Stores all tile related data here.
	That way when we wish to adda new tile 
	I don't have to change ALL the lines. 

*/

#ifndef TILE_H
#define TILE_H

#include <vector>
#include "curses.h"
#include "MakeColors.h"

struct TileType
{
	chtype symbol;
	short colCode;
	bool isPassable;
	int tileNum;
};

class Tile
{
public:
	Tile();
	~Tile();

	/* Tile types so that the code is easier to read */
	enum TileTypes
	{
		TILE_BOUNDS = 0,
		TILE_ROCK_FLOOR = 1,
		TILE_TREE = 2,
		TILE_WALL = 3,
	};

	std::vector<TileType> tileIndex;

	void makeTile(chtype symbol, short colCode, bool isPassable, int tileNum);

private:
	void initTiles();
};

#endif


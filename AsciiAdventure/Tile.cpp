#include "Tile.h"


Tile::Tile()
{
	initTiles();
}


Tile::~Tile()
{	/* Default Destructor */	}

void Tile::initTiles()
{
	/*
	Enters the tile values to the vector for the tile index

	The index will be the tile type

	Values are stored by symbol, color number and if the tile is passable
	*/

	/* Boundary Tiles */
	makeTile(' ' | A_DIM, MakeColors::COL_BOUNDS, false, TILE_BOUNDS);

	/* Rock floor */
	//tileIndex[TILE_ROCK_FLOOR] = { '.', MakeColors::COL_ROCK_FLOOR, true };
	makeTile('.', MakeColors::COL_ROCK_FLOOR, true, TILE_ROCK_FLOOR);

	/* Tree */
	//tileIndex[TILE_TREE] = { 'T', MakeColors::COL_TREE, false };
	makeTile('T', MakeColors::COL_TREE, false, TILE_TREE);

	/* Wall */
	//tileIndex[TILE_WALL] = { '#', MakeColors::COL_WALL, false };
	makeTile('#', MakeColors::COL_WALL, false, TILE_WALL);
}

void Tile::makeTile(chtype symbol, short colCode, bool isPassable, int tileNum)
{
	tileIndex.push_back({ symbol, colCode, isPassable, tileNum });
}
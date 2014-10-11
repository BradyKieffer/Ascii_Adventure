#include "PlayerAi.h"
#include <iostream>

PlayerAi::PlayerAi()
{
}


PlayerAi::~PlayerAi()
{
}

void PlayerAi::onEnter(int& z, int& y, int& x, int deltaZ, int deltaY, int deltaX, Map& map)
{

	if (z + deltaZ < 0 || z + deltaZ > map.getMapDepth() - 1)
	{
		/* If we are here then don't add to the depth */
		deltaZ = 0;
	}

	if (y + deltaY < 0 || y + deltaY > map.getMapHeight() - 1)
	{
		/* If we are here then don't add to the height */
		deltaY = 0;
	}


	if (x + deltaX < 0 || x + deltaX > map.getMapWidth() - 1)
	{
		/* If we are here then don't add to the width */

		deltaX = 0;
	}
	
	int tileType = map.getMap()[z + deltaZ][y + deltaY][x + deltaX];

	if (map.tile.isPassable(tileType))
	{
		z += deltaZ;
		y += deltaY;
		x += deltaX;

	}
	else if (tileType == Tile::TILE_WALL)
	{
		dig(z + deltaZ, y + deltaY, x + deltaX, map);
	}
}

void PlayerAi::dig(int z,int y, int x, Map& map)
{
	std::vector<std::vector<std::vector<int>>> tmp = map.getMap();
	tmp[z][y][x] = Tile::TILE_ROCK_FLOOR;
	map.setMap(tmp);
}
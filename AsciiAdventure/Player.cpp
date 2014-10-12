#include "Player.h"


Player::Player() : Actor()
{ /* Default Constructor */ }

Player::~Player()
{ /* Default Destructor */ }

void Player::onMove(Map& map, int deltaZ, int deltaY, int deltaX)
{
	int actZ = getZPos();
	int actY = getYPos();
	int actX = getXPos();

	if (actZ + deltaZ < 0 || actZ + deltaZ > map.getMapDepth() - 1)
	{
		/* If we are here then don't add to the depth */
		deltaZ = 0;
	}

	if (actY + deltaY < 0 || actY + deltaY > map.getMapHeight() - 1)
	{
		/* If we are here then don't add to the height */
		deltaY = 0;
	}


	if (actX + deltaX < 0 || actX + deltaX > map.getMapWidth() - 1)
	{
		/* If we are here then don't add to the width */

		deltaX = 0;
	}

	int tileType = map.getMap()[actZ + deltaZ][actY + deltaY][actX + deltaX];
	if (map.tile.isPassable(tileType))
	{
		setZPos(actZ + deltaZ);
		setYPos(actY + deltaY);
		setXPos(actX + deltaX);
	}
	else if (tileType == Tile::TILE_WALL)
	{
		dig(actZ + deltaZ, actY + deltaY, actX + deltaX, map);
	}
}


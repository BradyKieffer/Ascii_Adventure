#include "Bear.h"


Bear::Bear()
{
	rageTurns = rand() % 10 + 1;
}

Bear::~Bear()
{ /* Default Destructor */ }

void Bear::onUpdate(Map& map)
{
	if (isLiving())
	{
		onMove(map);
		rage();
	}
}

void Bear::onMove(Map& map)
{
	/* This will look for the player, if found it will move toward the player.
	   If not the bear will wander in a random direction */
	lookForPlayer(map);
}

void Bear::lookForPlayer(Map& map)
{
	bool isPlayerFound = false;
	for (int i = -1 * FOV; i < FOV + 1; ++i)
	{
		for (int j = -1 * FOV; j < FOV + 1; ++j)
		{
			if (i < 0 || i > map.getMapHeight() ||
				j < 0 || j > map.getMapWidth() ||
				map.getMap()[getZPos()][i][j] == Tile::TILE_WALL)
			{
				/* This set of variables is beyond our view
				or there is a wall obstructing the view
				so break out of the loop */
				break;
			}
			else
			{

			}
		}
	}
	
	if (isPlayerFound == true)
	{

	}
	else
	{
		wander(map);
	}
}

void Bear::wander(Map& map)
{
	int actZ = getZPos();
	int actY = getYPos();
	int actX = getXPos();

	int deltaZ = 0;
	int deltaY = rand() % 3 - 1;
	int deltaX = rand() % 3 - 1;

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

void Bear::rage()
{
	if (rand() % 100 < 5 || isRage == true)
	{
		setSymbol(getChar() | A_BLINK | COLOR_PAIR(MakeColors::COL_RAGE));
		if (rageTurns > 0)
		{
			--rageTurns;
			isRage = true;
		}
		else
		{
			isRage = false;
			rageTurns = rand() % 10 + 1;
		}
	}
	else
	{
		setSymbol(getChar() | COLOR_PAIR(MakeColors::COL_BEAR));
	}
}
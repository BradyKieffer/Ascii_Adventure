#include "Actor.h"

Actor::Actor()
{ /* Default Constructor */ }

Actor::Actor(int zPos, int yPos, int xPos, chtype symbol) : Object(zPos, yPos, xPos, symbol)
{
	/* Need to add HP next :) */
	setHp(100); // Just for some debugging :).
	isAlive = true;
}
	
Actor::~Actor()
{ /* Default Destructor */ }


bool Actor::isLiving()
{
	/* Let's us know if the actor is 'dead' */
	return isAlive;
}

Actor& Actor::operator=(const Actor& rhs)
{
	swap(rhs);
	return *this;
}

void Actor::swap(Actor rhs)
{
	setSymbol(rhs.getSymbol());
	
	setXPos(rhs.getXPos());
	setYPos(rhs.getYPos());
	setZPos(rhs.getZPos());

	setHp(rhs.getHp());
	setDef(rhs.getDef());
	setStr(rhs.getStr());
}

/* Setters */
void Actor::setHp(int hp){ hitPoints = hp; }
void Actor::setStr(float str){ strength = str; }
void Actor::setDef(float def){ defense = def; }

/* Getters */
int Actor::getHp(){ return hitPoints; }
int Actor::getStr(){ return strength; }
int Actor::getDef(){ return defense;  }

void Actor::modifyHP(int damage)
{
	if (isAlive == true)
	{
		setHp(getHp() - damage);
		if (getHp() <= 0 )
		{
			die();
		}
	}
}

void Actor::onUpdate(Map map)
{
	onMove(map);
}

void Actor::setCoords(Map map)
{
	/* For now just set the actor to the first found walkable tile */
	int z = rand() % map.getMapDepth();
	int y = rand() % map.getMapHeight();
	int x = rand() % map.getMapWidth();
	while (map.getMap()[z][y][x] == Tile::TILE_WALL)
	{
		z = rand() % map.getMapDepth();
		y = rand() % map.getMapHeight();
		x = rand() % map.getMapWidth();
	}

	setZPos(z);
	setYPos(y);
	setXPos(x);
}

void Actor::onMove(Map map)
{
	int actZ = getZPos();
	int actY = getYPos();
	int actX = getXPos();

	int deltaZ = 0;
	int deltaY = rand() % 1 - 2;
	int deltaX = rand() % 1 - 2;

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

void Actor::die()
{ 
	setSymbol('X' | A_DIM | COLOR_PAIR(MakeColors::COL_DEAD));
	isAlive = false;
}

void Actor::dig(int z, int y, int x, Map& map)
{
	std::vector<std::vector<std::vector<int>>> tmp = map.getMap();
	tmp[z][y][x] = Tile::TILE_ROCK_FLOOR;
	map.setMap(tmp);
}
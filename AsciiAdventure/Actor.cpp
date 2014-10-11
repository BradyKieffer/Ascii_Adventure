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

void Actor::setCoords(Map map)
{
	/* For now just set the player to the first found walkable tile */
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

void Actor::die()
{ 

	setSymbol('X' | A_DIM | COLOR_PAIR(MakeColors::COL_DEAD));
	isAlive = false;
}
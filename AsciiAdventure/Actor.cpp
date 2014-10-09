#include "Actor.h"

Actor::Actor()
{ /* Default Constructor */ }

Actor::Actor(int yPos, int xPos, chtype symbol) : Object(yPos, xPos, symbol)
{
	/* Need to add HP next :) */
	setHp(100); // Just for some debugging :).
	isAlive = true;
}
	
Actor::~Actor()
{ /* Default Destructor */ }

/* Setters */
void Actor::setHp(int hp)
{
	hitPoints = hp;
}

bool Actor::isLiving()
{
	/* Let's us know if the actor is 'dead' */
	return isAlive;
}

void Actor::setStr(float str)
{
	if (str > 0)
	{
		strength = str;
	}
	else
	{
		strength = 1.0;
	}
}


void Actor::setDef(float def)
{
	if (def > 0)
	{
		defense = def;
	}
	else
	{
		defense = 1.0;
	}
}

/* Getters */
int Actor::getHp()
{
	return hitPoints;
}

float Actor::getStr()
{
	return strength;
}

float Actor::getDef()
{
	return defense;
}

void Actor::takeDamage(int damage)
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


void Actor::onMove(Map map,int deltaY, int deltaX)
{
	int actY = getYPos();
	int actX = getXPos();
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
	int tile = map.getMap()[actY + deltaY][actX + deltaX];
	if (map.tile.tileIndex[tile].isPassable == true)
	{
		/* We are moving onto a floor tile! yay! */
		/* Add the results to the heroes coordinates */
		setYPos(actY + deltaY);
		setXPos(actX + deltaX);
	}
}

void Actor::setCoords(Map map)
{
	/* For now just set the player to the first found walkable tile */
	for (int i = 0; i < map.getScreenHeight(); i++)
	{
		for (int j = 0; j < map.getScreenWidth(); j++)
		{
			if (map.tile.tileIndex[map.getMap()[i][j]].isPassable == true)
			{
				/* We found our spot yay! */
				setYPos(i);
				setXPos(j);
				break;
			}
		}
	}
}
void Actor::die()
{ 

	setSymbol('X' | A_DIM | COLOR_PAIR(MakeColors::COL_DEAD));
	isAlive = false;
}
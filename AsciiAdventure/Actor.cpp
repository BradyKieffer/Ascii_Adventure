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

void Actor::setSpeed(float spd)
{
	if (speed > 0)
	{
		speed = spd;
	}
	else
	{
		speed = 1.0;
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
float Actor::getSpeed()
{
	return speed;
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

void Actor::die()
{ 

	setSymbol('X' | A_DIM | COLOR_PAIR(MakeColors::COL_DEAD));
	isAlive = false;
}
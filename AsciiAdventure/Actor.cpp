#include "Actor.h"

Actor::Actor()
{ /* Default Constructor */ }

Actor::Actor(int yPos, int xPos, chtype symbol, int colour) : Object(yPos, xPos, symbol, colour)
{
	/* Need to add HP next :) */
}
	
Actor::~Actor()
{ /* Default Destructor */ }

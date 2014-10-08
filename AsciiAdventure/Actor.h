/*

	A generic class that handles a more 
	defined presence for an actor object

*/

#ifndef ACTOR_H
#define ACTOR_H

#include"Object.h"

class Actor : 
	public Object
{
public:

	Actor();
	Actor(int yPos, int xPos, chtype symbol, int colour);
	~Actor();
};

#endif

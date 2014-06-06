/*

	The class that will handle our hero!

*/
#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
class Player :
	public Object
{
public:
	Player();
	Player(int yPos, int xPos);
	~Player();
};

#endif
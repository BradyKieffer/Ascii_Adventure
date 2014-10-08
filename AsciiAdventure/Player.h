/*

	The class that will handle our hero!

*/
#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"

class Player :
	public Actor
{
public:
	Player();
	Player(int xPos, int yPos);
	~Player();
};

#endif
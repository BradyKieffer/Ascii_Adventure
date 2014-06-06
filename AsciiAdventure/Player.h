
#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
class Player :
	public Object
{
public:
	Player(int yPos, int xPos);
	~Player();
};

#endif
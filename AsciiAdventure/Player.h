/*

	The class that will handle our hero!

*/
#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "PlayerAi.h"
class Player :
	public Actor
{
public:
	Player();
	Player(int xPos, int yPos);
	~Player();
	void onMove(Map& map, int deltaY, int deltaX);

private:
	PlayerAi ai;
};

#endif
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
	~Player();
	void onMove(Map& map, int deltaZ,int deltaY, int deltaX);
	

};

#endif
#include "Player.h"


Player::Player()
{ /* Default Constructor */ }

Player::Player(int zPos, int yPos, int xPos) : Actor(zPos, yPos, xPos,'@' | COLOR_PAIR(MakeColors::COL_PLAYER) | A_BOLD)
{
	/* Will add stuff in here like hp.... etc*/	
}

Player::~Player()
{ /* Default Destructor */ }

void Player::onMove(Map& map, int deltaZ, int deltaY, int deltaX)
{
	int actY = getYPos();
	int actX = getXPos();
	int actZ = getZPos();

	ai.onEnter(actZ,actY, actX, deltaZ, deltaY, deltaX, map);
	
	setZPos(actZ);
	setYPos(actY);
	setXPos(actX);
}
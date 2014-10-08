#include "Player.h"


Player::Player()
{ /* Default Constructor */ }

Player::Player(int yPos, int xPos) : Actor(yPos, xPos,'@' | COLOR_PAIR(MakeColors::COL_PLAYER) | A_BOLD)
{
	/* Will add stuff in here like hp.... etc*/	
}

Player::~Player()
{ /* Default Destructor */ }

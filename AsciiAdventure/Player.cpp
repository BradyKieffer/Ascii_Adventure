#include "Player.h"


Player::Player()
{ /* Default Constructor */ }

Player::Player(int yPos, int xPos) : Actor(yPos, xPos,'@' | COLOR_PAIR(100) | A_BOLD, 0)
{
	/* Will add stuff in here like hp.... etc*/	
}

Player::~Player()
{ /* Default Destructor */ }

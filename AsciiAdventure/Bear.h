/*
	
	This will be the first "enemy! Yay!"
	
	A ferocious bear that will nom on anything it wants to nom on!
*/
#ifndef BEAR_H
#define BEAR_H

#include"Actor.h"

class Bear :
	public Actor
{
public:
	Bear();
	Bear(int yPos, int xPos);
	~Bear();

};

#endif

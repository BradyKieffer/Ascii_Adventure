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
	~Bear();

	void onUpdate(Map& map);

	void onMove(Map& map);
	void wander(Map& map);

private:
	const int FOV = 5; /* How many tiles the bears can 'see' */
	
	int rageTurns;
	bool isRage;

	void lookForPlayer(Map& map);
	void rage(); /* The bears special ability makes them rage */
};


#endif

/*
	
	We will use this to spit out new Actor objects :)
	Note that we only want to set the map through this, 
	not actually change anything.

*/

#ifndef ACTOR_FACTORY_H
#define ACTOR_FACTORY_H

#include <vector>
#include "curses.h"
#include "Actor.h"
#include "Map.h"
#include "Bear.h"

class ActorFactory
{
public:
	ActorFactory();
	~ActorFactory();


	std::vector<Actor> getActorList();

	 void makeBears(int numBears, Map map);

	 void spawnEnemies(Map map);
	 void displayEnemies(WINDOW* gameWin, Map map, int top, int left, int currDepth);
	 void updateEnemies(Map& map);

	 void deleteList();

private:
	const int NUM_BEARS = 10;

	std::vector<Actor> actors;

	void newBear(Map map);
};

#endif
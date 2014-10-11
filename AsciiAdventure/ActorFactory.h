/*
	
	We will use this to spit out new Actor objects :)
	Note that we only want to set the map through this, 
	not actually change anything.

*/

#ifndef ACTOR_FACTORY_H
#define ACTOR_FACTORY_H

#include <list>
#include "Actor.h"
#include "Map.h"

class ActorFactory
{
public:
	ActorFactory(Map gameMap);
	~ActorFactory();

	void setMap(Map gameMap); 

private:
	std::list<Actor> actors;
	Map map;
};

#endif
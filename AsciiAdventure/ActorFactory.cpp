#include "ActorFactory.h"
#include <iostream>


ActorFactory::ActorFactory(){}

ActorFactory::~ActorFactory()
{
}


std::vector<Actor> ActorFactory::getActorList()
{
	return actors;
}

void ActorFactory::newBear(Map map)
{
	Bear bear;
	bear.setCoords(map);
	actors.resize(actors.size() + 1);
	actors[actors.size() - 1] = bear;
}

void ActorFactory::makeBears(int numBears, Map map)
{
	while (numBears > 0)
	{
		newBear(map);
		--numBears;
	}
}

/* For now this only makes one enemy but it will eventually make more */
void ActorFactory::spawnEnemies(Map map)
{
	makeBears(NUM_BEARS, map);
}

void ActorFactory::displayEnemies(WINDOW* gameWin,Map map, int top, int left, int currDepth)
{
	for (int currActor = 0; currActor < actors.size(); ++currActor)
	{
		
		int actX = actors[currActor].getXPos() - left;
		int actY = actors[currActor].getYPos() - top;
		int actZ = actors[currActor].getZPos();

		if (actX < 0 || actX > map.getScreenWidth()  ||
			actY < 0 || actY > map.getScreenHeight() ||
			actZ != currDepth)
		{
			/* Actor is off screen so ignore it */
		}
		else
		{
			chtype glyph = actors[currActor].getSymbol();
			/* On screen so draw it */
			mvwaddch(gameWin, actY, actX, glyph);
		}

	}
}

void ActorFactory::updateEnemies(Map map)
{
	for (int i = 0; i < actors.size(); ++i)
	{
		Actor actor = actors[i];
		actor.onUpdate(map);
	}
}
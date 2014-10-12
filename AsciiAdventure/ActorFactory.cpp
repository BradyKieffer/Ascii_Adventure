#include "ActorFactory.h"
#include <iostream>


ActorFactory::ActorFactory()
{}

ActorFactory::~ActorFactory()
{
	bears.resize(0);
}

/* For now this only makes one enemy but it will eventually make more */
void ActorFactory::displayEnemies(WINDOW* gameWin,Map map, int top, int left, int currDepth)
{
	/* Bears */
	displayBears(gameWin, map, top, left, currDepth);
}

void ActorFactory::updateEnemies(Map& map)
{
	/* Bears */
	updateBears(map);
}

void ActorFactory::spawnEnemies(Map map)
{
	/* Bears */
	makeBears(NUM_BEARS, map);
}

void ActorFactory::newBear(Map map)
{
	Bear bear;
	bear.setCoords(map);
	bear.setChar('B');
	bear.setSymbol('B' | COLOR_PAIR(MakeColors::COL_BEAR));
	bears.push_back(bear);
}

void ActorFactory::makeBears(int numBears, Map map)
{
	while (numBears > 0)
	{
		newBear(map);
		--numBears;
	}
}

void ActorFactory::displayBears(WINDOW* gameWin, Map map, int top, int left, int currDepth)
{
	for (int currActor = 0; currActor < bears.size(); ++currActor)
	{

		int actX = bears[currActor].getXPos() - left;
		int actY = bears[currActor].getYPos() - top;
		int actZ = bears[currActor].getZPos();

		if (actX < 0 || actX > map.getScreenWidth() ||
			actY < 0 || actY > map.getScreenHeight() ||
			actZ != currDepth)
		{
			/* Actor is off screen so ignore it */
		}
		else
		{
			chtype glyph = bears[currActor].getSymbol();
			/* On screen so draw it */
			mvwaddch(gameWin, actY, actX, glyph);
		}

	}
}

void ActorFactory::updateBears(Map& map)
{
	for (int i = 0; i < bears.size(); ++i)
	{
		bears[i].onUpdate(map);
	}
}
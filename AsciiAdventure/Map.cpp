#include "Map.h"



Map::Map(int height, int width)
{
	mapWidth = width;
	mapHeight = height;
	initMap();
	addRandomTrees();
}


Map::Map()
{
	mapWidth = 10;
	mapHeight = 10;
	initMap();
	addRandomTrees();
}

Map::~Map()
{
}

/* Getters */
std::vector<std::vector<int>> Map::getMap(){ return gameMap; }

void Map::initMap()
{
	gameMap.resize(mapHeight);
	for (int i = 0; i < mapHeight; i++)
	{
		gameMap[i].resize(mapWidth);
		for (int j = 0; j < mapWidth; j++)
		{
			gameMap[i][j] = 0; 
		}
	}
}

void Map::addRandomTrees()
{
	/* Will add 200 trees to the map randomly filling 10% overall with trees :) */

	int counter = 0;
	int randY, randX;

	srand(time(NULL));

	while (counter < 200)
	{
		randY = rand() % mapHeight;
		randX = rand() % mapWidth;
		if (gameMap[randY][randX] == 0)
		{
			gameMap[randY][randX] = 2;
			counter++;
		}
	}
}

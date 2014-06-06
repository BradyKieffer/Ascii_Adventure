#include "Map.h"


Map::Map()
{

	initMap();

}


Map::~Map()
{
}

std::vector<std::vector<int>> Map::getMap(){ return gameMap; }

void Map::initMap()
{
	gameMap.resize(MAP_HEIGHT);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		gameMap[i].resize(MAP_WIDTH);
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			gameMap[i][j] = 0; 
		}
	}
}

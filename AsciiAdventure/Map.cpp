#include "Map.h"



Map::Map(int height, int width)
{
	srand(time(NULL));
	mapWidth = width;
	mapHeight = height;
	initMap();
	genMap();

}


Map::Map()
{
	srand(time(NULL));
	mapWidth = 10;
	mapHeight = 10;
	initMap();
	genMap();
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
			gameMap[i][j] = GameEngine::TILE_WALL; 
		}
	}
}

void Map::genMap()
{
	/* Two random points that we will connect, declare their x and y*/
	int x, y, xo, yo, roomsPlaced = 0;
	int counter = 0;

	while (counter < NUM_ROOMS)
	{
		getRoomPoint(x, y);
		xo = x + ROOM_SIZE;
		yo = y + ROOM_SIZE;
		
		for (int i = y; i < yo; i++)
		{
			for (int j = x; j < xo; j++)
			{
				gameMap[i][j] = GameEngine::TILE_ROCK_FLOOR;
			}
		}
		roomsPlaced++;

		if (roomsPlaced > 1)
			makeHall(x, y);
		

		counter++;
	}

	//addRandomWalls();
}

void Map::addRandomTrees()
{
	/* Will add trees to the map randomly filling 10% overall with trees :) */

	int counter = 0;
	int randY, randX;

	while (counter < 100)
	{
		randY = (rand() % (mapHeight - 2)) + 1;
		randX = (rand() % (mapWidth - 2)) + 1;
		if (gameMap[randY][randX] == GameEngine::TILE_ROCK_FLOOR)
		{
			gameMap[randY][randX] = GameEngine::TILE_TREE;
			gameMap[randY - 1][randX] = GameEngine::TILE_ROCK_FLOOR;
			gameMap[randY + 1][randX] = GameEngine::TILE_ROCK_FLOOR;
			gameMap[randY][randX - 1] = GameEngine::TILE_ROCK_FLOOR;
			gameMap[randY][randX + 1] = GameEngine::TILE_ROCK_FLOOR;
			counter++;
		}
	}
}

void Map::addRandomWalls()
{
	/* Will add walls to the map randomly to smooth out the dungeon */

	int counter = 0;
	int randY, randX;

	while (counter < 50)
	{
		randY = (rand() % (mapHeight - 2)) + 1;
		randX = (rand() % (mapWidth - 2)) + 1;
		if (gameMap[randY][randX] == GameEngine::TILE_ROCK_FLOOR)
		{
			gameMap[randY][randX] = GameEngine::TILE_WALL;
			counter++;
		}
	}
}


void Map::genRandPoints(int& x, int& y, int& xo, int& yo)
{
	/* Make us some good ol' random points! */
	
	/* Just to ensure the loops run atleast once :) */
	x = 0;
	y = 0;
	xo = -1;
	yo = -1;

	/* Start with x and xo */
	while (x >= xo)
	{
		x = rand() % mapWidth;
		xo = rand() % mapWidth;
	}

	/* Now do y and yo */
	while (y >= yo)
	{
		y = rand() % mapHeight;
		yo = rand() % mapHeight;
	}
}

void Map::getRoomPoint(int& x, int& y)
{
	bool isClear = false;

	x = rand() % (mapWidth - 5);
	y = rand() % (mapHeight - 5);
	
}

void Map::makeHall(int x, int y)
{
	/* First calc the middle of the room, it's 2 over from x and y  */
	x += (ROOM_SIZE / 2);
	y += (ROOM_SIZE / 2);

	bool notConnected = true;
	int roomOffset = (ROOM_SIZE / 2) ; // Just to offset the start of our loops
	int xo = 0, yo = 0;

	
	/* Scan to design some halls that are 90 degrees */
	for (int i = x + roomOffset; i < mapWidth; i++)
	{
		bool foundHall = false;


		if (gameMap[y][i] == GameEngine::TILE_ROCK_FLOOR)
			break;

		for (int j = 0; j < mapHeight; j++)
		{
			if (gameMap[j][i] == GameEngine::TILE_ROCK_FLOOR)
			{
				yo = j;
				xo = i;
				foundHall = true;
			}
		}

		gameMap[y][i] = GameEngine::TILE_ROCK_FLOOR;

		if (foundHall == true)
		{
			if (yo < y)
			{
				carveDownward(x + roomOffset, y, xo, yo);
			}
			else if (yo > y)
			{
				carveUpward(x + roomOffset, y, xo, yo);
			}
			break;
		}
	}
	/* OLD MAKE HALL */
	/*
	 First calc the middle of the room, it's 2 over from x and y
	x += (ROOM_SIZE / 2);
	y += (ROOM_SIZE / 2);

	int roomOffset = (ROOM_SIZE / 2) + 1; // Just to offset the start of our loops

	int dir = rand() % 11;
	if (dir < 3)
	{
		// Up
		for (int i = y - roomOffset; i >= 0; i--)
		{
			if (gameMap[i][x] == GameEngine::TILE_ROCK_FLOOR)
				break;
			gameMap[i][x] = GameEngine::TILE_ROCK_FLOOR;
		}
	}
	else if (dir >= 3 && dir < 5)
	{
		// Left
		for (int i = x - roomOffset; i >= 0; i--)
		{
			if (gameMap[y][i] == GameEngine::TILE_ROCK_FLOOR)
				break;
			gameMap[y][i] = GameEngine::TILE_ROCK_FLOOR;
		}
	}
	else if (dir >= 5 && dir < 7)
	{
		// Down
		for (int i = y + roomOffset; i < mapHeight; i++)
		{
			if (gameMap[i][x] == GameEngine::TILE_ROCK_FLOOR)
				break;
			gameMap[i][x] = GameEngine::TILE_ROCK_FLOOR;
		}
	}
	else
	{
		// Right
		for (int i = x + roomOffset; i < mapWidth; i++)
		{
			if (gameMap[y][i] == GameEngine::TILE_ROCK_FLOOR)
				break;
			gameMap[y][i] = GameEngine::TILE_ROCK_FLOOR;
		}
	}

	*/
}

void Map::carveUpward(int x, int y, int xo, int yo)
{
	/* We carve a hall straight up to connect the room! */
	for (int i = y; i < yo; i++)
	{
		gameMap[i][xo] = GameEngine::TILE_ROCK_FLOOR;
	}
}

void Map::carveDownward(int x, int y, int xo, int yo)
{
	/* We carve a hall straight up to connect the room! */
	for (int i = yo; i < y; i++)
	{
		gameMap[i][xo] = GameEngine::TILE_ROCK_FLOOR;
	}
}
#include "Map.h"

#include<iostream>

Map::Map(int mHeight, int mWidth, int sHeight, int sWidth)
{
	srand(time(NULL));
	mapHeight = mHeight;
	mapWidth = mWidth;
	screenHeight = sHeight;
	screenWidth = sWidth;
	
	initMap();
	genMap();

}

Map::Map()
{
	/* Default Constructor */
}

Map::~Map()
{
}
/* Setters */
void Map::setMap(std::vector<std::vector<int>> map)
{
	gameMap = map;
}

/* Getters */
std::vector<std::vector<int>> Map::getMap(){ return gameMap; }

int Map::getTile(int y, int x) { return gameMap[y][x]; }

int Map::getMapHeight(){ return mapHeight; }
int Map::getMapWidth(){ return mapWidth; }
int Map::getScreenHeight(){ return screenHeight; }
int Map::getScreenWidth(){ return screenWidth; }

void Map::initMap()
{
	gameMap.resize(mapHeight);
	for (int i = 0; i < mapHeight; i++)
	{
		gameMap[i].resize(mapWidth);
		for (int j = 0; j < mapWidth; j++)
		{
			gameMap[i][j] = Tile::TILE_WALL; 
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
				gameMap[i][j] = Tile::TILE_ROCK_FLOOR;
			}
		}
		roomsPlaced++;

		if (roomsPlaced > 1)
		{
			makeHall(x, y);
		}
		counter++;
	}
}

void Map::displayMap(WINDOW* win, int left, int top)
{
	int tileType;
	char tileSym;
	short colCode;

	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			int wy = i + top;
			int wx = j + left;

			tileType = gameMap[wy][wx];
			
			mvwaddch(win, i, j, tile.tileIndex[tileType].symbol | COLOR_PAIR(tile.tileIndex[tileType].colCode));
			
		}
	}
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
		if (gameMap[randY][randX] == Tile::TILE_ROCK_FLOOR)
		{
			gameMap[randY][randX] = Tile::TILE_TREE;
			gameMap[randY - 1][randX] = Tile::TILE_ROCK_FLOOR;
			gameMap[randY + 1][randX] = Tile::TILE_ROCK_FLOOR;
			gameMap[randY][randX - 1] = Tile::TILE_ROCK_FLOOR;
			gameMap[randY][randX + 1] = Tile::TILE_ROCK_FLOOR;
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
		if (gameMap[randY][randX] == Tile::TILE_ROCK_FLOOR)
		{
			gameMap[randY][randX] = Tile::TILE_WALL;
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

/* This function is gonna be gross but I can't afford to care anymore :) */
void Map::makeHall(int x, int y)
{
	/* First calc the middle of the room, it's 2 over from x and y  */
	x += (ROOM_SIZE / 2);
	y += (ROOM_SIZE / 2);

	int roomOffset = (ROOM_SIZE / 2) ; // Just to offset the start of our loops
	int xo = 0, yo = 0;
	bool foundHall = false;
	
	/* Scan to design some halls that are 90 degrees */
	for (int i = x + roomOffset; i < mapWidth; i++)
	{

		if (gameMap[y][i] == Tile::TILE_ROCK_FLOOR)
		{
			break;
		}

		/* First search right then search left */
		for (int j = 0; j < mapHeight; j++)
		{
			if (gameMap[j][i] == Tile::TILE_ROCK_FLOOR)
			{
				yo = j;
				xo = i;
				foundHall = true;
			}
		}

		if (foundHall == true)
		{
			
			for (int q = x + roomOffset; q <= i; q++)
			{
				gameMap[y][q] = Tile::TILE_ROCK_FLOOR;
			}
			
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

	/* Scan left */
	if (foundHall == false)
	{
		for (int i = x - roomOffset - 1; i > 0; i--)
		{

			if (gameMap[y][i] == Tile::TILE_ROCK_FLOOR)
			{
				break; 
			}

			/* First search right then search left */
			for (int j = 0; j < mapHeight; j++)
			{
				if (gameMap[j][i] == Tile::TILE_ROCK_FLOOR)
				{
					yo = j;
					xo = i;
					foundHall = true;
				}
			}

			if (foundHall == true)
			{
				for (int q = x - roomOffset; q >= i; q--)
				{
					gameMap[y][q] = Tile::TILE_ROCK_FLOOR;
				}

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
	}
}

void Map::carveUpward(int x, int y, int xo, int yo)
{
	/* We carve a hall straight up to connect the room! */
	for (int i = y; i < yo; i++)
	{
		gameMap[i][xo] = Tile::TILE_ROCK_FLOOR;
	}
}

void Map::carveDownward(int x, int y, int xo, int yo)
{
	/* We carve a hall straight up to connect the room! */
	for (int i = yo; i < y; i++)
	{
		gameMap[i][xo] = Tile::TILE_ROCK_FLOOR;
	}
}
#include "Map.h"

#include<iostream>

Map::Map(int mDepth, int mHeight, int mWidth, int sHeight, int sWidth)
{
	srand(time(NULL));
	mapHeight = mHeight;
	mapWidth = mWidth;
	mapDepth = mDepth;
	screenHeight = sHeight;
	screenWidth = sWidth;
	
	//initMap();
	makeCaves(NUM_TIMES);

}

Map::Map()
{
	/* Default Constructor */
}

Map::~Map()
{
}

Map& Map::operator=(const Map& rhs)
{
	swap(rhs);
	return *this;
}

void Map::swap(Map rhs)
{
	setMapHeight(rhs.getMapHeight());
	setMapWidth(rhs.getMapWidth());
	setScreenHeight(rhs.getScreenHeight());
	setScreenWidth(rhs.getScreenWidth());
	setMap(rhs.getMap());
}

/* Setters */
void Map::setMap(std::vector<std::vector<std::vector<int>>> map){ gameMap = map; }
void Map::setMapHeight(int mHeight){ mapHeight = mHeight; }
void Map::setMapWidth(int mWidth){ mapWidth = mWidth; }
void Map::setMapDepth(int mDepth){ mapDepth - mDepth; }
void Map::setScreenHeight(int sHeight){ screenHeight = sHeight; }
void Map::setScreenWidth(int sWidth){ screenWidth = sWidth; }


/* Getters */
std::vector<std::vector<std::vector<int>>> Map::getMap(){ return gameMap; }

int Map::getTile(int x, int y, int z){ return gameMap[z][y][x]; }

int Map::getMapHeight(){ return mapHeight; }
int Map::getMapWidth(){ return mapWidth; }
int Map::getMapDepth(){ return mapDepth; }
int Map::getScreenHeight(){ return screenHeight; }
int Map::getScreenWidth(){ return screenWidth; }

void Map::initMap()
{
	gameMap.resize(mapDepth);
	for (int i = 0; i < mapDepth; ++i)
	{
		gameMap[i].resize(mapHeight);
		for (int j = 0; j < mapHeight; ++j)
		{
			gameMap[i][j].resize(mapWidth);
			for (int k = 0; k < mapWidth; ++k)
			{
				gameMap[i][j][k] = Tile::TILE_ROCK_FLOOR;
			}	
		}
	}
}

void Map::displayMap(WINDOW* win, int left, int top, int currDepth)
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

			tileType = gameMap[currDepth][wy][wx];
			
			mvwaddch(win, i, j, tile.tileIndex[tileType].symbol | COLOR_PAIR(tile.tileIndex[tileType].colCode));
		}
	}
}

/* The new map gen will be going here yay :D */
void Map::makeCaves(int times)
{
	placeTiles();
	while (times > 0)
	{
		smooth();
		--times;
	}
	//placeStairs();
}

void Map::placeTiles()
{
	gameMap.resize(mapDepth);
	for (int i = 0; i < mapDepth; ++i)
	{
		gameMap[i].resize(mapHeight);
		for (int j = 0; j < mapHeight; ++j)
		{
			gameMap[i][j].resize(mapWidth);
			for (int k = 0; k < mapWidth; ++k)
			{
				/* We want an equal ration between walls and floors */
				if (rand() % 100 < 50)
				{
					gameMap[i][j][k] = Tile::TILE_ROCK_FLOOR;
				}
				else
				{
					gameMap[i][j][k] = Tile::TILE_WALL;
				}
			}
		}
	}
}

void Map::smooth()
{
	std::vector<std::vector<std::vector<int>>> tmp = gameMap;
	for (int z = 0; z < mapDepth; z++)
	{
		int numStairsPlaced = 0;
		for (int y = 1; y < mapHeight - 1; ++y)
		{
			for (int x = 1; x < mapWidth - 1; ++x)
			{
				int numWalls = 0, numFloors = 0, xo, yo;
				for (yo = -1; yo <= 1; ++yo)
				{
					for (xo = -1; xo <= 1; ++xo)
					{
						if (tmp[z][y + yo][x + xo] == Tile::TILE_WALL)
						{
							++numWalls;
						}
						else if (tmp[z][y + yo][x + xo] == Tile::TILE_ROCK_FLOOR)
						{
							++numFloors;
						}

					}
				}

				if (numWalls > numFloors)
				{
					tmp[z][y][x] = Tile::TILE_WALL;
				}
				else if(numFloors == 9 && numStairsPlaced < NUM_STAIRS_PER_FLOOR && rand() % 100 < 5)
				{
					tmp[z][y][x] = rand() % 100 < 50 ? Tile::TILE_STAIRS_DOWN : Tile::TILE_STAIRS_UP;
					++numStairsPlaced;
				}
				else
				{
					tmp[z][y][x] = Tile::TILE_ROCK_FLOOR;
				}

			}
		}
	}
	setMap(tmp);
}

void Map::placeStairs()
{
	int numStairsPlaced = 0;
	while (numStairsPlaced < NUM_STAIRS_PER_FLOOR)
	{
		for (int z = 0; z < mapDepth; ++z)
		{
			numStairsPlaced = 0;
			for (int y = 1; y < mapHeight - 1; ++y)
			{
				for (int x = 1; x < mapWidth - 1; ++x)
				{
					int numWalls = 0, numFloors = 0, xo, yo;
					for (yo = -1; yo <= 1; ++yo)
					{
						for (xo = -1; xo <= 1; ++xo)
						{
							if (gameMap[z][y + yo][x + xo] == Tile::TILE_ROCK_FLOOR)
							{
								++numFloors;
							}
							else
							{
								break;
							}
						}
					}
					if (numFloors == 9 && numStairsPlaced < NUM_STAIRS_PER_FLOOR && rand() % 100 < 2)
					{
						gameMap[z][y][x] = rand() % 100 < 50 ? Tile::TILE_STAIRS_DOWN : Tile::TILE_STAIRS_UP;
						++numStairsPlaced;
					}
				}
			}
		}
	}
}
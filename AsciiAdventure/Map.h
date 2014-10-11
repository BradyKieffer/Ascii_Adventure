/*

	The map will be stored and generated here.
	This will (hopefully) be the only place 
	that still has function calls that go x - y
	and not y - x

*/

#ifndef MAP_H
#define MAP_H

#include<curses.h>
#include<vector>
#include<ctime>
#include"Tile.h"

class Map
{
public:	
	Tile tile;

	Map();
	Map(int mapDepth, int mapHeight, int mapWidth, int screenHeight, int screenWidth);
	~Map();
	
	Map& operator=(const Map& rhs);

	std::vector<std::vector<std::vector<int>>> getMap();
	void setMap(std::vector<std::vector<std::vector<int>>> map);

	int getMapHeight();
	int getMapWidth();
	int getMapDepth();
	int getScreenHeight();
	int getScreenWidth();

	void setMapHeight(int mHeight);
	void setMapWidth(int mWidth);
	void setMapDepth(int mDepth);
	void setScreenHeight(int sHeight);
	void setScreenWidth(int sWidth);
	
	int getTile(int x, int y, int z); /* Get a tile by passing in y and x */
	void displayMap(WINDOW* win, int left, int top, int currDepth);

private:
	int NUM_TIMES =10; /* How many times we want to iterate through the smoothing algo */
	std::vector<std::vector<std::vector<int>>> gameMap;

	const int NUM_ROOMS = 50, ROOM_SIZE = 6, NUM_STAIRS_PER_FLOOR = 1;

	int mapHeight, mapWidth, mapDepth,screenHeight, screenWidth;

	void swap(Map map);

	void initMap();

	void makeCaves(int times); /* Makes caves by smoothing the tiles placed */
	void placeTiles(); /* places walls or floors randomly in each tile */
	void smooth();
	void placeStairs();
};

#endif


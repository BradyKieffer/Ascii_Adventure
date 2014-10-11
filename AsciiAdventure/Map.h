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
	Map(int mapHeight, int mapWidth, int screenHeight, int screenWidth);
	~Map();
	
	Map& operator=(const Map& rhs);

	std::vector<std::vector<int>> getMap();
	void setMap(std::vector<std::vector<int>> map);

	int getMapHeight();
	int getMapWidth();
	int getScreenHeight();
	int getScreenWidth();

	void setMapHeight(int mHeight);
	void setMapWidth(int mWidth);
	void setScreenHeight(int sHeight);
	void setScreenWidth(int sWidth);

	int getTile(int y, int x); /* Get a tile by passing in y and x */
	void displayMap(WINDOW* win, int left, int top);

private:
	int NUM_TIMES =10; /* How many times we want to iterate through the smoothing algo */
	std::vector<std::vector<int>> gameMap;

	const int NUM_ROOMS = 50, ROOM_SIZE = 6, NUM_STAIRS_PER_FLOOR = 6;

	int mapHeight, mapWidth, screenHeight, screenWidth;

	void swap(Map map);

	void initMap();
	void genMap(); /* Make our world here */
	void addRandomTrees(); /* Just testing what it's like to add random trees */
	void addRandomWalls(); /* Just testing what it's like to add random walls */
	void addBounds(); /* How we keep the player on screen */

	void makeCaves(int times); /* Makes caves by smoothing the tiles placed */
	void placeTiles(); /* places walls or floors randomly in each tile */
	void smooth(int& numStairsPlaced);

	void genRandPoints(int& x, int& y, int& xo, int& yo); /* Generates random points such the x < xo and y < yo*/
	void getRoomPoint(int& x, int& y); /* Make a point such that it can become a 5x5 room */
	void makeHall(int x, int y); /* Make a hallway in a certain direction depending on random maths */
	
	void carveUpward(int x, int y, int xo, int yo);
	void carveDownward(int x, int y, int xo, int yo);

};

#endif


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
	
	std::vector<std::vector<int>> getMap();
	void setMap(std::vector<std::vector<int>> map);

	int getMapHeight();
	int getMapWidth();
	int getScreenHeight();
	int getScreenWidth();

	int getTile(int y, int x); /* Get a tile by passing in y and x */
	void displayMap(WINDOW* win, int left, int top);

private:
	std::vector<std::vector<int>> gameMap;

	const int NUM_ROOMS = 50,ROOM_SIZE = 6;

	int mapHeight, mapWidth, screenHeight, screenWidth;

	void initMap();
	void genMap(); /* Make our world here */
	void addRandomTrees(); /* Just testing what it's like to add random trees */
	void addRandomWalls(); /* Just testing what it's like to add random walls */
	void addBounds(); /* How we keep the player on screen */

	void genRandPoints(int& x, int& y, int& xo, int& yo); /* Generates random points such the x < xo and y < yo*/
	void getRoomPoint(int& x, int& y); /* Make a point such that it can become a 5x5 room */
	void makeHall(int x, int y); /* Make a hallway in a certain direction depending on random maths */
	
	void carveUpward(int x, int y, int xo, int yo);
	void carveDownward(int x, int y, int xo, int yo);

};

#endif


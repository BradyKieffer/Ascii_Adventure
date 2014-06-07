/*

	The map will be stored and generated here

*/

#ifndef MAP_H
#define MAP_H

#include<curses.h>
#include<vector>
#include<ctime>
#include"GameEngine.h"



class Map
{
public:
	Map(int height, int width);
	Map();
	~Map();
	
	std::vector<std::vector<int>> getMap();



private:
	std::vector<std::vector<int>> gameMap;

	const int NUM_ROOMS = 35,ROOM_SIZE = 6;
	int mapHeight, mapWidth;

	void initMap();
	void addRandomTrees(); /* Just testing what it's like to add random trees */
	void addRandomWalls(); /* Just testing what it's like to add random walls */

	void genMap(); /* Make our world here */
	void genRandPoints(int& x, int& y, int& xo, int& yo); /* Generates random points such the x < xo and y < yo*/
	void getRoomPoint(int& x, int& y); /* Make a point such that it can become a 5x5 room */
	void makeHall(int x, int y); /* Make a hallway in a certain direction depending on random maths */
};

#endif


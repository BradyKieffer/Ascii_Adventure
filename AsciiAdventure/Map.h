/*

	The map will be stored and generated here

*/

#ifndef MAP_H
#define MAP_H

#include<curses.h>
#include<vector>
#include<ctime>

class Map
{
public:
	Map(int height, int width);
	Map();
	~Map();
	
	std::vector<std::vector<int>> getMap();



private:
	std::vector<std::vector<int>> gameMap;

	int mapHeight, mapWidth;

	void initMap();
	void addRandomTrees(); /* Just testing what it's like to add random trees */

};

#endif


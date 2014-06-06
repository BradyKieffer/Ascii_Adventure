/*

	The map will be stored and generated here

*/

#ifndef MAP_H
#define MAP_H

#include<curses.h>
#include<vector>

class Map
{
public:
	Map();
	~Map();
	
	std::vector<std::vector<int>> getMap();

private:
	std::vector<std::vector<int>> gameMap;

	const int MAP_WIDTH = 100, MAP_HEIGHT = 100;

	void initMap();

};

#endif


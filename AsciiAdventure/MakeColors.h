
/*

Implement and store colors here

*/

#ifndef MAKECOLORS_H
#define MAKECOLORS_H

#include<curses.h>


enum ColNameNums
{
	COLOR_LIGHT_GREY = 100,
	COLOR_DARK_BROWN = 101,
	COLOR_WALL_BROWN = 102,
	COLOR_FLOOR_BROWN = 103,
	COLOR_STAIRS = 104
};

class MakeColors
{
public:
	MakeColors();
	~MakeColors();

	void initColors();

	enum ColPairNums
	{
		COL_DEAD = 99,
		COL_PLAYER = 100,
		COL_BEAR = 101,
		COL_ROCK_FLOOR = 1,
		COL_TREE = 2,
		COL_WALL = 3,
		COL_BOUNDS = 4,
		COL_STAIRS = 5,
		COL_RAGE = 6
	};
private: 
	void makeNewCols();
};

#endif

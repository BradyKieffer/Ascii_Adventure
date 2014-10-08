
/*

Implement and store colors here

*/

#ifndef MAKECOLORS_H
#define MAKECOLORS_H

#include<curses.h>


enum ColNameNums
{
	COLOR_LIGHT_GREY = 100,
	COLOR_BEAR = 101
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
		COL_WALL = 3
	};
private: 
	void makeNewCols();
};

#endif

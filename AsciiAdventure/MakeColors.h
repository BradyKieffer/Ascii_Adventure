
/*

Implement and store colors here

*/

#ifndef MAKECOLORS_H
#define MAKECOLORS_H

#include<curses.h>

enum ColPairNums
{
	COL_PLAYER = 100,
	COL_ROCK_FLOOR = 1,
	COL_TREE = 2,
	COL_WALL = 3
};

enum ColNameNums
{
	COLOR_LIGHT_GREY = 100
};

class MakeColors
{
public:
	MakeColors();
	~MakeColors();

	void initColors();

private: 
	void makeNewCols();
};

#endif

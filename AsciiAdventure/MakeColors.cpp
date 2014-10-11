#include "MakeColors.h"


MakeColors::MakeColors()
{
	makeNewCols();
}


MakeColors::~MakeColors()
{
}


void MakeColors::initColors()
{
	/* When death occurs :( */
	init_pair(COL_DEAD, COLOR_BLUE, COLOR_RED);

	/* Players color selection */
	init_pair(COL_PLAYER, COLOR_YELLOW, COLOR_FLOOR_BROWN);

	/* BEAR color selection */
	init_pair(COL_BEAR, COLOR_DARK_BROWN, COLOR_BLACK);

	/* Rock (generic) color selection */
	//init_pair(COL_ROCK_FLOOR, COLOR_LIGHT_GREY, COLOR_BLACK);
	init_pair(COL_ROCK_FLOOR, COLOR_FLOOR_BROWN, COLOR_FLOOR_BROWN);

	/* Tree color selection */
	init_pair(COL_TREE, COLOR_GREEN, COLOR_BLACK);

	/* Wall color selection */
	init_pair(COL_WALL, COLOR_WALL_BROWN, COLOR_WALL_BROWN);

	/* Out of bounds */
	init_pair(COL_BOUNDS, COLOR_LIGHT_GREY, COLOR_LIGHT_GREY);

	/* Stairs */
	init_pair(COL_STAIRS, COLOR_BLACK, COLOR_FLOOR_BROWN);
}

void MakeColors::makeNewCols()
{
	/* param 1     : color name
	* param 2, 3, 4 : rgb content min = 0, max = 1000 */

	/* Light gray color */
	init_color(COLOR_LIGHT_GREY, 500, 500, 500);

	/* Dark brown color */
	init_color(COLOR_DARK_BROWN, 250, 200, 0);
	
	/* Brown for the walls */
	init_color(COLOR_WALL_BROWN, 255, 230, 0);

	/* Color for the floor */
	init_color(COLOR_FLOOR_BROWN, 200, 150, 0);

}
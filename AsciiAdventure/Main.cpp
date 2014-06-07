/*
	
	It's time for an AsciiAdventure yay!!!
	This is an attempt at writing a roguelike.
	It will most likely fail

	Start Date:		31-05-2014
	Last Revised:	05-06-2014
	Author:			Brady Kieffer

	TODO:
		Implement a structure for tiles that will store their properties

		Add something to control the defined color pairs

*/

#include<curses.h>
#include "GameEngine.h"

const int HEIGHT = 25;
const int WIDTH = 80;

int main()
{
	GameEngine engine(HEIGHT, WIDTH);
	
	engine.gameInit();
	endwin();
	return 0;
}
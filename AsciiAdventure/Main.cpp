
/*
	
	It's time for an AsciiAdventure yay!!!
	This is an attempt at writing a roguelike.
	It will most likely fail

	Start Date:		31-05-2014
	Last Revised:	07-10-2014
	Author:			Brady Kieffer

*/

#include<curses.h>
#include "GameEngine.h"

int main()
{
	GameEngine engine;
	
	engine.gameInit();
	endwin();
	return 0;
}
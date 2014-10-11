#include "GameEngine.h"
#include <algorithm> // For max and min 


GameEngine::GameEngine(int gameHeight, int gameWidth)
{
	/* Curses code to set up the background for our input and initialize various other things */
	initscr();
	cbreak();
	keypad(gameWin, TRUE);
	noecho();
	curs_set(0); /* Make the cursor invisible */
	start_color();
	PDC_set_blink(TRUE);

	MakeColors col;
	col.initColors();

	/* Set up the game window */
	gameWin = newwin(SCREEN_HEIGHT, SCREEN_WIDTH, 0, 0);
}

GameEngine::~GameEngine()
{
	delwin(gameWin);
}

void GameEngine::gameInit()
{
	/* Start the game loop */
	mainLoop = true;	
	gameLoop();
}

void GameEngine::gameLoop()
{
	/* Used to center the screen on the hero */
	int left = 0; 
	int top = 0;

	char inp;
	Map gameMap(MAP_HEIGHT, MAP_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH);
	
	/* Set up our hero */
	Player tmp(0, 0);
	hero = tmp;
	hero.setCoords(gameMap);

	while (hero.isLiving() && mainLoop == true)
	{
		
		left = getScrollX();
		top = getScrollY();

		gameMap.displayMap(gameWin, left, top);

		/*Debugging purposes*/
		std::cout << "Player (x,y) = " << hero.getXPos() << " , " << hero.getYPos() << std::endl;
		
		/* Draw the hero to the screen*/
		mvwaddch(gameWin,hero.getYPos() - top, hero.getXPos() - left,hero.getSymbol());
		wrefresh(gameWin);

		inp = wgetch(gameWin);
		getInput(gameMap,inp);
		
	}
}

int GameEngine::getScrollX()
{
	return std::max(0, std::min(hero.getXPos() - SCREEN_WIDTH/2, MAP_WIDTH - SCREEN_WIDTH));
}

int GameEngine::getScrollY()
{
	return std::max(0, std::min(hero.getYPos() - SCREEN_HEIGHT/2, MAP_HEIGHT - SCREEN_HEIGHT));
}

void GameEngine::getInput(Map& gameMap, char input)
{
	
	switch (input)
	{
	case'4':
		// Move left 
		hero.onMove(gameMap, 0, -1);
		break;

	case'8':
		// Move up
		hero.onMove(gameMap, -1, 0);
		break;

	case '6':
		// Move right
		hero.onMove(gameMap, 0, 1);
		break;

	case '2':
		// Move down
		hero.onMove(gameMap, 1, 0);
		break;

	case '7':
		// Move up-left
		hero.onMove(gameMap, -1, -1);
		break;

	case '9':
		// Move up-right
		hero.onMove(gameMap, -1, 1);
		break;

	case '3':
		// Move down-right
		hero.onMove(gameMap, 1, 1);
		break;

	case '1':
		// Move down-left
		hero.onMove(gameMap, 1, -1);
		break;

	case 'Q':
	case 'q':
		// Quit the game
		mainLoop = false;
		break;

	case 'R':
	case 'r':
		/* Debug for now.. */
		gameInit();
		break;

	default:
		break;
	}
}
#include "GameEngine.h"


GameEngine::GameEngine(int gameHeight, int gameWidth)
{
	/* Curses code to set up the background for our input and initialize various other things */
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	
	/* Set up the game window */
	gameScreen.setHeight(gameHeight);
	gameScreen.setWidth(gameWidth);
	gameScreen.initWindow();
}


GameEngine::~GameEngine()
{}

void GameEngine::gameInit()
{
	/* Create our world */
	Map genWorld(MAP_HEIGHT, MAP_WIDTH);
	gameMap = genWorld.getMap();

	/* Start the game loop */
	mainLoop = true;

	/* Set up our hero */
	Player tmp(0, 0);
	hero = tmp;
	
	/*Debugging purposes*/
	std::cout << "Game Height: " << gameScreen.getHeight() << std::endl;
	std::cout << "Game Width: " << gameScreen.getWidth() << std::endl;

	gameLoop();


}


void GameEngine::gameLoop()
{
	char inp;

	
	char heroSymbol = hero.getSymbol(); /* Just so we don't call this function a million times */
	while (mainLoop == true)
	{
		
		displayMap();
		/*Debugging purposes*/
		std::cout << "Player (x,y) = " << hero.getXPos() << " , " << hero.getYPos() << std::endl;

		/* Draw the hero to the screen*/
		mvaddch(hero.getYPos(), hero.getXPos() ,hero.getSymbol());

		inp = getch();
		getInput(inp);

	}
}

void GameEngine::displayMap()
{
	for (int i = 0; i < gameMap.size(); i++)
	{
		for (int j = 0; j < gameMap[i].size(); j++)
		{
			switch (gameMap[i][j])
			{
			case TILE_FLOOR:
				
				mvaddch(i, j, '.');
				break;

			case TILE_WALL:
				mvaddch(i, j, '#');
				break;

			case TILE_TREE:
				mvaddch(i, j, 'T');
				break;
			}
		}
	}
}

void GameEngine::getInput(char input)
{
	
	switch (input)
	{
	case'4':
		// Move left 
		moveChar(0, -1);
		break;

	case'8':
		// Move up
		moveChar(-1, 0);
		break;

	case '6':
		// Move right
		moveChar(0, 1);
		break;

	case '2':
		// Move down
		moveChar(1, 0);
		break;

	case '7':
		// Move up-left
		moveChar(-1, -1);
		break;

	case '9':
		// Move up-right
		moveChar(-1, 1);
		break;

	case '3':
		// Move down-right
		moveChar(1, 1);
		break;

	case '1':
		// Move down-left
		moveChar(1, -1);
		break;

	case 'Q':
	case 'q':
		// Quit the game
		mainLoop = false;

	default:
		break;
	}
}

void GameEngine::moveChar(int deltaY, int deltaX)
{
	mvaddch(hero.getYPos(), hero.getXPos(), ' '); /* Bad way of removing the character's old sprite */
	
	
	if (hero.getYPos() + deltaY < 0 || hero.getYPos() + deltaY > MAP_HEIGHT - 1)
	{
		/* If we are here then don't add to the height */
		deltaY = 0;
	}


	if (hero.getXPos() + deltaX < 0 || hero.getXPos() + deltaX > MAP_WIDTH - 1)
	{
		/* If we are here then don't add to the width */
		deltaX = 0;
	}

	if (gameMap[hero.getYPos() + deltaY][hero.getXPos() + deltaX] == TILE_FLOOR)
	{
		/* We are moving onto a floor tile! yay! */
		/* Add the results to the heroes coordinates */
		hero.setYPos(hero.getYPos() + deltaY);
		hero.setXPos(hero.getXPos() + deltaX);
	}
}
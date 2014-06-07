#include "GameEngine.h"


GameEngine::GameEngine(int gameHeight, int gameWidth)
{
	/* Curses code to set up the background for our input and initialize various other things */
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0); /* Make the cursor invisible */
	start_color();
	
	MakeColors col;
	col.initColors();

	/* Set up the game window */
	gameScreen.setHeight(gameHeight);
	gameScreen.setWidth(gameWidth);
	gameScreen.initWindow();
}

GameEngine::~GameEngine()
{}

void GameEngine::gameInit()
{
	/* Set up the tile list */
	initTiles();

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

void GameEngine::initTiles()
{
	/* 
	Enters the tile values to the vector for the tile index
	
	The index will be the tile type

	Values are stored by symbol, color number and if the tile is passable
	*/

	tileIndex.resize(3);

	/* Rock floor */
	tileIndex[TILE_ROCK_FLOOR] = { '.', COL_ROCK_FLOOR, true };

	/* Tree */
	tileIndex[TILE_TREE] = { 'T', COL_TREE, false };

	/* Wall */
	tileIndex[TILE_WALL] = { '#', COL_WALL, false };
}

void GameEngine::gameLoop()
{
	char inp;
	
	setPlayerCoords();

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
	int tileType;
	char tileSym;
	short colCode;
	for (int i = 0; i < gameMap.size(); i++)
	{
		for (int j = 0; j < gameMap[i].size(); j++)
		{
			tileType = gameMap[i][j];
			mvaddch(i, j, tileIndex[tileType].symbol | COLOR_PAIR(tileIndex[tileType].colCode));
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

	int tileMoveToType = gameMap[hero.getYPos() + deltaY][hero.getXPos() + deltaX];

	if (tileIndex[tileMoveToType].isPassable == true)
	{
		/* We are moving onto a floor tile! yay! */
		/* Add the results to the heroes coordinates */
		hero.setYPos(hero.getYPos() + deltaY);
		hero.setXPos(hero.getXPos() + deltaX);
	}
}

void GameEngine::setPlayerCoords()
{
	/* For now just set the player to the first found walkable tile */
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (tileIndex[gameMap[i][j]].isPassable == true)
			{
				/* We found our spot yay! */
				hero.setYPos(i);
				hero.setXPos(j);
				break;
			}
		}
	}
}
#include "GameEngine.h"


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
	gameWin = newwin(gameHeight, gameWidth, 0, 0);
}

GameEngine::~GameEngine()
{

	delwin(playerHUD);
	delwin(gameWin);
}

/* Getters */

int GameEngine::getHeight()
{
	return MAP_HEIGHT;
}

int GameEngine::getWidth()
{
	return MAP_WIDTH;
}

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
	
	/* Create some bears to battle */
	makeEnemies();

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
	tileIndex[TILE_ROCK_FLOOR] = { '.', MakeColors::COL_ROCK_FLOOR, true };

	/* Tree */
	tileIndex[TILE_TREE] = { 'T', MakeColors::COL_TREE, false };

	/* Wall */
	tileIndex[TILE_WALL] = { '#', MakeColors::COL_WALL, false };
}

void GameEngine::gameLoop()
{
	char inp;
	
	setPlayerCoords();
	
	while (hero.isLiving() && mainLoop == true)
	{
		displayMap();
		/*Debugging purposes*/
		std::cout << "Player (x,y) = " << hero.getXPos() << " , " << hero.getYPos() << std::endl;

		/* Because we want him to die :) */
		hero.takeDamage(1);
		std::cout << "Player HP = " << hero.getHp() << std::endl;
		
		/* Draw the hero to the screen*/
		mvwaddch(gameWin,hero.getYPos(), hero.getXPos() ,hero.getSymbol());
		wrefresh(gameWin);

		/* Draw the enemies */
		renderEnemies();
		

		inp = wgetch(gameWin);
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
			mvwaddch(gameWin, i, j, tileIndex[tileType].symbol | COLOR_PAIR(tileIndex[tileType].colCode));
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

void GameEngine::renderEnemies()
{
	bool enemieKilled = false;
	for (int i = 0; i < enemies.size(); i++)
	{
		// For debug purposes, kill random bears

		if (rand() % 100 > 98)
		{
			enemies[i].takeDamage(999.9);
			//enemies.erase(enemies.begin() + i);
			//enemieKilled = true;
			//break;
		}
		mvwaddch(gameWin, enemies[i].getYPos(), enemies[i].getXPos(), enemies[i].getSymbol());
	}
	/*
	if (enemieKilled)
	{
		renderEnemies();
	}
	*/
}

void GameEngine::makeEnemies()
{
	enemies.resize(NUM_ENEMIES);
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		int x = rand() % MAP_WIDTH;
		int y = rand() % MAP_HEIGHT;
		
		while (gameMap[y][x] == GameEngine::TILE_WALL)
		{
			x = rand() % MAP_WIDTH;
			y = rand() % MAP_HEIGHT;
		}
		Bear tmp(y, x);
		enemies[i] = tmp;
	}
}
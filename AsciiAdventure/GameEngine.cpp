#include "GameEngine.h"


GameEngine::GameEngine(int gameHeight, int gameWidth)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	gameScreen.setHeight(gameHeight);
	gameScreen.setWidth(gameWidth);
	gameScreen.initWindow();
}


GameEngine::~GameEngine()
{}

void GameEngine::gameInit()
{
	Map map;
	gameMap = map.getMap();
	gameLoop();
}


void GameEngine::gameLoop()
{
	char inp = getch();
	bool loop = true;
	while (loop)
	{
		addch(inp);
		inp = getch();
		if (inp == 'q' || inp == 'Q')
			loop = false;
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
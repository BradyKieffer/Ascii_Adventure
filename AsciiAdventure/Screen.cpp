#include "Screen.h"

Screen::Screen()
{
	// Default constructor
}

Screen::Screen(int height, int width)
{
	setHeight(height);
	setWidth(width);
}


Screen::~Screen()
{
	// Destroy the current window when out of scope!
	delwin(gameWin);
	
}


// Setters
void Screen::setHeight(int height)
{
	if (checkSize(height) == true)
		screenHeight = height;
}

void Screen::setWidth(int width)
{
	if (checkSize(width) == true)
		screenWidth = width;
}

// Getters 
int Screen::getHeight()
{
	return screenHeight;
}

int Screen::getWidth()
{
	return screenWidth;
}

bool Screen::checkSize(int size)
{
	// For now we only want to ensure it's greater than 0 :)
	if (size > 0)
		return true;
	else
		return false;
}

void Screen::initWindow()
{
	if (checkSize(screenHeight) == true && checkSize(screenWidth) == true)
	{
		gameWin = newwin(screenHeight, screenWidth, 0, 0);
		wrefresh(gameWin);
	}
}
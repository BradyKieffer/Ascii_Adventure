/*

	A base class that will be used to describe the basic properties of any 
	object that we wish to place on the screen.

	Will contain its character, colour, coordinates and functions to return these values.
	They will also have setters just for future use.

*/

#ifndef OBJECT_H
#define OBJECT_H

#include<curses.h>
#include"MakeColors.h"

class Object
{
public:
	Object();
	Object(int zPos,int yPos, int xPos, char ch,chtype symbol);
	~Object();

	// Setting the properties of our object
	void setSymbol(chtype symbol);
	void setChar(char ch);
	void setXPos(int xPos);		
	void setYPos(int yPos);
	void setZPos(int zPos);

	// Get the properties of our object 
	chtype getSymbol();
	char getChar();
	int getXPos();
	int getYPos();
	int getZPos();

private:
	chtype character;
	char glyph;
	int x, y, z, colour;
};

#endif OBJECT_H


/*

	A base class that will be used to describe the basic properties of any 
	object that we wish to place on the screen.

	Will contain its character, colour, coordinates and functions to return these values.
	They will also have setters just for future use.

*/

#ifndef OBJECT_H
#define OBJECT_H

#include<curses.h>

class Object
{
public:
	Object();
	~Object();

	// Setting the properties of our object
	void setSymbol(chtype symbol); 
	void setXPos(int xPos);		
	void setYPos(int yPos);
	void setCol(int col);

	// Get the properties of our object 
	chtype getSymbol();
	int getXPos();
	int getYPos();
	int getCol();

private:
	chtype character;
	int x, y, colour;
};

#endif OBJECT_H

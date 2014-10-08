#include "Object.h"



Object::Object()
{ /* Default constructor */ }

Object::Object(int yPos, int xPos, chtype symbol)
{
	/* Every object needs a position, symbol and a colour */
	setXPos(xPos);
	setYPos(yPos);
	setSymbol(symbol);
	//setCol(colour);
}

Object::~Object()
{ /* Default Destructor */ }


// Setters 
void Object::setSymbol(chtype symbol){ character = symbol; }
void Object::setXPos(int xPos){ x = xPos; }
void Object::setYPos(int yPos){ y = yPos; }
//void Object::setCol(int col){ colour = col; }

// Getters 
chtype Object::getSymbol(){ return character; }
int Object::getXPos(){ return x; }
int Object::getYPos(){ return y; }
//int Object::getCol(){ return colour; }

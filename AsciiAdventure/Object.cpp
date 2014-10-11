#include "Object.h"



Object::Object()
{ /* Default constructor */ }

Object::Object(int zPos, int yPos, int xPos, chtype symbol)
{
	/* Every object needs a position, symbol and a colour */
	setXPos(xPos);
	setYPos(yPos);
	setZPos(zPos);
	setSymbol(symbol);
	//setCol(colour);
}

Object::~Object()
{ /* Default Destructor */ }


// Setters 
void Object::setSymbol(chtype symbol){ character = symbol; }
void Object::setXPos(int xPos){ x = xPos; }
void Object::setYPos(int yPos){ y = yPos; }
void Object::setZPos(int zPos){ z = zPos; }
//void Object::setCol(int col){ colour = col; }

// Getters 
chtype Object::getSymbol(){ return character; }
int Object::getXPos(){ return x; }
int Object::getYPos(){ return y; }
int Object::getZPos(){ return z; }
//int Object::getCol(){ return colour; }

#include "Object.h"



Object::Object()
{ /* Default constructor */ }

Object::Object(int zPos, int yPos, int xPos, char ch,chtype symbol)
{
	/* Every object needs a position, symbol and a colour */
	setXPos(xPos);
	setYPos(yPos);
	setZPos(zPos);
	setSymbol(symbol);
	setChar(ch);
}

Object::~Object()
{ /* Default Destructor */ }


// Setters 
void Object::setSymbol(chtype symbol){ character = symbol; }
void Object::setChar(char ch){ glyph = ch; }
void Object::setXPos(int xPos){ x = xPos; }
void Object::setYPos(int yPos){ y = yPos; }
void Object::setZPos(int zPos){ z = zPos; }


// Getters 
chtype Object::getSymbol(){ return character; }
char Object::getChar(){ return glyph; }
int Object::getXPos(){ return x; }
int Object::getYPos(){ return y; }
int Object::getZPos(){ return z; }


#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

// Setters 
void Object::setSymbol(chtype symbol){ character = symbol; }
void Object::setXPos(int xPos){ x = xPos; }
void Object::setYPos(int yPos){ y = yPos; }
void Object::setCol(int col){ colour = col; }

// Getters 
chtype Object::getSymbol(){ return character; }
int Object::getXPos(){ return x; }
int Object::getYPos(){ return y; }
int Object::getCol(){ return colour; }
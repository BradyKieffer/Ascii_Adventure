/*

	Currently used to control the properties of our screen

*/

#ifndef  SCREEN_H
#define SCREEN_H

#include<curses.h>

class Screen
{
public:
	
	Screen(); //Default constructor that is most likely to be used
	Screen(int height, int width);
	~Screen();
	
	int getHeight();
	int getWidth();
	
	void setHeight(int height);
	void setWidth(int width);

	void initWindow(); // Sets the window up for us 

private:
	WINDOW* gameWin;
	int screenHeight, screenWidth;

	
	bool checkSize(int size); //Just make sure the size is greater than 0

};

#endif // !1 SCREEN_H

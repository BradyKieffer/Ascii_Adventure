/*

	Base class for a screen

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
	
	WINDOW* getWin();
	void setWin(WINDOW* win);

	void setHeight(int height);
	void setWidth(int width);

	void initWindow(); // Sets the window up for us
	void initSubWin(WINDOW* rootWin, int startY, int startX); /*  Makes this a subwindow (like the HUD) */
	
	bool checkSize(int size); //Just make sure the size is greater than 0

private:
	int screenHeight, screenWidth;
	WINDOW* window;
};

#endif // !1 SCREEN_H

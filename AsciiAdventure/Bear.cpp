#include "Bear.h"


Bear::Bear()
{ /* Default Constructor */ }

Bear::Bear(int zPos, int yPos, int xPos) : Actor(zPos, yPos, xPos, 'B' | COLOR_PAIR(MakeColors::COL_BEAR) | A_BOLD)
{}


Bear::~Bear()
{ /* Default Destructor */ }

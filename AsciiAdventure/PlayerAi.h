#ifndef PLAYER_AI_H
#define PLAYER_AI_H

#include <vector>
#include "ActorAi.h"
#include "Map.h"

class PlayerAi :
	public ActorAi
{
public:
	PlayerAi();
	~PlayerAi();

	void onEnter(int& y, int& x, int deltaY, int deltaX, Map& map);

private:

	void dig(int y, int x, Map& map);
};
#endif


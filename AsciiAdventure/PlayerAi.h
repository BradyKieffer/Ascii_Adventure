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

	void onEnter(int& z, int& y, int& x,int deltaZ, int deltaY, int deltaX, Map& map);

private:

	void dig(int z, int y, int x, Map& map);
};
#endif


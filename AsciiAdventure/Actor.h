/*

	A generic class that handles a more 
	defined presence for an actor object

*/

#ifndef ACTOR_H
#define ACTOR_H

#include "Object.h"
#include "ActorAi.h"
#include "Map.h"

class Actor : 
	public Object
{
public:

	Actor();
	Actor(int yPos, int xPos, chtype symbol);
	~Actor();

	void setCoords(Map map);
	void onMove(Map map, int deltaY, int deltaX); /* Verifies the move for the actor */

	/* To be implemented at a later date */
	int getHp();
	int getStr();
	int getDef();
	
	void setHp(int hp);
	void setStr(float str);
	void setDef(float def);

	bool isLiving();
	void attack(Actor attacker, Actor defender);
	void modifyHP(int damage); /* Damages the given actor */
	
private:
	/* Stats for each actor */
	int hitPoints, strength, defense;
	
	bool isAlive;
	void die(); /* Called when hp <= 0 */

};

#endif

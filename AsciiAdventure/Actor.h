/*

	A generic class that handles a more 
	defined presence for an actor object

*/

#ifndef ACTOR_H
#define ACTOR_H

#include"Object.h"

class Actor : 
	public Object
{
public:

	Actor();
	Actor(int yPos, int xPos, chtype symbol);
	~Actor();

	/* To be implemented at a later date */
	int getHp();
	float getStr();
	float getDef();
	float getSpeed();
	
	void setHp(int hp);
	void setStr(float str);
	void setDef(float def);
	void setSpeed(float spd);

	void takeDamage(int damage); /* Damages the given actor */

	void attack(Actor attacker, Actor defender);
	
private:
	/* Stats for each actor */
	int hitPoints;
	float strength;
	float defense;
	float speed;
	
	bool isAlive;

	void die(); /* Called when hp <= 0 */

};

#endif

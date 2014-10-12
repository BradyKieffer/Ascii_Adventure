/*

	A generic class that handles a more 
	defined presence for an actor object

*/

#ifndef ACTOR_H
#define ACTOR_H

#include "Object.h"
#include "Map.h"

class Actor : 
	public Object
{
public:
	const int ACTOR_PRESENT = -1; /* If there is an actor present then the map will have this value */

	Actor();
	~Actor();

	Actor& operator=(const Actor& rhs);

	void setCoords(Map map);
	void onUpdate(Map& map); /* This function should be overloaded, it will be called on each
						actor object when it is their turn to move, by default it will
						just call onMove */
	void onMove(Map& map); /* Moves the actor in a random dir. */

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
	void dig(int z, int y, int x, Map& map); /* If the actor wants to dig through a wall */
	
private:
	void swap(Actor rhs);

	/* Stats for each actor */
	int hitPoints, strength, defense;
	
	bool isAlive;

	void die(); /* Called when hp <= 0 */

};

#endif

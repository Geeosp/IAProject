#ifndef GOAL_FUNCS
#define GOAL_FUNCS

class Bot;
#include "Item.h"



class Goal_Funcs
{
private:
	

public:

	//returns a value between 0 and 1 based on the bot's health. The better
	//the health, the higher the rating
	static float Health(Bot * _bot);

	static float Health(int _health);

	//returns a value between 0 and 1 based on the bot's closeness to the 
	//given item. the further the item, the higher the rating. If there is no
	//item of the given type present in the game world at the time this method
	//is called the value returned is 1
	static float DistanceToItem(Bot * _bot, ITEM_TYPE _type);


	//returns a value between 0 and 1 based on how much ammo the bot has for
	//the given weapon, and the maximum amount of ammo the bot can carry. The
	//closer the amount carried is to the max amount, the higher the score
	static float IndividualWeaponStrength(Bot * _bot, ITEM_TYPE _weaponType);


	//returns a value between 0 and 1 based on the total amount of ammo the
	//bot is carrying each of the weapons. Each of the weapons a bot can
	//pick up can contribute a to the score. 
	static float TotalWeaponStrength(Bot * _bot);

	static float clamp(float _value, float _min, float _max);
private:
	


	
};


#endif
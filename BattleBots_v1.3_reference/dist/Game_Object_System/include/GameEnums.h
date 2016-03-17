#ifndef GAMEENUMS_H
#define GAMEENUMS_H

#include "EnumName.h"

struct GameEnums : public EnumName
{
	GameEnums(GameEnums::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		BOT = 10000,
		WALL,
		LASER,
		BULLET,
		ITEM,
		EMPTY
	};


};



#endif
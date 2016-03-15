#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"
#include "GameEnums.h"

enum ITEM_TYPE
{
	HEALTH,
	LASER_AMMO,
	RIFLE_AMMO,
	ROCKET_AMMO

};

class Item : public GameObject
{

private:
	ITEM_TYPE type;

public:
	Item(ITEM_TYPE _type, const PhysicBody_Data &_data, GraphicsObject_Sprite * _sprite);
	~Item();

	void Update(const float _curTime);

	ITEM_TYPE getItemType();
};

#endif
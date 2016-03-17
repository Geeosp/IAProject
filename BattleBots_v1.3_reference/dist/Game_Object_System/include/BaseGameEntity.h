#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

#include "GameObject.h"
#include "GameEnums.h"
class Bot;

class BaseGameEntity : public GameObject
{


public:
	BaseGameEntity(const PhysicBody_Data &_data, GraphicsObject_Sprite * _sprite);
	~BaseGameEntity();

	void Update(const float _curTime);

	void setBotOwner(Bot * _bot);
	Bot * getBotOwner();

private:

	Bot * bot;
};


#endif
#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include "GameEnums.h"

class Wall : public GameObject
{

public:
	Wall(const PhysicBody_Data &_data, GraphicsObject_Sprite * _sprite);
	~Wall();

	void Update(const float _curTime);





};

#endif
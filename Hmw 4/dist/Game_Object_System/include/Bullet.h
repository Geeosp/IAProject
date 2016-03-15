#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Bot.h"

class Bullet : public GameObject
{
public:
	Bullet(const int _owner, const Vect &_dir, const float speed, const PhysicBody_Data &_data, GraphicsObject_Sprite * _Sprite, Weapon_Type _type);
	~Bullet();

	void Update(const float _curTime);

	int getOwnerID() {
		return bulletOwner;
	};

	Weapon_Type getType();

private:
	
	int bulletOwner;
	Weapon_Type type;
};


#endif
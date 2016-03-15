#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "Bullet.h"
#include "Vect.h"
#include "Texture.h"
#include "Image.h"


class BulletFactory
{
	friend class GameManager;
	friend class Bot;

private:
	BulletFactory();
	~BulletFactory();

	static BulletFactory * Instance();

	Texture * textImage;
	Image * bulletImage;

	static Bullet * CreateBullet(const int _owner, const Vect& pos, const Vect &dir, const float speed, Weapon_Type _type);

public:

	
};




#endif
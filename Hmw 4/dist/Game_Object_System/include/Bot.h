#ifndef BOT_H
#define BOT_H

#include "GraphNode.h"
#include "BaseGameEntity.h"
#include "GameEnums.h"
#include "Item.h"
class Timer;
class SpriteFont;

enum Weapon_Type
{
	PISTOL,
	LASER,
	ROCKET,
	RIFLE

};


__declspec(align(16)) class Bot
{
	friend class GameManager;
	friend class ContactManager;

public:
	Bot(PhysicBody_Data &_data, GraphicsObject_Sprite * _sprite);
	~Bot();

	void Update(const float _curTime);
	void Render(Camera * pCam);
	int Claim();
	bool Claimed();

	// World Location (Pixels)
	void MoveToPosition(Vect &pos);
	void RotateToAngle(const float _degrees);
	bool Fire(Weapon_Type weapon);



	

	int getID(){ return id; }

	float getBotSpeed();
	Vect getPos();

	int getRocketAmmo();
	int getLaserAmmo();
	int getRifleAmmo();

	int getHealth();

	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}
		void operator delete(void* p)
	{
		_mm_free(p);
	}

private:

	void Respawn(Vect &_pos);
	void PickUp(ITEM_TYPE _item);

	void addHealth();
	void addLaserAmmo();
	void addRifleAmmo();

	bool claimed;
	int id;
	bool canFire;

	int RocketAmmo;
	int LaserAmmo;
	int RifleAmmo;

	void FireRifle();
	void FireRocket();
	void FireLaser();
	void FirePistol();

	void Hit(Weapon_Type _weapon);



	float PistolCoolDown;
	float LaserCoolDown;
	float RifleCoolDown;
	float reload;

	Timer * timer;

	SpriteFont * healthDisplay;
	GraphicsObject_Sprite * laserSprite;

	int health;
	bool respawn;
	Vect respawnPos;

	bool drawLaser;
	float drawLaserCounter;
	


	BaseGameEntity * entity;

	

};


#endif
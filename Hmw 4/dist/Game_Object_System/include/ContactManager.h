#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactListener.h"
class Bot;
class Bullet;

// Listens and returns all collision detected by the Physics system
class ContactManager : public ContactListener
{

public:
	ContactManager();

	// Returns ContactInfo and ContactImpulse when two objects are colliding
	void OnCollision(const Contact_Info &_info, const Contact_Impulse &_impulse);

	// Returns ContactInfo at the first moment of collision
	void OnCollisionEnter(const Contact_Info &_info);

	// Return ContactInfo the last frame of the collision
	void OnCollisionExit(const Contact_Info &_info);

private:
	void HandleBullets(Bot * _bot, Bullet * bullet);
	void HandleBullets(Bullet * bulletA, Bullet * bulletB);
	void HandleBullets(Bullet * bullet);
};


#endif 
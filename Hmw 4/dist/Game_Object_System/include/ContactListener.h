#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "Box2D/Box2D.h"
#include "World.h"
#include "GameObject.h"

struct Contact_Info
{
	GameObject * Contact_A;
	GameObject * Contact_B;
};

struct Contact_Impulse
{
	float normalImpulse;
	float tangentImpulse;
};


class ContactListener : public b2ContactListener
{
public:
	ContactListener();

	virtual void OnCollisionEnter(const Contact_Info &_info);
	virtual void OnCollision(const Contact_Info &_info, const Contact_Impulse &_impulse);
	virtual void OnCollisionExit(const Contact_Info &_info);

private:

	void BeginContact(b2Contact * contact);

	void EndContact(b2Contact* contact);

	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);


	//void EndContact(b2Contact * contact)
	//{
	//	(void)contact;
	//};

	//void PreSolve(b2Contact * contact, const b2Manifold * oldManifold)
	//{
	//	(void)contact;
	//	(void)oldManifold;
	//};

	//void PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
	//{
	//	/////////////////
	//	// Change this to contact->GetFixtureA()->getBody()->getUserData();
	//	////////////////////

	//	if (impulse->normalImpulses[0] >= 1.0f)
	//	{
	//		GameObject * A = (GameObject *)contact->GetFixtureA()->GetUserData();
	//		GameObject * B = (GameObject *)contact->GetFixtureB()->GetUserData();


	//		assert(A != 0);
	//		assert(B != 0);

	//		GameObjName::Name nameA = GameObjName::Name(A->getName().value);
	//		GameObjName::Name nameB = GameObjName::Name(B->getName().value);

	//		if (nameA == GameObjName::Red)
	//		{
	//			A->Accept(B, impulse);
	//		}
	//		if (nameB == GameObjName::Red)
	//		{
	//			B->Accept(A, impulse);
	//		}
	//	}

	//	//(void)contact;
	//	(void)impulse;
	//};

};



#endif

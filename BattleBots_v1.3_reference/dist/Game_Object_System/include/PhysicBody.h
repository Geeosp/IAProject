#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include "GameObject.h"
#include "Box2D/Box2D.h"

const float PIXELSTOMETERS = 0.02f;
const float METERSTOPIXELS = 50.0f;

class GameObject;

enum PHYSICBODY_SHAPE_TYPE
{
	BOX,
	CIRCLE
};

enum PHYSICBODY_COLLISION_TYPE
{
	STATIC = 0,
	KINEMATIC,
	DYNAMIC
};

struct PhysicBody_Data
{

	bool active;
	Vect position;
	Vect localPosition = Vect(0.0f, 0.0f, 0.0f);
	Vect size;
	float density;
	float friction;
	float radius;
	float linearDamping;
	float angularDamping;
	float angle;
	bool fixedRotation;
	bool isSensor = false;
	PHYSICBODY_SHAPE_TYPE shape_type;
	PHYSICBODY_COLLISION_TYPE col_type;
	int groupIndex = 0;
};





class GameObject;

class PhysicBody
{



public:
	PhysicBody(const PhysicBody_Data &_data, GameObject * obj);
	~PhysicBody();

	// mutators
	void SetVelocity(Vect &vel);
	void SetAngularVelocity(const float _angularVel);
	
	void AddForce(Vect &force);
	void AddLinearImpulse(Vect &impulse);
	void AddTorque(const float force);
	void AddAngularImpulse(const float force);
	void Transform(Vect &pos, float angle);
	void Rotate(float angle);

	// accessors
	Vect getPosition();
	Vect getVelocity();
	float getAngle();
	float getMass();
	Vect getDirection();
	float getAngularVelocity();

	void Render(Camera * pCam);

	GameObject * getGameObj();



private:
	PhysicBody();

	// GameObject here is only used as a backpointer
	GameObject * gObj;

	b2Body * body;
	GraphicsObject_SpriteBox * debugSprite;


	b2Body * createBody(const PhysicBody_Data &_data);

};




#endif
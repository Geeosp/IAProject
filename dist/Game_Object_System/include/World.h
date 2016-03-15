#ifndef WORLD_H
#define WORLD_H

#include "Box2D/Box2D.h"
#include "RayCastCallBack.h"
#include "ContactListener.h"
#include "GameObject.h"
#include "Vect.h"
#include <vector>

class ContactListener;

struct RayCast_InData
{
	Vect p1;
	Vect p2;
};

struct RayCast_OutData
{
	std::vector<GameObject *> objs;
	std::vector<Vect> normals;
	std::vector<Vect> positions;

};


class World
{

public:
	static b2World * getWorld();

	static void destroyBody(b2Body * _body);

	static void Update();

	static bool RayCast(const RayCast_InData &_in, RayCast_OutData &_out);

	static void SetContactListener(ContactListener * _listener);

private:
	static World * privInstance();
	World();
	~World();

	b2World * world;
};







#endif
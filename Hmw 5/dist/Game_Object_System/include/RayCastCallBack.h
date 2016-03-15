#ifndef RAYCASTCALLBACK_H
#define RAYCASTCALLBACK_H

#include "Box2D/Box2D.h"
#include <vector>

class RayCastCallBack : public b2RayCastCallback
{

public:
	RayCastCallBack()
	{
	}

	/// Called for each fixture found in the query. You control how the ray cast
	/// proceeds by returning a float:
	/// return -1: ignore this fixture and continue
	/// return 0: terminate the ray cast
	/// return fraction: clip the ray to this point
	/// return 1: don't clip the ray and continue
	/// @param fixture the fixture hit by the ray
	/// @param point the point of initial intersection
	/// @param normal the normal vector at the point of intersection
	/// @return -1 to filter, 0 to terminate, fraction to clip the ray for
	/// closest hit, 1 to continue

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) {
		//m_fixture = fixture;
		//m_point = point;
		//m_normal = normal;
		//m_fraction = fraction;
		fixtures_Hit.push_back(fixture);
		points.push_back(point);
		normals.push_back(normal);
		fractions.push_back(fraction);

		// Change return for different behaviors
		return 1;
	}

	std::vector<b2Fixture *> fixtures_Hit;
	std::vector<b2Vec2> points;
	std::vector<b2Vec2> normals;
	std::vector<float32> fractions;
	//b2Fixture * m_fixture;
	//b2Vec2 m_point;
	//b2Vec2 m_normal;
	//float32 m_fraction;
};




#endif
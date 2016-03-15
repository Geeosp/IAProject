#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "AzulCore.h"
#include "EnumName.h"
#include "PhysicBody.h"

class PhysicBody;
struct PhysicBody_Data;


class GameObject
{
public:
	virtual void Update(const float _curTime) = 0;
	void UpdatePhysics();
	void Render(Camera * pCam);

	GameObject(EnumName::Name _type, const PhysicBody_Data &_data, GraphicsObject_Sprite * _Sprite);
	~GameObject();

	// Transform 
	void Scale(const Vect &_scale);
	void Rotate(const float _angle);
	void Translate(const Vect &_loc);

	Vect getPhysicalLocation();

	Vect getPosition();
	float getAngle();
	Vect getScale();

	void FlipSprite_Horz();

	GraphicsObject_Sprite * getSprite();
	PhysicBody * getBody();

	EnumName::Name getType();
	int getID();

	void Destroy();
	bool PendingDelete();

private:

	void pushPhysics();

	int flipHorz;

	int NextValidID(){ static int NextID = 0; return NextID++; }
	int id;

	bool deleted;


protected:

	EnumName::Name type_name;

	GraphicsObject_Sprite * pSprite;
	PhysicBody * body;




};






#endif
#pragma once
#ifndef GEEO_GRAPHNODE
#define GEEO_GRAPHNODE
#include "Vect.h"
#include "GraphicsObject_Sprite.h"
#include "Graphics_Man.h"
#include "GGraph.h"
class GGraphNode
{
public:
	GGraphNode(const int x, const int y, const int id);
	~GGraphNode();
	int getId();
	void render(Camera * pCam);
	void renderPath(Camera * pCam);
	Vect* getPos();

private:
	Vect* pos;
	int id;

	GraphicsObject_Sprite * sprite;

	GraphicsObject_Sprite * spritePath;




};


#endif


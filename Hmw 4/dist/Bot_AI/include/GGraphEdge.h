#pragma once
#ifndef GEEO_GRAPHEDGE
#define GEEO_GRAPHEDGE
#include "GGraphNode.h"
#include "Graphics_Man.h"
class GGraphNode;
class GGraphEdge
{
public:
	GGraphEdge(GGraphNode* from, GGraphNode* to);
	~GGraphEdge();
	void render(Camera * pCam);
	GGraphNode* from;
	GGraphNode* to;
	float getWeight();
private:
	float weight;
	GraphicsObject_Sprite * sprite;


};

#endif
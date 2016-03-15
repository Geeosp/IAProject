#ifndef NAVGRAPHEDGE_H
#define NAVGRAPHEDGE_H

#include "GraphEdge.h"
#include "Vect.h"
#include "NavGraphNode.h"

class Camera;
class GraphicsObject_SpriteBox;


class NavGraphEdge : public GraphEdge
{
private:
	// For Display
	Vect * pos;
	GraphicsObject_SpriteBox * sprite;


public:
	NavGraphEdge(const int _from, const int _to, const float _cost);
	NavGraphEdge(NavGraphNode * _toNode, NavGraphNode * _fromNode, const float _cost);
	NavGraphEdge(NavGraphNode * _toNode, NavGraphNode * _fromNode);
	~NavGraphEdge();

	void Update();
	void Render(Camera * pCam);

	Vect * getPos();

};

#endif
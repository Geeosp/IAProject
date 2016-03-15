#ifndef NAVGRAPHNODE_H
#define NAVGRAPHNODE_H

#include "GraphNode.h"
#include "Vect.h"

class GraphicsObject_Sprite;

class SpriteFont;
class Camera;

class NavGraphNode : public GraphNode
{

public:
	NavGraphNode(Vect &_pos);
	~NavGraphNode();

	void Update();
	void Render(Camera *pCam);

	Vect * getPos();
	Vect Pos()const{ return *pos; }


private:
	int NextValidID(){ static int NextID = 0; return NextID++; }

	GraphicsObject_Sprite * sprite;

	SpriteFont * display;

	Vect * pos;
};

#endif
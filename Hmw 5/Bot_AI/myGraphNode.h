#ifndef MYGRAPHNODE_H
#define MYGRAPHNODE_H

#include <vector>
#include "Vect.h"
#include "GraphicsObject_Sprite.h"

class myGraphEdge;

class myGraphNode
{

private:
	std::vector<myGraphEdge *> edges;

	Vect * pos;
	int nodeID;

	int NextValidID(){ static int NextID = 0; return NextID++; }

	GraphicsObject_Sprite * sprite;

public:
	myGraphNode(Vect * _pos);
	~myGraphNode();
	Vect * getPos();
	std::vector<myGraphEdge *> getEdges();

	void addEdge(myGraphEdge * _edge);

	void Render(Camera * pCam);


	int getID();
};


#endif



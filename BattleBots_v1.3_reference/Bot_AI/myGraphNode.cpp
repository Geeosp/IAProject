#include "myGraphNode.h"
#include "myGraphEdge.h"

#include "Graphics_Man.h"

myGraphNode::myGraphNode(Vect * _pos)
{
	pos = _pos;
	nodeID = NextValidID();

	Texture * text = new Texture("NavMeshNode.tga");
	Image * image = new Image(text, new Rect(0, 0, 64, 64));

	sprite = new GraphicsObject_Sprite(Graphics_Man::getModelSprite(),
		Graphics_Man::getShaderSprite(), image,
		new Rect(pos->X(), pos->Y(), 8, 8));

	Matrix world;
	Matrix RotZ;
	Matrix Scale;
	Matrix Trans;

	Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	RotZ.set(ROT_Z, 0.0f);
	Trans.set(TRANS, sprite->origPosX, sprite->origPosY, 0.0f);

	world = Scale * RotZ * Trans;
	sprite->SetWorld(world);
}

myGraphNode::~myGraphNode()
{
	for (std::vector<myGraphEdge *>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		delete *it;
	}
	edges.clear();
	delete pos;

	delete sprite;
}

std::vector<myGraphEdge *> myGraphNode::getEdges()
{
	return edges;
}

void myGraphNode::addEdge(myGraphEdge * _edge)
{
	edges.push_back(_edge);
}

int myGraphNode::getID()
{
	return nodeID;
}

void myGraphNode::Render(Camera * pCam)
{
	sprite->Render(pCam);
}

Vect * myGraphNode::getPos()
{
	return pos;
}
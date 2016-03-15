#pragma once
#ifndef  GEEOGRAPH
#define GEEOGRAPH


#include <map>
#include <vector>
#include "GGraphNode.h"
#include "GGraphEdge.h"
#include "GameManager.h"
#include "AStar.h"


class GGraphNode;
class GGraphEdge;
class AStar;
using namespace std;
class GGraph
{
public:
	GGraph();
	~GGraph();
	map<int, GGraphNode*> nodes;
	map<int,vector<GGraphEdge*>> edges;

	vector<Vect*> getPath(Vect* from, Vect* to);
	void render(Camera * pCam);
	static int getNodeId(const int x, const int y);
	static int getNodeId(const float x, const float y);

private:
	void buildGraph();
	//AStar astar;
};








#endif // ! GGraPH

#pragma once
#ifndef GEEO_ASTAR
#define GEEO_ASTAR
#include "GGraphNode.h"
#include "GeeoHeapNode.h"
#include "GeeoHeap.h"
#include "GGraph.h"
#include "GEdgeHeapNode.h"
#include <vector>
class GGraphNode;
class GGraphEdge;
class GeeoHeapNode;
class GEdgeHeapNode;


struct SearchState{
	float dist;
	bool closed;
	GGraphNode* from;
	SearchState(float dist, bool closed, GGraphNode* from){
		this->dist = dist;//distance to this node;
		this->closed = closed;//if the distance is final;
		this->from = from;//the node who leads to this distance
	}
};



class AStar
{
public:
	AStar();
	~AStar();
	static 	vector<GGraphNode*> getPath(GGraphNode* from, GGraphNode* target, map<int, GGraphNode*>* nodes,
	map<int, vector<GGraphEdge*>> *edges);


private:
	



};

#endif
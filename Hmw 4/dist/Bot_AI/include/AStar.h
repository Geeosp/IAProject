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
enum SearchStateList{
	OPEN,CLOSED
};

struct SearchState{
	float distFromNode0;
	float distFromNode0ToTarget;//heuristic
	SearchStateList state;
	GGraphNode* from;
	SearchState(GGraphNode* from, float distFromNode0, float distFromNode0ToTarget, SearchStateList state){
		this->distFromNode0 = distFromNode0;//distance to this node;
		this->distFromNode0ToTarget = distFromNode0ToTarget;
		this->state = state;//if the distance is final;
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
	static float AStar::calculateHeuristic(GGraphNode *from, GGraphNode* to);

private:
	



};

#endif
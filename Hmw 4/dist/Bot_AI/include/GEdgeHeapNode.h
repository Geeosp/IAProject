#pragma once
#ifndef GEEO_EDGEHEAPNODE
#define GEEO_EDGEHEAPNODE
#include "GeeoHeapNode.h"
#include "GGraphEdge.h"
class GGraphEdge;
class GGraphNode;

class GEdgeHeapNode :
	public GeeoHeapNode
{
public:
	GEdgeHeapNode();
	~GEdgeHeapNode();
	float getWeight();
	GEdgeHeapNode(GGraphEdge* edge, GGraphNode * target, float distToNode0);
	GGraphEdge* edge;//edge to be avaluated
	GGraphNode * target;//final node target
	float distToNode0;
private:
	//float calculateHeuristic();



};

#endif
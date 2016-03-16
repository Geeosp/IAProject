#include "GEdgeHeapNode.h"


GEdgeHeapNode::GEdgeHeapNode()
{
}


GEdgeHeapNode::~GEdgeHeapNode()
{
}


float GEdgeHeapNode::getWeight(){//weight to use in the heap
	return
		distToNode0
		+
		edge->getWeight()
		+
		AStar::calculateHeuristic(edge->from, edge->to);
		;
	}

GEdgeHeapNode:: GEdgeHeapNode(GGraphEdge* edge, GGraphNode * target, float distToNode0){
		this->edge = edge;
		this->target = target;
		this->distToNode0 = distToNode0;
	}



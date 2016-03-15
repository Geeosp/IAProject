#include "GEdgeHeapNode.h"


GEdgeHeapNode::GEdgeHeapNode()
{
}


GEdgeHeapNode::~GEdgeHeapNode()
{
}


float GEdgeHeapNode::getWeight(){//weight to use in the heap
		return edge->getWeight() + calculateHeuristic();
	}
GEdgeHeapNode:: GEdgeHeapNode(GGraphEdge* edge, GGraphNode * target){
		this->edge = edge;
		this->target = target;
	}


float GEdgeHeapNode::calculateHeuristic(){
		return (*target->getPos() - *edge->to->getPos()).mag();
	}
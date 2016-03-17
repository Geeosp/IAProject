#include "AStar.h"


AStar::AStar()
{
}


AStar::~AStar()
{
}

vector<GGraphNode*> AStar::getPath(GGraphNode* from, GGraphNode* target, map<int, GGraphNode*> *graphNodes,
	map<int, vector<GGraphEdge*>> *graphEdges){
	graphEdges;
	float geeo_infinite = FLT_MAX;
	GeeoHeap heap;
	map<int, SearchState> searchStates;
	vector<GGraphNode*> path;
	target;
	//init map of distances with infinite;
	
	for (std::map<int, GGraphNode* >::iterator it = graphNodes->begin(); it != graphNodes->end(); it++)
	{//for each node in graph, initialize its state with (infinite, not closed, firstNode)
		GGraphNode* node = it->second;
		SearchState d(from, geeo_infinite, geeo_infinite, SearchStateList::OPEN);
		searchStates.insert(std::pair<int, SearchState>(node->getId(), d));
	}
	SearchState* targetSearchState = &searchStates.find(target->getId())->second;
	//initialize the firstnode with (0, open, firstnode)
	SearchState* firstSearchState = &searchStates.find(from->getId())->second;
	firstSearchState->distFromNode0 = 0;
	firstSearchState->state = SearchStateList::OPEN;
	firstSearchState->distFromNode0ToTarget =AStar::calculateHeuristic(from, target);

	//initialize the heap with an edge from node0 to node0;
	GGraphEdge * zeroEdge = new GGraphEdge(from, from);
	GEdgeHeapNode * zeroHeapEdge = new GEdgeHeapNode(zeroEdge, target, 0);
	heap.add(zeroHeapEdge);

	//a star algorithm
//	bool found = false;
	while (!heap.isEmpty()&&targetSearchState->state!=SearchStateList::CLOSED){
		GEdgeHeapNode* heapNode = (GEdgeHeapNode* )heap.pop();
		GGraphEdge* edge = heapNode->edge;
		GGraphNode *currentNode = graphNodes->find(edge->to->getId())->second;
		SearchState * searchStateCurrent = &searchStates.find(currentNode->getId())->second;
		if (searchStateCurrent->state == SearchStateList::OPEN){
		//	DebugMsg::out("AStar trying node: %d\n", currentNode->getId());
			searchStateCurrent->state = SearchStateList::CLOSED;
			SearchState * searchStateFrom = &searchStates.find(edge->from->getId())->second;
			searchStateCurrent->distFromNode0 = searchStateFrom->distFromNode0 + edge->getWeight();
			vector<GGraphEdge*> nodeEdges = graphEdges->find(edge->to->getId())->second;
			for (unsigned int i = 0; i < nodeEdges.size(); i++){
				GGraphEdge* nodeEdge = nodeEdges[i];
				SearchState* searchStateNodeNeighbor = &searchStates.find(nodeEdge->to->getId())->second;
				if (searchStateNodeNeighbor->state == SearchStateList::OPEN)
				{
					GEdgeHeapNode* gehntmp = new GEdgeHeapNode(nodeEdge, target, searchStateCurrent->distFromNode0);
					heap.add(gehntmp);
					float distFromZeroToNeighbor = searchStateCurrent->distFromNode0 + nodeEdge->getWeight();
					if (distFromZeroToNeighbor < searchStateNodeNeighbor->distFromNode0){
						searchStateNodeNeighbor->from = currentNode;
						searchStateNodeNeighbor->distFromNode0 = searchStateCurrent->distFromNode0 + nodeEdge->getWeight();
					}
				}
			}
		
		}
	}

	if (targetSearchState->state == SearchStateList::CLOSED){
		vector<GGraphNode*> reversePath;
		GGraphNode* p = target;

		while (p != from){
			reversePath.push_back(p);
			//path.push_back(p);
			SearchState* s = &searchStates.find(p->getId())->second;
			p = s->from;
		}

		while (!reversePath.empty()){
			path.push_back(reversePath.back());
			reversePath.pop_back();
		}

	}


	return path;
}
float AStar::calculateHeuristic(GGraphNode *from, GGraphNode* to){
	return (*from->getPos() - *to->getPos()).magSqr();
}
#include "AStar.h"


AStar::AStar()
{
}


AStar::~AStar()
{
}

vector<GGraphNode*> AStar::getPath(GGraphNode* from, GGraphNode* target, map<int, GGraphNode*> *graphNodes,
	map<int, vector<GGraphEdge*>> *graphEdges){
	GeeoHeap heap;
	map<int, SearchState> searchStates;
	vector<GGraphNode*> path;
	target;
	//init map of distances with infinite;
	float infinite = FLT_MAX;
	for (std::map<int, GGraphNode* >::iterator it = graphNodes->begin(); it != graphNodes->end(); it++)
	{//for each node in graph, initialize its state with (infinite, not closed, firstNode)
		GGraphNode* node = it->second;
		SearchState d(infinite, false, from);
		searchStates.insert(std::pair<int, SearchState>(node->getId(), d));
	}
	//initialize the firstnode with (0, true, firstnode)
	searchStates.find(from->getId())->second.dist = 0;
	searchStates.find(from->getId())->second.from = from;
	searchStates.find(from->getId())->second.closed = true;



	GGraphNode* firstNode = from;
	//initialize the heap with all the first node edges
	vector<GGraphEdge*> firstNodeEdges = graphEdges->find(firstNode->getId())->second;
	for (unsigned int i = 0; i < firstNodeEdges.size(); i++){
		GEdgeHeapNode * gehn = new GEdgeHeapNode(firstNodeEdges.at(i), target);
		heap.add(gehn);
	}
	//a star algorithm
	bool found = false;
	while (!found&&!heap.isEmpty()){
		GEdgeHeapNode* heapNode = (GEdgeHeapNode* )heap.pop();
		GGraphEdge* edge = heapNode->edge;
		SearchState * searchStateFrom = &searchStates.find(edge->from->getId())->second;
		SearchState * searchStateTo = &searchStates.find(edge->to->getId())->second;

		//distance to Node, from the first node of the path to the edge.to.
		float distanceToNodeTo = searchStateFrom->dist+edge->getWeight();
		//if distanceToNode< distances.find(edge.to/id))
		if (distanceToNodeTo < searchStateTo->dist){
			searchStateTo->dist = distanceToNodeTo;
			searchStateTo->from = edge->from;
			searchStateTo->closed = true;
			
			vector<GGraphEdge*> nodeEdges = graphEdges->find(edge->to->getId())->second;
			for (unsigned int i = 0; i < nodeEdges.size(); i++){
				GEdgeHeapNode* gehntmp = new GEdgeHeapNode(nodeEdges.at(i), target);
				heap.add(gehntmp);
			}
		}
		if (edge->to->getId() == target->getId()){
			found = true;
		}
	}

	if (found){
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

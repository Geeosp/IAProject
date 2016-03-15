#include "myGraph.h"
#include "myGraphNode.h"
#include "myGraphEdge.h"
#include <assert.h>
#include "Camera.h"

myGraph::myGraph()
{
}

myGraph::~myGraph()
{
	for (std::map<int, myGraphNode *>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		delete it->second;
	}

	for (std::vector<myGraphEdge *>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		delete *it;
	}

	graph.clear();
	edges.clear();
}

int myGraph::numNodes()
{
	return graph.size();
}

void myGraph::addNode(myGraphNode * _node)
{
	graph.insert(std::pair<int, myGraphNode *>(_node->getID(), _node));
}

void myGraph::addEdge(myGraphNode * _start, myGraphNode * _end)
{
	myGraphEdge * newEdge = new myGraphEdge(_start, _end);

	edges.push_back(newEdge);

	_start->addEdge(newEdge);
	_end->addEdge(newEdge);

}

myGraphNode * myGraph::getClosestNodeToPosition(const Vect &_pos)
{
	myGraphNode * closestNodeSoFar = NULL;
	float closestDist = 100000.0f;

	
	for (std::map<int, myGraphNode *>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		//NavGraphNode * node = graph->GetNode(i);
		myGraphNode * node = it->second;
		Vect dir = _pos - *it->second->getPos();

		if (dir.mag() < closestDist)
		{
			closestDist = dir.mag();
			closestNodeSoFar = node;
		}
	}

	assert(closestNodeSoFar != NULL);
	return closestNodeSoFar;

}

std::map<int, myGraphNode*> myGraph::getGraph()
{
	return graph;
}

void myGraph::Render(Camera * _pCam)
{
	for (std::map<int, myGraphNode *>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		it->second->Render(_pCam);
	}
}



#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <map>
#include <vector>
#include "Vect.h"

class Camera;
class myGraphNode;
class myGraphEdge;

class myGraph
{
public:
	myGraph();
	~myGraph();

	void addNode(myGraphNode * _node);
	void addEdge(myGraphNode * _to, myGraphNode * _end);

	std::map<int, myGraphNode*> getGraph();

	int numNodes();

	myGraphNode * getClosestNodeToPosition(const Vect &_pos);

	void DFS(myGraphNode * _start, myGraphNode * _end);

	void Render(Camera * _pCam);

private:

	std::map<int, myGraphNode*> graph;
	std::vector<myGraphEdge *> edges;


};


#endif
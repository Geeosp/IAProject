#ifndef MYSEARCHALGORITHMS_H
#define MYSEARCHALGORITHMS_H


#include <vector>

class myGraphNode;
class myGraph;

class mySearchAlgorithms
{

public:
	std::vector<myGraphNode *> DFS(myGraph * _graph,
		myGraphNode * _start, myGraphNode * _end);

private:

};


#endif
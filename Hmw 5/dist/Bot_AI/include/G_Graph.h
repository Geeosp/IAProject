#pragma once
#ifndef  G_GRAPH
#define G_GRAPH


#include <map>
#include <vector>
#include "G_GraphNode.h"
#include "G_GraphEdge.h"
#include "GameManager.h"

using namespace std;
class G_Graph
{
public:
	G_Graph();
	~G_Graph();
	map<int, G_GraphNode> nodes;
	map<int,vector<G_GraphEdge>> edges;
	vector<G_GraphEdge*> getPath(G_GraphNode* from, G_GraphNode* to);

	int getNodeId(const int x, const int y);
private:
};








#endif // ! G_GRAPH

#include "GGraph.h"

const int minX= 40;
const int maxX= 1000;
const int intervalX= maxX - minX;
const int minY = 40;
const int maxY = 760;
const int intervalY=maxY-minY;
const int delta = 40;
const int deltaX = intervalX / delta;

GGraph::GGraph()
{
	buildGraph();
	
}


GGraph::~GGraph()
{
}

int GGraph::getNodeId(float x, float y){
	return getNodeId((int)x, (int)y);
}

int GGraph::getNodeId( int x,  int y){
		int id = -1;
	if (x > +40 && x < +1000 && y>40 && y < 760){
		int vx = x - 40;
		int vy = y - 40;
		int ax = vx / 40;
		int ay = vy / 40;
		id = 24 * ay + ax;
	}
//	DebugMsg::out("nodeId:%d\n", id);
	return id;
}

void GGraph::buildGraph()
{
	for (int x = 60; x < 1000; x += 40){
		for (int y = 60; y < 760; y += 40){
			int id = getNodeId(x, y);
			GGraphNode* node =new GGraphNode(x, y, id);
			nodes.insert(std::pair<int, GGraphNode*>(node->getId(), node));
		}
	}
	for (std::map<int, GGraphNode* >::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		GGraphNode* node = it->second;
		vector<Vect> points;
		/*
		Vect a(40, 0, 0);
		Vect b(-40, 0, 0);
		Vect c(0, 40, 0);
		Vect d(0, -40, 0);
		Vect e(40, 40, 0);
		Vect f(40, -40, 0);
		Vect a(-40, 40, 0);
		Vect a(-40,- 40, 0);
		*/
		float delta = 42.0f;
		points.push_back(*node->getPos() + *(new Vect(delta, 0.f, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(0.f, delta, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(-delta, 0.f, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(0.f, -delta, 0.f)));
		
		
		//diagonals
		points.push_back(*node->getPos() + *(new Vect(delta, delta, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(delta, -delta, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(-delta, delta, 0.f)));
		points.push_back(*node->getPos() + *(new Vect(-delta, -delta, 0.f)));
		/*
		*/
		Vect * pos = node->getPos();
		vector<GGraphEdge*> nodeEdges;
		Vect  v;
		for (unsigned int i = 0; i < points.size(); i++){
			v = points.at(i);
			if (!GameManager::isPathObstructed(0, *pos, v)){
				GGraphNode * from = node;
				GGraphNode * to = nodes.find(getNodeId((int)v.X(), (int)v.Y()))->second;
				if (!GameManager::isPathObstructed(0, *from->getPos(), *to->getPos())){
					nodeEdges.push_back(new GGraphEdge(from, to));
					//DebugMsg::out("edge from:%d to :%d \n", from->getId(), to->getId());
				}
			}
		}
		this->edges.insert(std::pair<int, vector<GGraphEdge*>>(node->getId(), nodeEdges));


	}
}

void GGraph::render(Camera * pCam) {
	for (std::map<int, GGraphNode* >::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		it->second->render(pCam);
	}
	
	for (std::map<int, vector<GGraphEdge*> >::iterator it = edges.begin(); it != edges.end(); it++)
	{
		vector<GGraphEdge*> nodeEdges = it->second;
		for (unsigned int i = 0; i < nodeEdges.size(); i++){
			nodeEdges.at(i)->render(pCam);
		}
	}
	
	/*
	for (unsigned int i = 0; i < edges.find(0)->second.size();i++){
		edges.find(0)->second.at(i)->render(pCam);
	}
	*/

}
list<Vect*> GGraph::getPath(Vect* from, Vect* to){
	from; to;
	list<Vect*> v;
	int fromId = getNodeId(from->X(), from->Y());
	int toId = getNodeId(to->X(), to->Y());
//	DebugMsg::out("trying to go :%d \n", fromId);
	GGraphNode* startNode = nodes.find(fromId)->second;
	GGraphNode* endNode = nodes.find(toId)->second;
	startNode;
	endNode;
	
	vector<GGraphNode*> nodesPath = AStar::getPath(startNode, endNode, &nodes,&edges);
	
	for (unsigned int i = 0; i < nodesPath.size(); i++){
		v.push_back(nodesPath.at(i)->getPos());
	}
	
	return v;


}
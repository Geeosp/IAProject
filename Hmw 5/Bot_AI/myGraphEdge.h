#ifndef MYGRAPHEDGE_H
#define MYGRAPHEDGE_H

class myGraphNode;

class myGraphEdge
{

private:
	myGraphNode * to;
	myGraphNode * from;


public:
	myGraphEdge(myGraphNode * _to, myGraphNode * _from);
	~myGraphEdge();

	myGraphNode * To();
	myGraphNode * From();

};




#endif
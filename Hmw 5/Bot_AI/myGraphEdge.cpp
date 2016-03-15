#include "myGraphEdge.h"


myGraphEdge::myGraphEdge(myGraphNode * _to, myGraphNode * _from)
{
	to = _to;
	from = _from;
}

myGraphEdge::~myGraphEdge()
{

}

myGraphNode * myGraphEdge::To()
{
	return to;
}

myGraphNode * myGraphEdge::From()
{
	return from;
}
#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

class GraphEdge
{

private:
	int indexFrom;
	int indexTo;

	float cost;

public:

	GraphEdge(const int _from, const int _to, const float _cost);
	GraphEdge(const int _from, const int _to);

	virtual ~GraphEdge(){}

	int From() const;
	void SetFrom(const int _index);

	int To() const;
	void SetTo(const int _index);

	float Cost() const;
	void SetCost(const float _cost);

};

#endif
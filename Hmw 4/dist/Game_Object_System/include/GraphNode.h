#ifndef GRAPHNODE_H
#define GRAPHNODE_H

enum 
{
	invalid_node_index = -1
};

class GraphNode
{

public:
	GraphNode();
	GraphNode(const int _index);
	virtual ~GraphNode(){};


	int Index() const;
	void SetIndex(const int newIndex);


protected:

	int index;



};

#endif
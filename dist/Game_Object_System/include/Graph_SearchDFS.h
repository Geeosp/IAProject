#ifndef GRAPH_SEARCH_DFS
#define GRAPH_SEARCH_DFS
#pragma warning (disable:4786)

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include "SparseGraph.h"

//----------------------------- Graph_SearchDFS -------------------------------
//
//  class to implement a depth first search. 
//-----------------------------------------------------------------------------
template<class graph_type>
class Graph_SearchDFS
{
private:

	//to aid legibility
	enum { visited, unvisited, no_parent_assigned };

	//create a typedef for the edge and node types used by the graph
	typedef typename graph_type::EdgeType Edge;
	typedef typename graph_type::NodeType Node;

private:

	//a reference to the graph to be searched
	const graph_type& m_Graph;

	//this records the indexes of all the nodes that are visited as the
	//search progresses
	std::vector<int>  m_Visited;

	//this holds the route taken to the target. Given a node index, the value
	//at that index is the node's parent. ie if the path to the target is
	//3-8-27, then m_Route[8] will hold 3 and m_Route[27] will hold 8.
	std::vector<int>  m_Route;

	//As the search progresses, this will hold all the edges the algorithm has
	//examined. THIS IS NOT NECESSARY FOR THE SEARCH, IT IS HERE PURELY
	//TO PROVIDE THE USER WITH SOME VISUAL FEEDBACK
	std::vector<const Edge*>  m_SpanningTree;

	//the source and target node indices
	int               m_iSource,	m_iTarget;

	//true if a path to the target has been found
	bool              m_bFound;


	//this method performs the DFS search
	bool Search();

public:

	Graph_SearchDFS(const graph_type& graph,
		int          source,
		int          target = -1) :

		m_Graph(graph),
		m_iSource(source),
		m_iTarget(target),
		m_bFound(false),
		m_Visited(m_Graph.NumNodes(), unvisited),
		m_Route(m_Graph.NumNodes(), no_parent_assigned)

	{

		m_bFound = Search();
	}

	Graph_SearchDFS& operator=(const Graph_SearchDFS&) {return *this;}

	//returns a vector containing pointers to all the edges the search has examined
	std::vector<const Edge*> GetSearchTree()const{ return m_SpanningTree; }

	//returns true if the target node has been located
	bool   Found()const{ return m_bFound; }

	//returns a vector of node indexes that comprise the shortest path
	//from the source to the target
	std::list<int> GetPathToTarget()const;
};

//-----------------------------------------------------------------------------
template <class graph_type>
bool Graph_SearchDFS<graph_type>::Search()
{
	//create a std stack of edges
	std::stack<const Edge*> stack;

	//create a dummy edge and put on the stack
	Edge Dummy(m_iSource, m_iSource, 0);

	stack.push(&Dummy);

	//while there are edges in the stack keep searching
	while (!stack.empty())
	{
		//grab the next edge
		const Edge* Next = stack.top();

		//remove the edge from the stack
		stack.pop();

		//make a note of the parent of the node this edge points to
		m_Route[Next->To()] = Next->From();

		//put it on the tree. (making sure the dummy edge is not placed on the tree)
		if (Next != &Dummy)
		{
			m_SpanningTree.push_back(Next);
		}

		//and mark it visited
		m_Visited[Next->To()] = visited;

		//if the target has been found the method can return success
		if (Next->To() == m_iTarget)
		{
			return true;
		}

		//push the edges leading from the node this edge points to onto
		//the stack (provided the edge does not point to a previously 
		//visited node)
		graph_type::ConstEdgeIterator ConstEdgeItr(m_Graph, Next->To());

		for (const Edge* pE = ConstEdgeItr.begin();
			!ConstEdgeItr.end();
			pE = ConstEdgeItr.next())
		{
			if (m_Visited[pE->To()] == unvisited)
			{
				stack.push(pE);
			}
		}
	}

	//no path to target
	return false;
}

//-----------------------------------------------------------------------------
template <class graph_type>
std::list<int> Graph_SearchDFS<graph_type>::GetPathToTarget()const
{
	std::list<int> path;

	//just return an empty path if no path to target found or if
	//no target has been specified
	if (!m_bFound || m_iTarget < 0) return path;

	int nd = m_iTarget;

	path.push_front(nd);

	while (nd != m_iSource)
	{
		nd = m_Route[nd];

		path.push_front(nd);
	}

	return path;
}




#endif
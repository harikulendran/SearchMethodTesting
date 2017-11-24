#pragma once

#include "TreeSearch.h"
#include <queue>

using namespace std;


struct LessThanByHeuristic {
	public:
		bool operator()(const NodeState lhs, const NodeState rhs) const;
};

template<class Container> class my_pq : public priority_queue<NodeState, vector<NodeState>, LessThanByHeuristic> {};

class AStar : public TreeSearch<my_pq> {
	public:
		AStar();
		void calculateF(NodeState* ns);
		int calculateH(Coord(&pieces)[NO_OF_PIECES]);
		void getCoords(NodeState* ns, Coord(&pieces)[NO_OF_PIECES]);
		
	protected:
		NodeState top();
};
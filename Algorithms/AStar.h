#pragma once

#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include <queue>

using namespace std;

struct LessThanByHeuristic {
	public:
		bool operator()(const NodeState lhs, const NodeState rhs) const;
};

class AStar {
	public:
		SearchOutput output{};
		NodeState current;
		priority_queue<NodeState, vector<NodeState>, LessThanByHeuristic> nodes;
		int nodeIndex = 0;

	public:
		AStar();

	public:
		SearchOutput search();
		void calculateF(NodeState* ns);
		int calculateH(Coord (&pieces)[NO_OF_PIECES]);
		void getCoords(NodeState* n, Coord (&pieces)[NO_OF_PIECES]);
};
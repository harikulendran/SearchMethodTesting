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
		NodeState current;
		priority_queue<NodeState, vector<NodeState>, LessThanByHeuristic> nodes;
		int nodeIndex = 0;

	public:
		AStar();

	public:
		void search(int q, int w, int e, int r);
		void calculateF(NodeState* ns);
		void getCoords(NodeState* n, Coord* a, Coord* b, Coord* c);
};
#pragma once

#include <stack>
#include "BlocksWorldBoard.h"
#include "NodeState.h"

using namespace std;

class DepthFirstSearch {
	public:
		SearchOutput output{};
		stack<NodeState> visitedNodes;
		BlocksWorldBoard bwBoard{};
		NodeState currentNode;
		int depth = 1;
		int nodeIndex = 0;
		bool complete = false;
		DepthFirstSearch(int ir = 0);
		SearchOutput search();
		SearchOutput search(int maxDepth);
		SearchOutput iterativeSearch(int initDepth, int maxDepth, int interval);
		void addRandomAdjacentNode();
};
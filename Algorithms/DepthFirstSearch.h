#pragma once

#include <stack>
#include "BlocksWorldBoard.h"
#include "NodeState.h"

using namespace std;

class DepthFirstSearch {
	public:
		stack<NodeState> visitedNodes;
		BlocksWorldBoard bwBoard{};
		NodeState currentNode;
		int depth = 1;
		int nodeIndex = 0;
		DepthFirstSearch();
		void search();
		bool search(int maxDepth);
		void iterativeSearch(int initDepth, int maxDepth, int interval);
		void addRandomAdjacentNode();
};
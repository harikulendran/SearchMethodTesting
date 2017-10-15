#pragma once

#include <stack>
#include "Tree.h"
#include "BlocksWorldBoard.h"
#include "NodeState.h"

using namespace std;

class DepthFirstSearch {
	public:
		stack<NodeState> visitedNodes;
		BlocksWorldBoard bwBoard{};
		shared_ptr<Tree> tree;
		NodeState currentNode;
		int depth = 1;
		DepthFirstSearch();
		void search();
		bool search(int maxDepth);
		void iterativeSearch(int initDepth, int maxDepth, int interval);
		void addRandomAdjacentNode(int noOfValidMoves);
		int getNoOfValidMoves();
};
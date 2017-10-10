#pragma once

#include <stack>
#include "Tree.h"
#include "BlocksWorldBoard.h"

using namespace std;

class DepthFirstSearch {
	public:
		stack<NodeState> visitedNodes;
		BlocksWorldBoard bwBoard{};
		shared_ptr<Tree> tree;
		int depth = 1;
		DepthFirstSearch();
		void search();
		NodeState getRandomAdjacentNode(int noOfValidMoves);
		NodeState getNextNode(int noOfValidMoves);
		int getNoOfValidMoves();
};
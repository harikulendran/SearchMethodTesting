#pragma once

#include "stdafx.h"
#include <stack>
#include "Tree.h"
#include "BlocksWorldBoard.h"

using namespace std;

class DepthFirstSearch {
	public:
		stack<int> visitedNodes;
		BlocksWorldBoard bwBoard{};
		shared_ptr<Tree> tree;
		int depth = 1;
		DepthFirstSearch();
		void search();
		int getRandomAdjacentNode(int noOfValidMoves);
		int getNoOfValidMoves();
};
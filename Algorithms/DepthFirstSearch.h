#pragma once

#include "stdafx.h"
#include <vector>
#include "Tree.h"
#include "BlocksWorldBoard.h"

using namespace std;

class DepthFirstSearch {
	public:
		vector<int> visitedNodes;
		BlocksWorldBoard bwBoard{};
		shared_ptr<Tree> tree;
		int count = 1;
		DepthFirstSearch();
		bool next();
		void search();
};
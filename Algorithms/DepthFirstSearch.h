#pragma once

#include "TreeSearch.h"
#include <stack>

class DepthFirstSearch : public TreeSearch<stack> {
	public:
		DepthFirstSearch(int i = 0, BlocksWorldBoard start = BlocksWorldBoard{});
	protected:
		NodeState top();
		void expandNode();
};
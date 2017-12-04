#pragma once

#include "TreeSearch.h"
#include <stack>

class IterativeDeepeningSearch : public TreeSearch<stack> {
	private:
		BlocksWorldBoard startBoard;
	public:
		IterativeDeepeningSearch(BlocksWorldBoard start = BlocksWorldBoard{});
		SearchOutput search(int maxDepth = INT32_MAX);
	protected:
		NodeState top();
};
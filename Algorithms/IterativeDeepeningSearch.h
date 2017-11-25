#pragma once

#include "TreeSearch.h"
#include <stack>

class IterativeDeepeningSearch : public TreeSearch<stack> {
	public:
		IterativeDeepeningSearch();
		SearchOutput search(int maxDepth = INT32_MAX);
	protected:
		NodeState top();
};
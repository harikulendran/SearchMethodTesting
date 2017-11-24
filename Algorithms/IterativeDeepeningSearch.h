#pragma once

#include "TreeSearch.h"
#include <stack>

class IterativeDeepeningSearch : public TreeSearch<stack> {
	public:
		IterativeDeepeningSearch();
		SearchOutput search(int maxDepth);
	protected:
		NodeState top();
};
#pragma once

#include "TreeSearch.h"
#include <stack>

class IterativeDeepeningSearch : public TreeSearch<stack> {
	public:
		SearchOutput search(int maxDepth);
	protected:
		NodeState top();
};
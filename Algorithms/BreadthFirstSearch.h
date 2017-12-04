#pragma once

#include "TreeSearch.h"
#include <queue>

class BreadthFirstSearch : public TreeSearch<std::queue> {
	public:
		BreadthFirstSearch(BlocksWorldBoard start = BlocksWorldBoard{});

	protected:
		NodeState top();
};
#pragma once

#include "TreeSearch.h"
#include <queue>


using namespace std;

class BreadthFirstSearch : public TreeSearch<std::queue> {
	public:
		BreadthFirstSearch();

	protected:
		NodeState top();
};
#pragma once

#include <queue>
#include "NodeState.h"
#include "BlocksWorldBoard.h"


using namespace std;


class BreadthFirstSearch {
	public:
		bool complete = false;
		queue <NodeState> treeNodes{};
		int nodeIndex = 0;
		NodeState completeNode;
		BreadthFirstSearch();
		~BreadthFirstSearch() = default;
		void search();
		void addCurrentNodeEdges();
		void showSolution();
};


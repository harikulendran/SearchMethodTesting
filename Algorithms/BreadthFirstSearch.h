#pragma once

#include "TreeSearch.h"
#include <queue>


using namespace std;

class BreadthFirstSearch : public TreeSearch<std::queue> {

protected:
	NodeState top();
	void calculateF(NodeState* ns);
};
/*
class BreadthFirstSearch {
	public:
		SearchOutput output{};
		bool complete = false;
		queue <NodeState> treeNodes{};
		int nodeIndex = 0;
		NodeState completeNode;

	public:
		BreadthFirstSearch();
		~BreadthFirstSearch() = default;

	public:
		SearchOutput search();
		void addCurrentNodeEdges();
		void showSolution();
};
*/
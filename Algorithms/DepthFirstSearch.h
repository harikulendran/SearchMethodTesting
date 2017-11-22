#pragma once

#include <stack>
#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include "TreeSearch.h"

using namespace std;

class DepthFirstSearch : public TreeSearch<stack> {
public:
	DepthFirstSearch(int i = 0);
protected:
	NodeState top();
	void calculateF(NodeState* ns);
	void expandNode();
};

/*
class DepthFirstSearch {
	public:
		SearchOutput output{};
		stack<NodeState> visitedNodes;
		BlocksWorldBoard bwBoard{};
		NodeState currentNode;
		int depth = 1;
		int nodeIndex = 0;
		bool complete = false;

	public:
		DepthFirstSearch(int ir = 0);

	public:
		SearchOutput search();
		SearchOutput search(int maxDepth);
		SearchOutput iterativeSearch(int initDepth, int maxDepth, int interval);
		void addRandomAdjacentNode();
};*/
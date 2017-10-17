#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
}

void DepthFirstSearch::search() {
	search(INT32_MAX);
}

void DepthFirstSearch::iterativeSearch(int initDepth, int maxDepth, int interval) {
	for (int i = initDepth; i < maxDepth; i += interval) {
		if (search(i))
			break;
	}
}

bool DepthFirstSearch::search(int maxDepth) {
	//push the root node to start
	visitedNodes.push(NodeState{0,-1,bwBoard});
	currentNode = visitedNodes.top();

	while (!visitedNodes.empty() && !currentNode.state.isSolved()) {
		if (currentNode.depth < maxDepth && !currentNode.expanded) {
			addRandomAdjacentNode();
			depth++;
		}
		else {
			visitedNodes.pop();
			if (!visitedNodes.empty())
				currentNode = visitedNodes.top();
		}
	}
	/*if (currentNode.state.isSolved()) {
		cout << "Depth reached: " << currentNode.depth << endl;
		cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
		//cout << "Number of edges in memory: " << tree->edgeSize() << endl;
		cout << "Final board: " << endl;
		currentNode.state.print();
	}*/
	return currentNode.state.isSolved();
}

void DepthFirstSearch::addRandomAdjacentNode() {
	visitedNodes.top().expanded = true;
	currentNode.state.checkMoves();
	int off = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[(i+off)%4]) {
			BlocksWorldBoard newState = BlocksWorldBoard{currentNode.state};
			newState.move(static_cast<Direction>((i + off)%4));
			visitedNodes.push(NodeState{ ++nodeIndex, currentNode.thisNode, newState, currentNode.depth + 1 });
			if (i == 3)
				currentNode = visitedNodes.top();
		}
	}
}
#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

/*DepthFirstSearch::DepthFirstSearch(int ir) {
	srand(time(NULL) + ir);
}

SearchOutput DepthFirstSearch::search() {
	return search(INT32_MAX);
}

SearchOutput DepthFirstSearch::iterativeSearch(int initDepth, int maxDepth, int interval) {
	for (int i = initDepth; i < maxDepth; i += interval) {
		search(i);
		if (complete)
			break;
	}
	return output;
}

SearchOutput DepthFirstSearch::search(int maxDepth) {
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
			output.nodesExpanded++;
			if (!visitedNodes.empty())
				currentNode = visitedNodes.top();
		}
	}
	complete = currentNode.state.isSolved();
	output.solnDepth = currentNode.depth;
	output.isOptimal = (output.solnDepth == 14);
	output.nodesInMemory = visitedNodes.size();
	output.maxNodesInMemory = output.nodesInMemory;
	return output;
}*/
DepthFirstSearch::DepthFirstSearch(int i) {
	srand(time(NULL) + i);
}

NodeState DepthFirstSearch::top() {
	return fringe.top();
}

void DepthFirstSearch::expandNode() {
	currentNode.state.checkMoves();
	int off = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[(i+off)%4]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{currentNode.state};
			newBoard.move(static_cast<Direction>((i + off)%4));
			fringe.push(NodeState{ ++nodeIndex, currentNode.thisNode, newBoard, currentNode.depth + 1 });
			if (i == 3)
				currentNode = top();
		}
	}
}

void DepthFirstSearch::calculateF(NodeState* ns) {
	return;
}
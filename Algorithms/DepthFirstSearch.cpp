#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

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
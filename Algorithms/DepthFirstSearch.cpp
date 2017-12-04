#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

//sets search name and initialises random number generator
DepthFirstSearch::DepthFirstSearch(int i, BlocksWorldBoard start) : TreeSearch(start) {
	//as the search runs ~9ms, time alone is not enough to act as a random
	//seed for concurrent runs
	srand(time(NULL) + i);
	searchName = "DFS";
	push(NodeState{ 0,-1,start });
}

//uses a stack
NodeState DepthFirstSearch::top() {
	return fringe.top();
}

//DFS overrides the expandNode function in order to add random expansion order
void DepthFirstSearch::expandNode() {
	currentNode.state.checkMoves();
	freq[currentNode.state.agent.x][currentNode.state.agent.y]++;
	output.nodesExpanded++;
	int off = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[(i+off)%4]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{currentNode.state};
			newBoard.move(static_cast<Direction>((i + off)%4));
			NodeState newNode{ ++nodeIndex, currentNode.thisNode, newBoard, currentNode.depth + 1 };
			newNode.dir = (i + off) % 4;
			push(newNode);

			//recordExpansion((i+off)%4,newBoard);
		}
	}
}
#include "TreeSearch.h"
#include <queue>

template <template<class> class Container> TreeSearch<Container>::TreeSearch() {
	fringe.push(NodeState root{ 0,-1,BlocksWorldBoard{} });
	
}


template <template<class> class Container> SearchOutput TreeSearch<Container>::search() {
	while (fringe.size() != 0) {
		currentNode = top();
		fringe.pop();
		output.nodesExpanded++;

		if (currentNode.state.isSolved()) {
			goalReached();
			return;
		}

		expandNode();
	}
}

template <template<class> class Container> void TreeSearch<Container>::goalReached() {
	output.solnDepth = currentNode.depth;
	output.isOptimal = (output.solnDepth == 14 + BOARD_SIZE - 4);
	output.nodesInMemory = fringe.size();
}

template <template<class> class Container> void TreeSearch<Container>::expandNode() {
	currentNode.state.checkMoves();
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[i]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard(currentNode.state);
			newBoard.move(static_cast<Direction>(i));
			fringe.push(NodeState{ ++nodeIndex,currentNode.thisNode,move(newBoard),currentNode.depth + 1 });
		}
	}
}
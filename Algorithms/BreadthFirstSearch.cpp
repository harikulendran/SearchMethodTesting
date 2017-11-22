#include "BreadthFirstSearch.h"
/*
BreadthFirstSearch::BreadthFirstSearch() {
	//tree = make_shared<Tree>();
	treeNodes.push(NodeState{ 0,-1,BlocksWorldBoard{} });
}

SearchOutput BreadthFirstSearch::search() {
	while (!complete)
		addCurrentNodeEdges();
	output.solnDepth = completeNode.depth;
	output.isOptimal = (output.solnDepth == 14);
	output.nodesInMemory = treeNodes.size();
	return output;
}

void BreadthFirstSearch::addCurrentNodeEdges() {
	//get the earliest node and remove it from the queue
	NodeState current = treeNodes.front();
	treeNodes.pop();
	output.nodesExpanded++;
	output.maxNodesInMemory = (output.maxNodesInMemory < treeNodes.size()) ? treeNodes.size() : output.maxNodesInMemory;

	//expand the available directions
	current.state.checkMoves();
	for (int i = 0; i < 4; i++) {
		if (current.state.validMoves[i]) {
			//save the state of the board at each node and add them to the queue
			BlocksWorldBoard newBoard = BlocksWorldBoard(current.state);
			newBoard.move(static_cast<Direction>(i));
			treeNodes.push(NodeState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth+1 });

			//when solution is found, stop
			if (newBoard.isSolved()) {
				complete = true;
				completeNode = treeNodes.back();
				return;
			}
		}
	}
}
*/

void BreadthFirstSearch::calculateF(NodeState* ns) {
	return;
}

NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
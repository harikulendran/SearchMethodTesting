#include "BreadthFirstSearch.h"

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
	/*cout << "Depth: " << completeNode.depth << endl;
	completeNode.state.print();
	cout << "Printing Steps:" << endl;*/
	//showSolution();
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
				//cout << treeNodes.size() << endl;
				return;
			}
		}
	}
}

/*
void BreadthFirstSearch::showSolution() {
	vector<BlocksWorldBoard> sol{};
	int curInd = completeNode.thisNode;
	while (curInd != -1) {
		Node* cn = tree->getNode(curInd);
		sol.push_back(cn->state);
		curInd = cn->parentIndex;
	}

	for (int i = sol.size() - 1; i > -1; i--) {
		sol[i].print();
	}
}*/
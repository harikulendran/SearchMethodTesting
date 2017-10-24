#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
	//tree = make_shared<Tree>();
	treeNodes.push(NodeState{ 0,-1,BlocksWorldBoard{} });
}

void BreadthFirstSearch::search() {
	while (!complete)
		addCurrentNodeEdges();
	/*cout << "Depth: " << completeNode.depth << endl;
	completeNode.state.print();
	cout << "Printing Steps:" << endl;*/
	//showSolution();
}

void BreadthFirstSearch::addCurrentNodeEdges() {
	//get the earliest node and remove it from the queue
	NodeState current = treeNodes.front();
	treeNodes.pop();

	//expand the available directions
	current.state.checkMoves();
	for (int i = 0; i < 4; i++) {
		if (current.state.validMoves[i]) {
			//save the state of the board at each node and add them to the queue
			BlocksWorldBoard newBoard = BlocksWorldBoard(current.state);
			newBoard.move(static_cast<Direction>(i));
			//tree->addNode(current.thisNode, tree->getNode(current.thisNode)->depth + 1);
			treeNodes.push(NodeState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth+1 });

			//when solution is found, stop
			if (newBoard.isSolved()) {
				complete = true;
				completeNode = treeNodes.back();
				cout << completeNode.depth << endl;
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
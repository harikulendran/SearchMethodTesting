#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
	tree = make_shared<Tree>();
	treeNodes.push(NodeState{ 0,-1,BlocksWorldBoard{} });
}

void BreadthFirstSearch::search() {
	while (!complete)
		addCurrentNodeEdges();
	//cout << "Depth: " << tree->getNode(completeNode.thisNode)->depth << endl;
	//completeNode.state.print();
	//cout << "Printing Steps:" << endl;
	//showSolution();
}

void BreadthFirstSearch::addCurrentNodeEdges() {
	//get the earliest node and remove it from the queue
	NodeState current = treeNodes.front();
	treeNodes.pop();

	//expand the available directions
	current.state.checkMoves();
	for (auto const& x : current.state.validMoves) {
		if (x.second) {
			//save the state of the board at each node and add them to the queue
			BlocksWorldBoard newBoard = BlocksWorldBoard(current.state);
			newBoard.move(x.first);
			int nextNode = tree->nodeSize();
			tree->addNode(nextNode, current.thisNode, tree->getNode(current.thisNode)->depth + 1);
			treeNodes.push(NodeState{ nextNode, current.thisNode, newBoard });

			//when solution is found, stop
			if (newBoard.isSolved()) {
				complete = true;
				completeNode = treeNodes.back();
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
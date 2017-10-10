#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
	tree = make_shared<Tree>();
	treeNodes = new queue<NodeState>();
	treeNodes->push(NodeState{ 0, BlocksWorldBoard{} });
}

void BreadthFirstSearch::search() {
	while (!complete)
		addCurrentNodeEdges();
	cout << "Depth: " << tree->getNode(completeNode.node)->depth << endl;
	completeNode.state.print();
}

void BreadthFirstSearch::addCurrentNodeEdges() {
	//get the earliest node and remove it from the queue
	NodeState current = treeNodes->front();
	treeNodes->pop();

	//expand the available directions
	current.state.checkMoves();
	for (auto const& x : current.state.validMoves) {
		if (x.second) {
			//save the state of the board at each node and add them to the queue
			BlocksWorldBoard newBoard = BlocksWorldBoard(current.state);
			newBoard.move(x.first);
			int nextNode = tree->nodeSize();
			tree->addNode(nextNode, tree->getNode(current.node)->depth + 1);
			treeNodes->push(NodeState{ nextNode, newBoard });

			//when solution is found, stop
			if (newBoard.isSolved()) {
				complete = true;
				completeNode = treeNodes->back();
				return;
			}
		}
	}
}

NodeState::NodeState(int i, BlocksWorldBoard s) : node(i), state(s) {}
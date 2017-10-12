#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
	tree = make_shared<Tree>(BlocksWorldBoard{});
	treeNodes = new queue<int>();
	treeNodes->push(0);
}

BreadthFirstSearch::~BreadthFirstSearch() {
	delete treeNodes;
	treeNodes = nullptr;
}

void BreadthFirstSearch::search() {
	while (!complete)
		addCurrentNodeEdges();
	cout << "Depth: " << tree->getNode(completeNode)->depth << endl;
	tree->getNode(completeNode)->state.print();
	cout << "Printing Steps:" << endl;
	showSolution();
}

void BreadthFirstSearch::addCurrentNodeEdges() {
	//get the earliest node and remove it from the queue
	Node* current = tree->getNode(treeNodes->front());
	treeNodes->pop();

	//expand the available directions
	current->state.checkMoves();
	for (auto const& x : current->state.validMoves) {
		if (x.second) {
			//save the state of the board at each node and add them to the queue
			BlocksWorldBoard newBoard = BlocksWorldBoard(current->state);
			newBoard.move(x.first);
			int nextNode = tree->nodeSize();
			tree->addNode(nextNode, current->index, newBoard, current->depth + 1);
			treeNodes->push(nextNode);

			//when solution is found, stop
			if (newBoard.isSolved()) {
				complete = true;
				completeNode = treeNodes->back();
				return;
			}
		}
	}
}

void BreadthFirstSearch::showSolution() {
	vector<BlocksWorldBoard> sol{};
	int curInd = completeNode;
	while (curInd != -1) {
		Node* cn = tree->getNode(curInd);
		sol.push_back(cn->state);
		curInd = cn->parentIndex;
	}

	for (int i = sol.size() - 1; i > -1; i--) {
		sol[i].print();
	}
}
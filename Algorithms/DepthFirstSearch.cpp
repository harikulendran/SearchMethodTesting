#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
	tree = make_shared<Tree>(bwBoard);
}

void DepthFirstSearch::search() {
	search(INT32_MAX);
}

void DepthFirstSearch::iterativeSearch(int initDepth, int maxDepth, int interval) {
	for (int i = initDepth; i < maxDepth; i += interval) {
		if (search(i))
			break;
	}
}

bool DepthFirstSearch::search(int maxDepth) {
	//push the root node to start
	visitedNodes.push(0);

	while (!visitedNodes.empty() && !bwBoard.isSolved()) {
		int noOfValidMoves = getNoOfValidMoves();
		if (noOfValidMoves > 0 && tree->currentNode->depth < maxDepth) {
			addRandomAdjacentNode(noOfValidMoves);
			depth++;
		} else {
			delete tree->getNode(visitedNodes.top());
			visitedNodes.pop();
			tree->currentNode = tree->getNode(visitedNodes.top());
			bwBoard = tree->currentNode->state;
		}
	}
	
	cout << "Depth reached: " << tree->getNode(visitedNodes.top())->depth << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	return bwBoard.isSolved();
}

int DepthFirstSearch::getNoOfValidMoves() {
	bwBoard.checkMoves();
	int noOfValidMoves = 0;

	int d = tree->getNode(visitedNodes.top())->depth;
	//expand tree
	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			noOfValidMoves++;
			int nextNode = tree->nodeSize();
			BlocksWorldBoard newState = BlocksWorldBoard{ bwBoard };
			newState.move(x.first);
			tree->addNode(nextNode, tree->currentNode->index, newState, d + 1);
			tree->currentNode->addEdge(tree->getNode(nextNode), x.first);
		}
	return noOfValidMoves;
}


void DepthFirstSearch::addRandomAdjacentNode(int noOfValidMoves) {
	int randomIndex = rand() % noOfValidMoves;
	for (int i = 0; i < noOfValidMoves; i++) {
		Edge e = tree->currentNode->edges[(randomIndex + i) % tree->currentNode->edges.size()];
		visitedNodes.push(e.n1->index);
		if (i == noOfValidMoves - 1) {
			tree->currentNode = e.n1;
			bwBoard = e.n1->state;
		}
	}
}
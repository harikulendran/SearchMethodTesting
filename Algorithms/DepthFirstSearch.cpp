#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
	tree = make_shared<Tree>(bwBoard);
}

void DepthFirstSearch::search() {
	//push the root node to start
	visitedNodes.push(0);

	while (!visitedNodes.empty() && !bwBoard.isSolved()) {
		int noOfValidMoves = getNoOfValidMoves();
		if (noOfValidMoves > 0) {
			addRandomAdjacentNode(noOfValidMoves);
			depth++;
		} else
			visitedNodes.pop();
	}
	
	/*cout << "Depth reached: " << tree->getNode(visitedNodes.top())->depth << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	*/
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
			tree->addNode(nextNode, tree->currentNode->index, BlocksWorldBoard{ bwBoard }, d + 1);
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
			bwBoard.move(e.dir);
		}
	}
}

/*
int DepthFirstSearch::getRandomAdjacentNode(int noOfValidMoves) {
	//select a random adjacent direction
	int randomIndex = rand() % noOfValidMoves;
	Direction randomDir = Direction::NA;
	int localCount = 0;

	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			if (localCount == randomIndex) {
				randomDir = x.first;
				break;
			}
			localCount++;
		}

	//return random adjacent node
	for (Edge e : tree->currentNode->edges)
		if (e.dir == randomDir) {
			tree->currentNode = e.n1;
			bwBoard.move(e.dir);
			//e.traversed = true;
			return e.n1->index;
		}
	return -1;
}
*/

int DepthFirstSearch::getNextNode(int noOfValidMoves) {

}
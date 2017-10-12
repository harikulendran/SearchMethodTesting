#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
	tree = make_shared<Tree>();
}

void DepthFirstSearch::search() {
	//push the root node to start
	visitedNodes.push(NodeState{0,BlocksWorldBoard(bwBoard)});

	while (!visitedNodes.empty() && !bwBoard.isSolved()) {
		int noOfValidMoves = getNoOfValidMoves();
		if (noOfValidMoves > 0) {
			NodeState randomNode = getRandomAdjacentNode(noOfValidMoves);
			visitedNodes.push(randomNode);
			depth++;
		} else
			visitedNodes.pop();
	}
	/*
	cout << "Depth reached: " << tree->getNode(visitedNodes.top().node)->depth << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	*/
}

int DepthFirstSearch::getNoOfValidMoves() {
	bwBoard.checkMoves();
	int noOfValidMoves = 0;

	int d = tree->getNode(visitedNodes.top().node)->depth;
	//expand tree
	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			noOfValidMoves++;
			int nextNode = tree->nodeSize();
			tree->addNode(nextNode, tree->currentNode->index, d+1);
			tree->currentNode->addEdge(tree->getNode(nextNode), x.first);
		}
	return noOfValidMoves;
}

NodeState DepthFirstSearch::getRandomAdjacentNode(int noOfValidMoves) {
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
			e.traversed = true;
			return NodeState{ e.n1->index, BlocksWorldBoard{bwBoard} };
		}
	return NodeState{ -1,BlocksWorldBoard{} };
}

NodeState DepthFirstSearch::getNextNode(int noOfValidMoves) {

}
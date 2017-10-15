#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"
#include <climits>

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
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
	tree = make_shared<Tree>();
	//push the root node to start
	visitedNodes.push(NodeState{0,-1,bwBoard});
	currentNode = visitedNodes.top();

	while (!visitedNodes.empty() && !currentNode.state.isSolved()) {
		if (tree->getNode(currentNode.thisNode)->depth < maxDepth && !currentNode.expanded) {
			int noOfValidMoves = getNoOfValidMoves();
			addRandomAdjacentNode(noOfValidMoves);
			depth++;
		}
		else {
			tree->nodes.erase(visitedNodes.top().thisNode);
			visitedNodes.pop();
			if (!visitedNodes.empty())
				currentNode = visitedNodes.top();
		}
	}
	if (currentNode.state.isSolved()) {
		cout << "Depth reached: " << tree->getNode(currentNode.thisNode)->depth << endl;
		cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
		cout << "Number of edges in memory: " << tree->edgeSize() << endl;
		cout << "Final board: " << endl;
		currentNode.state.print();
	}
	return currentNode.state.isSolved();
}

int DepthFirstSearch::getNoOfValidMoves() {
	//bwBoard.checkMoves();
	currentNode.state.checkMoves();
	int noOfValidMoves = 0;

	int d = tree->getNode(currentNode.thisNode)->depth;
	//expand tree
	for (auto const& x : currentNode.state.validMoves)
		if (x.second) {
			noOfValidMoves++;
			//BlocksWorldBoard newState = BlocksWorldBoard{ bwBoard };
			//newState.move(x.first);
			int nextNode = tree->nodeIndex;
			tree->addNode(currentNode.thisNode, d + 1);
			tree->getNode(currentNode.thisNode)->addEdge(nextNode, x.first);
		}

	return noOfValidMoves;
}


void DepthFirstSearch::addRandomAdjacentNode(int noOfValidMoves) {
	int randomIndex = rand() % noOfValidMoves;
	visitedNodes.top().expanded = true;
	for (int i = 0; i < noOfValidMoves; i++) {
		Edge e = tree->getNode(currentNode.thisNode)->edges[(randomIndex + i) % tree->getNode(currentNode.thisNode)->edges.size()];
		BlocksWorldBoard newState = BlocksWorldBoard{ currentNode.state };
		newState.move(e.dir);
		visitedNodes.push(NodeState{e.n1, tree->getNode(e.n1)->parentIndex, newState});
		if (i == noOfValidMoves - 1) {
			currentNode = visitedNodes.top();
		}
	}
}
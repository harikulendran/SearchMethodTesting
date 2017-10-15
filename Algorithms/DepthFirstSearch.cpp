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
	//cout << "Number of edges in memory PRESET: " << tree->edgeSize() << endl;
	tree = make_shared<Tree>();
	cout << "Number of edges in memory POSTSET: " << tree->edgeSize() << endl;
	//push the root node to start
	visitedNodes.push(NodeState{0,-1,bwBoard});
	currentNode = visitedNodes.top();

	while (!visitedNodes.empty() && !currentNode.state.isSolved()) {
		int noOfValidMoves = getNoOfValidMoves();
		if (noOfValidMoves > 0 && tree->getNode(currentNode.thisNode)->depth < maxDepth && !currentNode.expanded) {
			addRandomAdjacentNode(noOfValidMoves);
			depth++;
		}
		else {
			//palce
			delete tree->nodes[currentNode.thisNode];
			visitedNodes.pop();
			if (!visitedNodes.empty())
				currentNode = visitedNodes.top();
		}
	}
	
	cout << "Depth reached: " << tree->getNode(currentNode.thisNode)->depth << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	currentNode.state.print();
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
			int nextNode = tree->nodeSize();
			//BlocksWorldBoard newState = BlocksWorldBoard{ bwBoard };
			//newState.move(x.first);
			tree->addNode(nextNode, currentNode.thisNode, d + 1);
			tree->getNode(currentNode.thisNode)->addEdge(tree->getNode(nextNode), x.first);
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
		visitedNodes.push(NodeState{e.n1->index, e.n1->parentIndex, newState});
		if (i == noOfValidMoves - 1) {
			currentNode = visitedNodes.top();
		}
	}
}
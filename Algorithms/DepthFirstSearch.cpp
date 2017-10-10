#include "stdafx.h"

#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
	tree = make_shared<Tree>();
}

/*void DepthFirstSearch::search() {
	while (!next()) {}
	cout << "Depth reached: " << count << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	int qqq;
	cin >> qqq;
}*/

void DepthFirstSearch::search() {
	//push the root node to start
	visitedNodes.push(0);

	while (!visitedNodes.empty() && !bwBoard.isSolved()) {
		int noOfValidMoves = getNoOfValidMoves();
		if (noOfValidMoves > 0) {
			int randomNode = getRandomAdjacentNode(noOfValidMoves);
			visitedNodes.push(randomNode);
			depth++;
		} else
			visitedNodes.pop();
	}
	cout << "Depth reached: " << depth << endl;
	cout << "Number of nodes in memory: " << visitedNodes.size() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	int qqq;
	cin >> qqq;
}

int DepthFirstSearch::getNoOfValidMoves() {
	bwBoard.checkMoves();
	int noOfValidMoves = 0;

	//expand tree
	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			noOfValidMoves++;
			int nextNode = tree->nodeSize();
			tree->addNode(nextNode, depth);
			tree->currentNode->addEdge(tree->getNode(nextNode), x.first);
		}
	return noOfValidMoves;
}

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
			return e.index;
		}
	return -1;
}

/*
bool DepthFirstSearch::next() {
	bwBoard.checkMoves();
	int vm = 0;
	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			vm++;
			int index = tree->nodeSize();
			tree->addNode(index, count);
			tree->currentNode->addEdge(tree->getNode(index), x.first);
		}

	count++;
	cout << count << endl;
	int selected = rand() % vm;
	vm = 0;
	Direction dir(Direction::NA);

	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			if (vm == selected) {
				dir = x.first;
				break;
			}
			vm++;
		}
	
	for (Edge e : tree->currentNode->edges) {
		if (e.dir == dir) {
			tree->currentNode = e.n1;
			visitedNodes.push_back(e.index);
			bwBoard.move(e.dir);
			break;
		}
	}

	//if (count == 500)
		//return true;

	return (bwBoard.isSolved());
}
*/
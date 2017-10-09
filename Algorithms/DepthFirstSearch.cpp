#include "stdafx.h"

#include "DepthFirstSearch.h"
#include "stdlib.h"
#include "time.h"

DepthFirstSearch::DepthFirstSearch() {
	srand(time(NULL));
	tree = make_shared<Tree>();
}

void DepthFirstSearch::search() {
	while (!next()) {}
	cout << "Depth reached: " << count << endl;
	cout << "Number of nodes in memory: " << tree->nodeSize() << endl;
	cout << "Number of edges in memory: " << tree->edgeSize() << endl;
	cout << "Final board: " << endl;
	bwBoard.print();
	int qqq;
	cin >> qqq;
}

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
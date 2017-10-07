#include "stdafx.h"

#include "DepthFirstSearch.h"
#include "stdlib.h"

DepthFirstSearch::DepthFirstSearch() {

}

void DepthFirstSearch::search() {
	while (!next()) {}
	cout << "Depth reached: " << count << endl;
	cout << "Number of nodes in memory: " << tree.nodeSize() << endl;
	cout << "Number of edges in memory: " << tree.edgeSize() << endl;
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
			int index = tree.nodeSize();
			tree.addNode(index, count);
			tree.currentNode->addEdge(tree.getSNode(index), x.first);
		}

	count++;
	int selected = rand() % vm;
	vm = 0;
	Direction dir;

	for (auto const& x : bwBoard.validMoves)
		if (x.second) {
			vm++;
			if (vm == selected)
				dir = x.first;
		}
	
	for (Edge e : tree.currentNode->edges)
		if (e.dir == dir) {
			tree.currentNode = e.n1;
			visitedNodes.push_back(e.index);
			bwBoard.move(e.dir);
		}

	return (bwBoard.isSolved());
}
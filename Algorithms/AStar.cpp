#include "AStar.h"
#include <cmath>

bool LessThanByHeuristic::operator()(const NodeState lhs, const NodeState rhs) const {
	return lhs.h > rhs.h;
}

AStar::AStar() {
}

void AStar::search() {
	int count = 1;
	NodeState root{0};
	calculateF(&root);
	nodes.push(move(root));
	current = nodes.top();

	while (!nodes.empty()) {
		if (current.state.isSolved()) {
			//cout << "No of nodes: " << nodes.size() << endl << "no of expanded: " << count << endl;
			//cout << current.depth << endl;
			break;
		}
		nodes.pop();
		/*if (current.depth < 5) {
			cout << current.depth << " -> " << current.G << endl;
		}*/
		count++;

		current.state.checkMoves();
		for (int i = 0; i < 4; i++) {
			if (current.state.validMoves[i]) {
				BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
				newBoard.move(static_cast<Direction>(i));
				NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
				calculateF(&newState);
				nodes.push(move(newState));
			}
		}
		current = nodes.top();
	}

	/*cout << current->depth << endl;
	cout << "Nodes in fringe: " << nodes.size() << endl;
	current->state.print();*/
}

void AStar::calculateF(NodeState* ns) {
	Coord A, B, C, a;
	Coord sA{ 1,1 }, sB{ 1,2 }, sC{ 1,3 };

	getCoords(ns, &A, &B, &C);

	int H = abs(sA.x - A.x) + abs(sA.y - A.y) +
		abs(sB.x - B.x) + abs(sB.y - B.y) +
		abs(sC.x - C.x) + abs(sC.y - C.y);

	ns->G = H;

	ns->h = H+ns->depth;
}

void AStar::getCoords(NodeState* n, Coord* a, Coord* b, Coord* c) {
	for (int j=0; j<4; j++)
		for (int i = 0; i < 4; i++) {
			if (n->state.board[i][j] == 'A') {
				a->x = i;
				a->y = j;
			} else if (n->state.board[i][j] == 'B') {
				b->x = i;
				b->y = j;
			} else if (n->state.board[i][j] == 'C') {
				c->x = i;
				c->y = j;
			}
		}
}
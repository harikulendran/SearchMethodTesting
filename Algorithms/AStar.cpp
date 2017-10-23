#include "AStar.h"
#include <cmath>

bool LessThanByHeuristic::operator()(const NodeState lhs, const NodeState rhs) const {
	return lhs.h > rhs.h;
}

AStar::AStar() {
}

void AStar::search(int q, int w, int e, int r) {
	int count = 1;
	NodeState root{0};
	calculateF(&root);
	nodes.push(move(root));
	current = nodes.top();

	while (!nodes.empty()) {
		if (current.state.isSolved()) {
			cout << "No of nodes: " << nodes.size() << endl << "no of expanded: " << count << endl;
			break;
		}
		nodes.pop();
		count++;

		current.state.checkMoves();
		if (current.state.validMoves[q]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
			newBoard.move(static_cast<Direction>(q));
			NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
			calculateF(&newState);
			nodes.push(move(newState));
		}
		if (current.state.validMoves[w]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
			newBoard.move(static_cast<Direction>(w));
			NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
			calculateF(&newState);
			nodes.push(move(newState));
		}
		if (current.state.validMoves[e]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
			newBoard.move(static_cast<Direction>(e));
			NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
			calculateF(&newState);
			nodes.push(move(newState));
		}
		if (current.state.validMoves[r]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
			newBoard.move(static_cast<Direction>(r));
			NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
			calculateF(&newState);
			nodes.push(move(newState));
		}
		current = nodes.top();
	}

	/*cout << current->depth << endl;
	cout << "Nodes in fringe: " << nodes.size() << endl;
	current->state.print();*/
}

void AStar::calculateF(NodeState* ns) {
	Coord A, B, C;
	Coord sA{ 1,1 }, sB{ 1,2 }, sC{ 1,3 };

	getCoords(ns, &A, &B, &C);

	int H = abs(sA.x - A.x) + abs(sA.y - A.y) +
		abs(sB.x - B.x) + abs(sB.x - B.x) +
		abs(sC.x - C.x) + abs(sC.x - C.x);

	ns->h = H + ns->depth;
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
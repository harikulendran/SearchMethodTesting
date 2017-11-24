#include "AStar.h"
#include <cmath>

bool LessThanByHeuristic::operator()(const NodeState lhs, const NodeState rhs) const {
	return lhs.h > rhs.h;
}

AStar::AStar() {
	searchName = "AStar";
}

NodeState AStar::top() {
	return fringe.top();
}

void AStar::calculateF(NodeState* ns) {
	Coord pieces[NO_OF_PIECES];
	getCoords(ns, pieces);
	int H = calculateH(pieces);

	ns->G = H;

	ns->h = H+ns->depth;
	//ns->h = 0;
}

int AStar::calculateH(Coord (&pieces)[NO_OF_PIECES]) {
	int H = 0;
	int boardOffset = NO_OF_PIECES;
	for (int i = 0; i < NO_OF_PIECES; i++)
		H += abs(1 - pieces[i].x) + abs(BOARD_SIZE - boardOffset-- - pieces[i].y);
	return H;
}

//get the current position of the pieces
void AStar::getCoords(NodeState* n, Coord (&pieces)[NO_OF_PIECES]) {
	for (int j=0; j < BOARD_SIZE; j++)
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int k = 0; k<NO_OF_PIECES; k++)
				if (n->state.board[i][j] == goals[k]) {
					pieces[k].x = i;
					pieces[k].y = j;
				}
		}
}
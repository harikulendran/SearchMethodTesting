#include "AStar.h"
#include <cmath>

bool LessThanByHeuristic::operator()(const NodeState lhs, const NodeState rhs) const {
	return lhs.h > rhs.h;
}

/*AStar::AStar() {
}

SearchOutput AStar::search() {
	//add the root node and calculate its 
	NodeState root{0};
	calculateF(&root);
	nodes.push(move(root));
	current = nodes.top();

	while (!nodes.empty()) {
		if (current.state.isSolved()) {
			output.solnDepth = current.depth;
			output.isOptimal = (output.solnDepth == 14);
			output.nodesInMemory = nodes.size();
			break;
		}
		nodes.pop();

		current.state.checkMoves();
		for (int i = 0; i < 4; i++) {
			if (current.state.validMoves[i]) {
				BlocksWorldBoard newBoard = BlocksWorldBoard{ current.state };
				newBoard.move(static_cast<Direction>(i));
				NodeState newState{ ++nodeIndex, current.thisNode, move(newBoard), current.depth + 1 };
				newState.d = static_cast<Direction>(i);
				calculateF(&newState);
				nodes.push(move(newState));
			}
		}
		output.nodesExpanded++;
		current = nodes.top();
		char s;
		switch (static_cast<int>(current.d)) {
		case (0):
			s = 'L';
			break;
		case (1):
			s = 'R';
			break;
		case (2):
			s = 'U';
			break;
		case (3):
			s = 'D';
		}


		if (output.nodesExpanded < 20)
			cout << s << " ";
		output.maxNodesInMemory = (output.maxNodesInMemory < nodes.size()) ? nodes.size() : output.maxNodesInMemory;
	}

	return output;
}*/

NodeState AStar::top() {
	return fringe.top();
}

void AStar::calculateF(NodeState* ns) {
	Coord pieces[NO_OF_PIECES];
	getCoords(ns, pieces);
	int H = calculateH(pieces);

	ns->G = H;

	ns->h = H+ns->depth;
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
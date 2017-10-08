#include "stdafx.h"

#include <iostream>
#include "BlocksWorldBoard.h"

Coord::Coord(int acoord = 0, int bcoord = 0) : x(acoord), y(bcoord) {}

BlocksWorldBoard::BlocksWorldBoard() {
	board[0][3] = 1;
	board[1][3] = 2;
	board[2][3] = 3;
	board[3][3] = 4;
	moves.insert_or_assign(Direction::RIGHT, Coord(1, 0));
	moves.insert_or_assign(Direction::LEFT, Coord(-1, 0));
	moves.insert_or_assign(Direction::UP, Coord(0, -1));
	moves.insert_or_assign(Direction::DOWN, Coord(0, 1));
}

bool BlocksWorldBoard::isSolved() {
	return (board[1][1] == 1 &&
		board[1][2] == 2 &&
		board[1][3] == 3);
}

bool BlocksWorldBoard::isValid(Direction dir) {
	return validMoves[dir];
}

void BlocksWorldBoard::checkMoves() {
	validMoves[Direction::RIGHT] = (agent.x != BOARD_SIZE - 1);
	validMoves[Direction::LEFT] = (agent.x != 0);
	validMoves[Direction::DOWN] = (agent.y != BOARD_SIZE - 1);
	validMoves[Direction::UP] = (agent.y != 0);
}

void BlocksWorldBoard::move(Direction dir) {
	if (dir == Direction::NA)
		return;
	int temp = board[agent.x + moves[dir].x][agent.y + moves[dir].y];
	board[agent.x + moves[dir].x][agent.y + moves[dir].y] = 4;
	board[agent.x][agent.y] = temp;
	agent.x += moves[dir].x;
	agent.y += moves[dir].y;
}

void BlocksWorldBoard::print() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
}
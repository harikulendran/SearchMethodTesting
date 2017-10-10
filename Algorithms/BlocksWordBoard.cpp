#include <iostream>
#include "BlocksWorldBoard.h"

Coord::Coord(int acoord = 0, int bcoord = 0) : x(acoord), y(bcoord) {}

BlocksWorldBoard::BlocksWorldBoard() {
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = '.';
	board[0][3] = 'A';
	board[1][3] = 'B';
	board[2][3] = 'C';
	board[3][3] = 'a';
	/*moves.try_emplace(Direction::RIGHT, Coord(1, 0));
	moves.try_emplace(Direction::LEFT, Coord(-1, 0));
	moves.try_emplace(Direction::UP, Coord(0, -1));
	moves.try_emplace(Direction::DOWN, Coord(0, 1));
	*/
}

bool BlocksWorldBoard::isSolved() {
	return (board[1][1] == 'A' &&
		board[1][2] == 'B' &&
		board[1][3] == 'C' &&
		board[3][3] == 'a');
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

Coord BlocksWorldBoard::moves(Direction dir) {
	switch (dir) {
		case Direction::RIGHT :
			return Coord(1, 0);
		case Direction::LEFT :
			return Coord(-1, 0);
		case Direction::UP :
			return Coord(0, -1);
		case Direction::DOWN :
			return Coord(0, 1);
	}
}

void BlocksWorldBoard::move(Direction dir) {
	if (dir == Direction::NA)
		return;
	Coord offset = moves(dir);
	int temp = board[agent.x + offset.x][agent.y + offset.y];
	board[agent.x + offset.x][agent.y + offset.y] = 'a';
	board[agent.x][agent.y] = temp;
	agent.x += offset.x;
	agent.y += offset.y;
}

void BlocksWorldBoard::print() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
}
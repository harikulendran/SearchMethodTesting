#include <iostream>
#include "BlocksWorldBoard.h"

Coord::Coord(int acoord, int bcoord) : x(acoord), y(bcoord) {}

BlocksWorldBoard::BlocksWorldBoard() {
	//set the board to blank
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = '.';
	//add the pieces in the start state
	for (int i = 0; i < NO_OF_PIECES; i++)
		board[i][BOARD_SIZE - 1] = goals[i];
}

bool BlocksWorldBoard::isSolved() {
	bool solved = true;
	int boardOffset = NO_OF_PIECES;
	//check all the pieces are in the correct goal position
	for (int i = 0; i < NO_OF_PIECES; i++)
		solved &= (board[1][BOARD_SIZE - boardOffset--] == goals[i]);
	return solved;
}

void BlocksWorldBoard::checkMoves() {
	validMoves[static_cast<int>(Direction::RIGHT)] = (agent.x != BOARD_SIZE - 1);
	validMoves[static_cast<int>(Direction::LEFT)] = (agent.x != 0);
	validMoves[static_cast<int>(Direction::DOWN)] = (agent.y != BOARD_SIZE - 1);
	validMoves[static_cast<int>(Direction::UP)] = (agent.y != 0);
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
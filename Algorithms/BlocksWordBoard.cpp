#include <iostream>
#include "BlocksWorldBoard.h"

Coord::Coord(int acoord, int bcoord) : x(acoord), y(bcoord) {}

BlocksWorldBoard::BlocksWorldBoard() {
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = '.';
	//for (int i = 0; i < 4 - 1; i++)
	//	board[i][BOARD_SIZE - 1] = goals[i];
	board[0][BOARD_SIZE - 1] = 'A';
	board[1][BOARD_SIZE - 1] = 'B';
	board[2][BOARD_SIZE - 1] = 'C';
	board[BOARD_SIZE-1][BOARD_SIZE-1] = 'a';
	//print();
}

bool BlocksWorldBoard::isSolved() {
	/*bool solved = true;
	for (int i = 0; i < 3 - 1; i++) {
		if (board[1][BOARD_SIZE-3] != goals[i])
			solved = false;
		//solved &= (board[1][i + 1] == goals[i]);
		//cout << (board[1][i + 1] == goals[i]);
	}
	return solved;*/
	return (board[1][BOARD_SIZE - 3] == 'A' &&
			board[1][BOARD_SIZE - 2] == 'B' &&
			board[1][BOARD_SIZE - 1] == 'C');
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
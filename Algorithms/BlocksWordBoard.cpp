#include <iostream>
#include "BlocksWorldBoard.h"

//simple coordinate representation
Coord::Coord(int acoord, int bcoord) : x(acoord), y(bcoord) {}

BlocksWorldBoard::BlocksWorldBoard() {
	//set the board to blank
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = '.';
	//add the pieces in the start state
	for (int i = 0; i < NO_OF_PIECES; i++)
		board[i][BOARD_SIZE - 1] = goals[i];

	//add the agent
	agent.x = BOARD_SIZE - 1;
	agent.y = BOARD_SIZE - 1;
	board[agent.x][agent.y] = 'a';
}

void BlocksWorldBoard::setBoard(BlocksWorldBoard* other) {
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = other->board[i][j];
}

//checks if the current board is the goal state
bool BlocksWorldBoard::isSolved() {
	bool solved = true;
	int boardOffset = NO_OF_PIECES;
	//check all the pieces are in the correct goal position
	for (int i = 0; i < NO_OF_PIECES; i++)
		solved &= (board[1][BOARD_SIZE - boardOffset--] == goals[i]);
	return solved;
	//return (board[0][0] == 'A') &&(board[1][0] == 'B') &&(board[2][0] == 'C');
}

//fills the list of valid moves for the agent in its current position
void BlocksWorldBoard::checkMoves() {
	validMoves[static_cast<int>(Direction::RIGHT)] = (agent.x != BOARD_SIZE - 1) && (board[agent.x+1][agent.y] != 'x');
	validMoves[static_cast<int>(Direction::LEFT)] = (agent.x != 0) && (board[agent.x-1][agent.y] != 'x');
	validMoves[static_cast<int>(Direction::DOWN)] = (agent.y != BOARD_SIZE - 1) && (board[agent.x][agent.y+1] != 'x');
	validMoves[static_cast<int>(Direction::UP)] = (agent.y != 0) && (board[agent.x+1][agent.y-1] != 'x');
}

//links each Direction to a unit coordinate
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

//moves the agent in the given direction
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

//prints the current board
void BlocksWorldBoard::print() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
}
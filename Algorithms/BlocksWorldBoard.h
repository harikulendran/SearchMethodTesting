#pragma once

#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 4;

enum class Direction { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3, NA = 4 };

class Coord {
	public:
		int x;
		int y;
		Coord(int acoord, int bcoord);
};

class BlocksWorldBoard {
	public:
		BlocksWorldBoard();
		~BlocksWorldBoard() = default;
		bool validMoves[4];
		bool isSolved();
		void checkMoves();
		void move(Direction dir);
		void print();
		Coord moves(Direction dir);
	private:
		char board[BOARD_SIZE][BOARD_SIZE] = {};
		Coord agent{ 3,3 };
};
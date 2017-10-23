#pragma once

#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 4;

enum class Direction { UP = 0, LEFT = 1, RIGHT = 2, DOWN = 3, NA = 4 };

class Coord {
	public:
		int x;
		int y;
		Coord(int acoord = 0, int bcoord = 0);
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
		char board[BOARD_SIZE][BOARD_SIZE] = {};
	private:
		Coord agent{ 3,3 };
};
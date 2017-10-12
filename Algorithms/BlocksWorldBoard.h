#pragma once

#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 4;

enum class Direction { LEFT, UP, RIGHT, DOWN, NA };

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
		map<Direction, bool> validMoves;
		bool isSolved();
		void checkMoves();
		bool isValid(Direction dir);
		void move(Direction dir);
		void print();
		Coord moves(Direction dir);
	private:
		char board[BOARD_SIZE][BOARD_SIZE] = {};
		Coord agent{ 3,3 };
};
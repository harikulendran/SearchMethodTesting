#pragma once

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 4;

enum class Direction { LEFT, RIGHT, UP, DOWN, NA };

class Coord {
	public:
		int x;
		int y;
		Coord(int acoord, int bcoord);
};

class BlocksWorldBoard {
	public:
		BlocksWorldBoard();
		map<Direction, bool> validMoves;
		bool isSolved();
		void checkMoves();
		bool isValid(Direction dir);
		void move(Direction dir);
		void print();
	private:
		char board[BOARD_SIZE][BOARD_SIZE] = {};
		map<Direction, Coord> moves;
		Coord agent{ 3,3 };
};
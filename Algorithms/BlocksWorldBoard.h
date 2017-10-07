#pragma once

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 4;

enum class Direction { LEFT, RIGHT, UP, DOWN, NA };

struct Coord {
	int x;
	int y;
	Coord(int a, int b);
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
		int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
		map<Direction, Coord> moves;
		Coord agent;
};
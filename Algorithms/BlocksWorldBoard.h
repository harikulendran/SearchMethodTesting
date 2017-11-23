#pragma once

#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 5;
const static int NO_OF_PIECES = 3;
const static string goals("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

enum class Direction { UP = 0, LEFT = 1, RIGHT = 2, DOWN = 3, NA = 4 };

class SearchOutput {
	public:
		int solnDepth = 0;
		bool isOptimal = false;
		int nodesInMemory = 0;
		int maxNodesInMemory = 0;
		__int64 nodesExpanded = 0;
		__int64 realWorldTime;
};

class Coord {
	public:
		int x;
		int y;

	public:
		Coord(int acoord = 0, int bcoord = 0);
};

class BlocksWorldBoard {
	public:
		Coord moves(Direction dir);
		char board[BOARD_SIZE][BOARD_SIZE] = {};
		bool validMoves[4];

	public:
		BlocksWorldBoard();
		~BlocksWorldBoard() = default;

	public:
		bool isSolved();
		void checkMoves();
		void move(Direction dir);
		void print();
	
	private:
		Coord agent{ BOARD_SIZE - 1,BOARD_SIZE - 1 };
};
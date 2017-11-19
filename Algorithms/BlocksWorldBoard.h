#pragma once

#include <iostream>
#include <map>

using namespace std;

const static int BOARD_SIZE = 6;
const static string goals("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

enum class Direction { UP = 3, LEFT = 2, RIGHT = 1, DOWN = 0, NA = 4 };

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
		Coord agent{ BOARD_SIZE - 1,BOARD_SIZE - 1 };
};
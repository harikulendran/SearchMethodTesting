#pragma once
#include "BlocksWorldBoard.h"
#include "CImg.h"

using namespace cimg_library;

class BoardDrawer {
	private:
		const unsigned int x_dim = 500;
		const unsigned int y_dim = 500;
		unsigned char lineCol[3] = { 0,0,0 };
		unsigned char shadeCol[3] = { 212,247,255 };
		unsigned char fadeRed[3] = { 255,102,102 };
		CImg<unsigned char> image{ x_dim, y_dim, 1, 3, 255 };
		BlocksWorldBoard startBoard;

	public:
		BoardDrawer(BlocksWorldBoard start);

	public:
		void draw(string name, BlocksWorldBoard board, int i=0);
		void displaySoln(int* soln, int size);
		void drawHeatMap(string name, int(&board)[BOARD_SIZE][BOARD_SIZE]);
		void drawHPiece(int x, int y, double c);

	private:
		void showBoard();
		void drawBoard(BlocksWorldBoard board);
		void drawGrid();
		void drawPiece(int x, int y, char c);
};
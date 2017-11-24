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
		CImg<unsigned char> image{ x_dim, y_dim, 1, 3, 255 };

	public:
		BoardDrawer();

	public:
		void draw(string name, BlocksWorldBoard board, int i=0);

	private:
		void showBoard();
		void drawGrid();
		void drawPiece(int x, int y, char c);
};
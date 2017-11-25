#include "BoardDrawer.h"
#include <sstream>

BoardDrawer::BoardDrawer() {
	//draw(BlocksWorldBoard{});
	//showBoard();
}

void BoardDrawer::draw(string name, BlocksWorldBoard board, int i) {
	drawBoard(board);

	std:ostringstream path;
	path << "img/" << name << "/" << i << ".bmp";
	string tstr = path.str();
	image.save(tstr.c_str());
}

void BoardDrawer::displaySoln(int* soln, int size) {
	CImgDisplay main(image, "Solution", 255);
	BlocksWorldBoard board{};
	int backIndex = 0;
	drawBoard(board);
	draw("soln", board, backIndex++);
	image.display(main);
	for (int i = size - 1; i >= 0; i--) {
		cimg::wait(700);
		cout << soln[i] << " ";
		board.move(static_cast<Direction>(soln[i]));
		drawBoard(board);
		draw("soln", board, backIndex++);
		image.display(main);
	}
	while (!main.is_closed()) {
		cimg::wait(20);
	}

}

void BoardDrawer::drawBoard(BlocksWorldBoard board) {
	image = CImg<unsigned char>{ x_dim,y_dim,1,3,255 };
	for (int j = 0; j < BOARD_SIZE; j++)
		for (int i = 0; i < BOARD_SIZE; i++)
			if (board.board[i][j] != '.') {
				drawPiece(i, j, board.board[i][j]);
			}
	drawGrid();
}

void BoardDrawer::drawPiece(int x, int y, char c) {
	unsigned char red[] = { 255,0,0 };
	float xo = image.width() / (float)BOARD_SIZE;
	float yo = image.height() / (float)BOARD_SIZE;
	unsigned char green[] = { 214, 255, 214 };
	unsigned char* col = (c == 'a') ? green : shadeCol;
	image.draw_rectangle(x*xo, y*yo, (x+1)*xo, (y+1)*yo, col, 1);
	const char cs[] = { c,0 };
	image.draw_text(x*xo + xo/2.0f - 18.0, y*yo + yo/2.0f - 30.0, cs, red, 0, 1.0f, 60);
}

void BoardDrawer::showBoard() {
	CImgDisplay main(image, "image",0);
	image.display(main);
	while (!main.is_closed()) {
		cimg::wait(20);
	}
}

void BoardDrawer::drawGrid() {
	for (int i = -2; i < 3; i++)
		image.draw_grid((image.width() - 1.0) / ((float)BOARD_SIZE), (image.height() - 1.0) / ((float)BOARD_SIZE), i, i, false, true, lineCol, 1.0f, 0xffffffff, 0xffffffff);
}
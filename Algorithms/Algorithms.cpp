#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	auto start = chrono::steady_clock::now();
	//BreadthFirstSearch b{};
	//b.search();
	DepthFirstSearch d{};
	d.search();
	auto timeTaken = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
	cout << "Time taken: " << timeTaken.count() / 1000.0 << "s" << endl;

//	DepthFirstSearch d{};
	//d.search();

	/*BlocksWorldBoard b{};
	b.move(Direction::LEFT);
	BlocksWorldBoard b2(b);
	b2.move(Direction::UP);

	b.print();
	cout << "ADFASDF" << endl;
	b2.print();
	*/
	int q;
	cin >> q;

	return 0;
}
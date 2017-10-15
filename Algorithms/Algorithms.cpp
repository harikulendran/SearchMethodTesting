#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	//BreadthFirstSearch b{};
	//b.search();



	__int64 total = 0;
	int testno = 1000;
	for (int i = 0; i < testno; i++) {
		auto start = chrono::steady_clock::now();
		DepthFirstSearch d{};
		d.search();
		//d.iterativeSearch(0,25,1);
		//BreadthFirstSearch b{};
		//b.search();
		auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
 
		total += dur.count();
			
		//cout << "time: " << dur.count() << endl;
	}
	cout << "Avg time taken: " << (double)total / (double)testno << "ms" << endl;
	



	/*{
		BreadthFirstSearch d{};
		d.search();
		int qq;
		cin >> qq;
	}*/

	/*BlocksWorldBoard b{};
	b.move(Direction::LEFT);
	BlocksWorldBoard b2(b);
	b2.move(Direction::UP);

	b.print();
	cout << "ADFASDF" << endl;
	b2.print();
	*/
	//int q;
	//cin >> q;

	return 0;
}
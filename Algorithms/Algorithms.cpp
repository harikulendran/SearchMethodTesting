#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	__int64 total = 0;
	int testno = 1;
	for (int i = 0; i < testno; i++) {
		auto start = chrono::steady_clock::now();
		DepthFirstSearch d{};
		//d.search();
		d.iterativeSearch(0,25,1);
		//BreadthFirstSearch b{};
		//b.search();
		auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
 
		total += dur.count();
			
		//cout << "time: " << dur.count() << endl;
	}
	cout << "Avg time taken: " << (double)total / (double)testno << "ms" << endl;
	
	//int q;
	//cin >> q;

	return 0;
}
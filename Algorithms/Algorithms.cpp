#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "AStar.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	__int64 total = 0;
	int testno = 1;
	for (int i = 0; i < testno; i++) {
		auto start = chrono::steady_clock::now();
		//DepthFirstSearch d{};
		//d.search();
		//d.iterativeSearch(0,25,1);
		//BreadthFirstSearch b{};
		//b.search();
		/*for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (k != j)
					for (int l = 0; l < 4; l++) {
						if (l != k && l!= j)
							for (int p = 0; p < 4; p++) {
								if (p != k && p!= j && p!= l) {
									AStar a{};
									cout << j << " " << k << " " << l << " " << p << " " << endl;
									a.search(j, k, l, p);
									cout << endl;
								}	
							}
					}
			}
		}*/
		AStar a{};
		a.search(0, 1, 2, 3);
		//a.search();
		auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
 
		total += dur.count();
			
		//cout << "time: " << dur.count() << endl;
	}
	cout << "Avg time taken: " << (double)total / (double)testno << "ms" << endl;
	
	//int q;
	//cin >> q;

	return 0;
}
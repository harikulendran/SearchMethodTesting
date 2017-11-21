#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "AStar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int main() {
	__int64 total = 0;
	int testno = 1;
	SearchOutput output;

	ifstream f(string("DATA/outputFile.csv").c_str());
	bool start = f.good();
	ofstream outputFile;
	outputFile.open("DATA/outputFile.csv", ios::out | ios::app);

	if (!start)
		outputFile << "NO,Solution Depth,Nodes In Memory,Max Nodes in Memory,Nodes Expanded,Optimal Solution,Real World Time\n";

	string outputString = "";

	for (int i = 0; i < testno; i++) {
		auto start = chrono::steady_clock::now();
		//DepthFirstSearch d{i+1};
		//output = d.search();
		//output = d.iterativeSearch(0,40,1);
		BreadthFirstSearch b{};
		output = b.search();
		//AStar a{};
		//output = a.search();
		auto dur = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - start);
		output.realWorldTime = dur.count();

		outputString += to_string(i + 1) + "," + to_string(output.solnDepth) + "," 
					+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
					+ to_string(output.nodesExpanded) + "," + to_string(output.isOptimal) + ","
					+ to_string(output.realWorldTime) + "\n";

		total += dur.count();
			
		cout << "time: " << dur.count() << endl;
	}
	outputFile << outputString;
	outputFile << "\n";
	outputFile.close();
	cout << "Avg time taken: " << (double)total / (double)testno << "ns" << endl;
	
	return 0;
}
#include "BlocksWorldBoard.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "IterativeDeepeningSearch.h"
#include "TreeSearch.h"
#include "AStar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


using namespace std;

int main() {
	__int64 total = 1;
	int testno = 1;
	SearchOutput output;

	ifstream f(string("DATA/outputFile.csv").c_str());
	bool start = f.good();
	ofstream outputFile;
	outputFile.open("DATA/outputFile.csv", ios::out | ios::app);
	if (!start)
		outputFile << "NO,Solution Depth,Nodes In Memory,Max Nodes in Memory,Nodes Expanded,Optimal Solution,Real World Time\n";

	string outputString = "";

	//BoardDrawer ba{};
	//int* soln = new int[14] {1,3,1,0,0,2,3,2,0,1,3,1,1,0};
	//ba.displaySoln(soln, 14);

	for (int i = 0; i < testno; i++) {
		auto start = chrono::steady_clock::now();
		/*for (int j = 0; j < 100; j++) {
			DepthFirstSearch d{ j + 1 };
			output = d.search();

			outputString += "DFS," + to_string(i + 1) + "," + to_string(output.solnDepth) + ","
				+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
				+ to_string(output.nodesExpanded) + "," + to_string(output.isOptimal) + ","
				+ to_string(output.realWorldTime) + "\n";
		}*/
		//BreadthFirstSearch b{};
		//output = b.search();
		/*
		outputString +="BFS,"+ to_string(i + 1) + "," + to_string(output.solnDepth) + "," 
					+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
					+ to_string(output.nodesExpanded) + "," + to_string(output.isOptimal) + ","
					+ to_string(output.realWorldTime) + "\n";
		*/
		//AStar a{};
		//output = a.search();
		
		/*outputString += "AStar,"+to_string(i + 1) + "," + to_string(output.solnDepth) + "," 
					+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
					+ to_string(output.nodesExpanded) + "," + to_string(output.isOptimal) + ","
					+ to_string(output.realWorldTime) + "\n";*/
		IterativeDeepeningSearch ids{};
		output = ids.search(40);
	
		auto dur = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - start);
		output.realWorldTime = dur.count();

		outputString += "IDS,"+ to_string(i + 1) + "," + to_string(output.solnDepth) + "," 
					+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
					+ to_string(output.nodesExpanded) + "," + to_string(output.isOptimal) + ","
					+ to_string(output.realWorldTime) + "\n";

		
		total += dur.count();
			
		cout << i << " time: " << dur.count() << endl;
	}
	outputFile << outputString;
	outputFile << "\n";
	outputFile.close();
	cout << "Avg time taken: " << (double)total / (double)testno << "ns" << endl;
	
	return 0;
}
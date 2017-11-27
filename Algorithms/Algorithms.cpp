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

void record(string name, string* outputString, SearchOutput output, int i=1) {
		*outputString += "DFS," + to_string(i + 1) + "," + to_string(output.solnDepth) + ","
			+ to_string(output.nodesInMemory) + "," + to_string(output.maxNodesInMemory) + ","
			+ to_string(output.nodesExpanded) + "\n";
}

int main() {
	int testno = 1;
	SearchOutput output;

	ifstream f(string("DATA/outputFile.csv").c_str());
	bool start = f.good();
	ofstream outputFile;
	outputFile.open("DATA/outputFile.csv", ios::out | ios::app);
	if (!start)
		outputFile << "NO,Solution Depth,Nodes In Memory,Max Nodes in Memory,Nodes Expanded\n";

	string outputString = "";

	for (int i = 0; i < testno; i++) {
		DepthFirstSearch d{ i + 1 };
		output = d.search();
		record(d.searchName, &outputString, output, i);
	}

	//BreadthFirstSearch b{};
	//output = b.search();
	//record(b.searchName, &outputString, output);

	//AStar a{};
	//output = a.search();
	//record(a.searchName, &outputString, output);

	//IterativeDeepeningSearch ids{};
	//output = ids.search(40);
	//record(ids.searchName, &outputString, output);


	outputFile << outputString;
	outputFile << "\n";
	outputFile.close();
	
	return 0;
}
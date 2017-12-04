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

void record(string name, string* outputString, SearchOutput output, int i=0, int j=0) {
		*outputString += name + " " + to_string(i + 1) + "," + to_string(j) + "," + to_string(output.solnDepth) + ","
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
		outputFile << "NO,Problem Difficulty,Solution Depth,Nodes In Memory,Max Nodes in Memory,Nodes Expanded\n";

	string outputString = "";


	//allows you to make changes to the board state before running
	BlocksWorldBoard sB{};
	//adding an 'x' for example adds an immovable block
	//sB.board[2][2] = 'x';


	for (int j = 0; j < testno; j++) {
		//IterativeDeepeningSearch ids{sB};
		//output = ids.search();
		//record(ids.searchName, &outputString, output,0,j);

		//BreadthFirstSearch b{sB};
		//output = b.search();
		//record(b.searchName, &outputString, output,0,j);
		int q = 0;
		while (output.solnDepth > 19) {
			DepthFirstSearch d{ q++,sB };
			output = d.search();
			record(d.searchName, &outputString, output, 0, j);
		}

		//AStar a{sB};
		//output = a.search();
		//record(a.searchName, &outputString, output,0,j);
		
		cout << j << " DONE\n";
	}

	outputFile << outputString;
	outputFile << "\n";
	outputFile.close();
	
	return 0;
}
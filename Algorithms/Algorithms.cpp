// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
	Graph* graph = &Graph::getRandomGraph(6,0);
	cout << "outside rand " << graph->nodeSize() << endl;
	cout << "outside rand " << graph->edgeSize() << endl;
	int a;
	cin >> a;
	return 0;
}
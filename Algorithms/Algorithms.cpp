// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

using namespace std;

int main() {
	Tree tree = Tree::getRandomTree(6,0);
	cout << "outside rand " << tree.nodeSize() << endl;
	cout << "outside rand " << tree.edgeSize() << endl;
	int a;
	cin >> a;
	return 0;
}
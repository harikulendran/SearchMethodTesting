#pragma once

#include "BlocksWorldBoard.h"
#include <vector>
#include <memory>

using namespace std;

class Node;

class Node {
	public:
		int index;
		int parentIndex;
		int depth;
		map<Direction, int> edges;

	public:
		Node(int i = -1, int p = -1, int d = -1);
		~Node() = default;

	public:
		void addEdge(int n, Direction d);
		int edgeSize();
};

class Tree {
	public:
		map<int,Node> nodes;
		int nodeIndex = 0;

	public:
		Tree();
		~Tree() = default;

	public:
		void addNode(int p, int d);
		Node* getNode(int i);
		int nodeSize();
		int edgeSize();
};
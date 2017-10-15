#pragma once

#include "BlocksWorldBoard.h"
#include <vector>
#include <memory>

using namespace std;

class Node;

class Edge {
	public:
		int index;
		Direction dir;
		Node* n1;
		//bool traversed = false;

	public:
		Edge(int i, Direction di, Node* node1);
		~Edge() = default;
};

class Node {
	public:
		int index;
		int parentIndex;
		int depth;
		//BlocksWorldBoard state;
		vector<Edge> edges;

	public:
		Node(int i, int p, int d);
		~Node() = default;

	public:
		bool operator==(const Node* rhs);
		bool operator!=(const Node* rhs);
		void addEdge(Node* n, Direction d);
		void removeEdge(int index);
		int edgeSize();
};

class Tree {
	public:
		Node* root;
		Node* currentNode;
		vector<Node*> nodes;

	public:
		Tree();
		~Tree();

	public:
		void addNode(int i, int p, int d);
		Node* getNode(int i);
		int nodeSize();
		int edgeSize();
};
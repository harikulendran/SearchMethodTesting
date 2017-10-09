#pragma once

#include "stdafx.h"
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
		Edge(int i, Direction di, Node* node1);
};

class Node {
	public:
		int index;
		int depth;
		vector<Edge> edges;
		bool operator==(const Node* rhs);
		bool operator!=(const Node* rhs);
		Node(int i, int d);
		//~Node();
		void addEdge(Node* n, Direction d);
		int edgeSize();
};

class Tree {
	public:
		Node* root;
		Node* currentNode;
		vector<Node*> nodes;
		Tree();
		//~Tree();
		void addNode(int i, int d);
		Node* getNode(int i);
		//shared_ptr<Node> getSNode(int i);
		int nodeSize();
		int edgeSize();
		static Tree getRandomTree(int n, int p);
};
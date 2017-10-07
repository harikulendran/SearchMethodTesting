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
		shared_ptr<Node> n1;
		Edge(int i, Direction di, shared_ptr<Node> node1);
};

class Node {
	public:
		int index;
		int depth;
		vector<Edge> edges;
		bool operator==(const shared_ptr<Node> rhs);
		bool operator!=(const shared_ptr<Node> rhs);
		Node(int i, int d);
		~Node();
		void addEdge(shared_ptr<Node> n, Direction d);
		int edgeSize();
};

class Tree {
	public:
		shared_ptr<Node> root;
		shared_ptr<Node> currentNode;
		vector<shared_ptr<Node>> nodes;
		Tree();
		//~Tree();
		void addNode(int i, int d);
		Node& getNode(int i);
		shared_ptr<Node> getSNode(int i);
		int nodeSize();
		int edgeSize();
		static Tree getRandomTree(int n, int p);
};
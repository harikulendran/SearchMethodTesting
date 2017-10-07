#pragma once

#include "stdafx.h"
#include <vector>
#include <memory>

using namespace std;

class Node;

class Edge {
	public:
		int index;
		shared_ptr<Node> n1;
		Edge(int i, shared_ptr<Node> node1);
};

class Node {
	public:
		int index;
		vector<Edge> edges;
		bool operator==(const shared_ptr<Node> rhs);
		bool operator!=(const shared_ptr<Node> rhs);
		Node(int i);
		~Node();
		void addEdge(shared_ptr<Node> n);
		int edgeSize();
};

class Tree {
	public:
		shared_ptr<Node> root;
		vector<shared_ptr<Node>> nodes;
		Tree();
		//~Tree();
		void addNode(int i);
		Node& getNode(int i);
		shared_ptr<Node> getSNode(int i);
		int nodeSize();
		int edgeSize();
		static Tree getRandomTree(int n, int p);
};
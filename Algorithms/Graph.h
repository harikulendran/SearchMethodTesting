#pragma once

#include "stdafx.h"
#include <vector>

using namespace std;

class Node;

class Edge {
	public:
		int index;
		Node* n1;
		Node* n2;
		Edge(int i, Node& node1, Node& node2);
};

class Node {
	public:
		int index;
		vector<Edge> edges;
		bool operator==(const Node& rhs);
		bool operator!=(const Node& rhs);
		Node(int i);
		void addEdge(Node n);
};

class Graph {
	public:
		Node root;
		vector<Node> nodes;
		Graph();
		void addNode(Node& n);
		Node getNode(int i);
		int nodeSize();
		static Graph getRandomGraph(int n, int p);
};
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
		vector<Edge*>* edges;
		bool operator==(const Node& rhs);
		bool operator!=(const Node& rhs);
		Node(int i);
		~Node();
		void addEdge(Node n);
		int edgeSize();
};

class Graph {
	public:
		Node* root;
		vector<Node*> nodes;
		Graph();
		~Graph();
		void addNode(Node* n);
		Node getNode(int i);
		int nodeSize();
		int edgeSize();
		static Graph getRandomGraph(int n, int p);
};
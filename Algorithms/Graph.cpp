
#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

//Edge
Edge::Edge(int i, Node& node1, Node& node2): index(i), n1(&node1), n2(&node2) {}

//Node
bool Node::operator==(const Node& rhs) {
	return (this->index == rhs.index);
}
bool Node::operator!=(const Node& rhs) {
	return !(*this == rhs);
}
Node::Node(int i) : index(i) {
	edges = new vector<Edge*>;
}
Node::~Node() {
	cout << "delete?" << endl;
	//for (Edge* e : *edges)
		//delete e;
	//delete edges;
}
void Node::addEdge(Node n) {
	if (*this != n) {
		Edge* e = new Edge(edges->size(), *this, n);
		edges->push_back(e);
		cout << index << " - " << &edges << ": " << edges->size() << endl;
		//n.addEdge(*this);
	}
}
int Node::edgeSize() {
	return edges->size();
}

Graph::Graph() : root(new Node(0)) {}
Graph::~Graph() {
	for (Node* n : nodes)
		delete n;
}
		
void Graph::addNode(Node* n) {
	nodes.push_back(n);
}
Node Graph::getNode(int i) {
	return *(nodes.at(i));
}
int Graph::nodeSize() {
	return nodes.size();
}
int Graph::edgeSize() {
	int sum = 0;
	for (Node* n : nodes)
		sum += n->edgeSize();
	return sum;
}

Graph Graph::getRandomGraph(int n, int p) {
	Graph* g = new Graph();
	
	g->addNode(g->root);
	for (int i = 1; i < n; i++) {
		Node* nod = new Node(i);
		g->addNode(nod);
	}

	int index2 = 0;
	for (int i = 0; i < g->nodeSize(); i++) {
		for (int j = index2; j < g->nodeSize(); j++)
			if (i != j)
				(g->getNode(i)).addEdge(g->getNode(j));
		index2++;
	}
	cout << endl << "inside edgesize " << g->edgeSize() << endl;
	cout << "inside index " << g->root->index << endl;
	for (Edge* pi : *((g->nodes)[0]->edges))
		cout << "in root edges: " << pi->index << endl;
	return *g;
}
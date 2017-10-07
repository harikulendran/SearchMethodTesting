#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//Edge
Edge::Edge(int i, shared_ptr<Node> node1) : index(i), n1(node1) {}

//Node
bool Node::operator==(const shared_ptr<Node> rhs) {
	return (this->index == rhs->index);
}
bool Node::operator!=(const shared_ptr<Node> rhs) {
	return !(*this == rhs);
}
Node::Node(int i) : index(i) {}
Node::~Node() {
	//for (Edge* e : *edges)
		//delete e;
	//delete edges;
}
void Node::addEdge(shared_ptr<Node> n) {
	if (*this != n) {
		Edge e(edges.size(), n);
		edges.emplace_back(e);
		cout << index << " - " << &edges << ": " << edges.size() << endl;
		//n.addEdge(*this);
	}
}
int Node::edgeSize() {
	return edges.size();
}

Tree::Tree() : root(new Node(0)) {}
		
void Tree::addNode(int i) {
	nodes.push_back(make_shared<Node>(i));
}
Node& Tree::getNode(int i) {
	return *(nodes.at(i));
}
shared_ptr<Node> Tree::getSNode(int i) {
	return nodes.at(i);
}
int Tree::nodeSize() {
	return nodes.size();
}
int Tree::edgeSize() {
	int sum = 0;
	for (shared_ptr<Node> n : nodes)
		sum += n->edgeSize();
	return sum;
}

Tree Tree::getRandomTree(int n, int p) {
	Tree t{};
	
	for (int i = 0; i < n; i++)
		t.addNode(i);

	t.root = t.nodes.at(0);

	int index2 = 0;
	for (int i = 0; i < t.nodeSize(); i++) {
		for (int j = index2; j < t.nodeSize(); j++)
			if (i != j)
				(t.getSNode(i))->addEdge(t.getSNode(j));
		index2++;
	}
	cout << endl << "inside edgesize " << t.edgeSize() << endl;
	cout << "inside index " << t.root->index << endl;
	for (Edge pi : (t.nodes)[0]->edges)
		cout << "in root edges: " << pi.index << endl;
	return t;
}
#include "Tree.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//Edge
Edge::Edge(int i, Direction d, Node* node1) : index(i), dir(d), n1(node1) {}

//Node
bool Node::operator==(const Node* rhs) {
	return (this->index == rhs->index);
}
bool Node::operator!=(const Node* rhs) {
	return !(*this == rhs);
}
Node::Node(int i, int p, int d) : index(i), parentIndex(p), depth(d) {}

void Node::addEdge(Node* n, Direction d) {
	if (*this != n) {
		edges.emplace_back(Edge(edges.size(), d, n));
		//cout << index << " - " << &edges << ": " << edges.size() << endl;
		//edges.emplace_v
	}
}
int Node::edgeSize() {
	return edges.size();
}

Tree::Tree() {
	addNode(0,-1,0);
	root = getNode(0);
	currentNode = root;
}

Tree::~Tree() {
	for (Node* n : nodes) {
		delete n;
		n = nullptr;
	}
}
		
void Tree::addNode(int i, int p, int d) {
	nodes.emplace_back(new Node(i,p,d));
}
Node* Tree::getNode(int i) {
	return (nodes.at(i));
}
/*shared_ptr<Node> Tree::getSNode(int i) {
	return nodes.at(i);
}*/
int Tree::nodeSize() {
	return nodes.size();
}
int Tree::edgeSize() {
	int sum = 0;
	for (Node* n : nodes)
		sum += n->edgeSize();
	return sum;
}

Tree Tree::getRandomTree(int n, int p) {
	Tree t{};
	
	for (int i = 0; i < n; i++)
		t.addNode(i,-1,0);

	t.root = t.nodes.at(0);

	int index2 = 0;
	for (int i = 0; i < t.nodeSize(); i++) {
		for (int j = index2; j < t.nodeSize(); j++)
			if (i != j)
				(t.getNode(i))->addEdge(t.getNode(j), Direction::NA);
		index2++;
	}
	/*cout << endl << "inside edgesize " << t.edgeSize() << endl;
	cout << "inside index " << t.root->index << endl;
	for (Edge pi : (t.nodes)[0]->edges)
		cout << "in root edges: " << pi.index << endl;*/
	return t;
}
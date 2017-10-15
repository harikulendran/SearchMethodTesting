#include "Tree.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

//Node
Node::Node(int i, int p, int d) : index(i), parentIndex(p), depth(d) {}

void Node::addEdge(int n, Direction d) {
	if (index != n) {
		edges[d] = n;
	}
}

int Node::edgeSize() {
	return edges.size();
}

Tree::Tree() {
	addNode(-1,0);
}

void Tree::addNode(int p, int d) {
	nodes[nodeIndex] = Node(nodeIndex,p,d);
	nodeIndex++;
}
Node* Tree::getNode(int i) {
	return &nodes[i];
}

int Tree::nodeSize() {
	return nodes.size();
}

int Tree::edgeSize() {
	int sum = 0;
	for (auto const& x : nodes) {
		Node temp = x.second;
		sum += temp.edgeSize();
	}
	return sum;
}
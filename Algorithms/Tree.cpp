#include <iostream>
#include <vector>

using namespace std;

class Node;
class Edge;

bool operator== (const Node& lhs, const Node& rhs) {
	return (lhs.index == rhs.index);
}
bool operator!= (const Node& lhs, const Node& rhs) {
	return !(lhs == rhs);
}

class Node {
	public:
		int index;
		vector<Edge*> edges;
	
	public:
		Node(int i) : index(i) {}
		void addEdge(Node n) {
			if (*this != n)
				edges.push_back(new Edge(1, *this, n));

		}
};


class Edge {
	public:
		int index;
		Node n1;
		Node n2;

	public:
		Edge(int i, Node& node1, Node& node2) : index(i), n1(node1), n2(node2) {}
};

class Tree {
	


};
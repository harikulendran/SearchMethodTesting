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
		vector<Edge> edges;
	
	public:
		Node(int i) : index(i) {}
		void addEdge(Node n) {
			if (*this != n) {
				edges.push_back(*new Edge(1, *this, n));
				n.addEdge(*this);
			}
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

class Graph{
	public:
		Node root;
		vector<Node> nodes;

		

	public:
		Graph() : root(*new Node(0)) {}
		
		void addNode(Node& n) {
			nodes.push_back(n);
		}
		Node getNode(int i) {
			return nodes.at(i);
		}
		int nodeSize() {
			return nodes.size();
		}

		static Graph getRandomGraph(int n, int p) {
			Graph* g = new Graph();
			
			g.addNode(g.root);
			for (int i = 1; i < n; i++)
				g.addNode(*new Node(i));

			int index2 = 0;
			for (int i = 0; i < g.nodeSize(); i++) {
				for (int j = index2; j < g.nodeSize(); j++)
					if (i != j)
						g.getNode(i).addEdge(g.getNode(j));
				index2++;
			}

		}


};
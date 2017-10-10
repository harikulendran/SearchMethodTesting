#pragma once

#include <queue>
#include "Tree.h"
#include "BlocksWorldBoard.h"


using namespace std;

struct BFSNode {
	public:
		int node;
		BlocksWorldBoard state;
		BFSNode() = default;
		BFSNode(int i, BlocksWorldBoard s);
};

class BreadthFirstSearch {
	public:
		bool complete = false;
		shared_ptr<Tree> tree;
		queue<BFSNode>* treeNodes;
		BFSNode completeNode;
		BreadthFirstSearch();
		void search();
		void addCurrentNodeEdges();
};


#pragma once

#include <queue>
#include "Tree.h"
#include "BlocksWorldBoard.h"


using namespace std;


class BreadthFirstSearch {
	public:
		bool complete = false;
		shared_ptr<Tree> tree;
		queue<NodeState>* treeNodes;
		NodeState completeNode;
		BreadthFirstSearch();
		~BreadthFirstSearch();
		void search();
		void addCurrentNodeEdges();
};


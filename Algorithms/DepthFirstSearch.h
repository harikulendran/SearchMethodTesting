#pragma once

#include "TreeSearch.h"
#include <stack>


class DepthFirstSearch : public TreeSearch<stack> {
public:
	DepthFirstSearch(int i = 0);
protected:
	NodeState top();
	void calculateF(NodeState* ns);
	void expandNode();
};
#pragma once

#include <stack>
#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include "TreeSearch.h"


class DepthFirstSearch : public TreeSearch<stack> {
public:
	DepthFirstSearch(int i = 0);
protected:
	NodeState top();
	void calculateF(NodeState* ns);
	void expandNode();
};
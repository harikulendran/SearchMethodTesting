#pragma once

#include "BlocksWorldBoard.h"

using namespace std;

class NodeState {
	public:
		int thisNode;
		int parentNode;
		BlocksWorldBoard state;
		bool expanded = false;
		NodeState(int n = -1, int p = -1, BlocksWorldBoard s = BlocksWorldBoard{});
};
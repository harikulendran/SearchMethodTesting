#pragma once

#include "BlocksWorldBoard.h"

using namespace std;

class NodeState {
	public:
		int thisNode;
		int parentNode;
		int h = 0;
		int G = 0;
		int depth;
		BlocksWorldBoard state;
		bool expanded = false;
		NodeState(int n = -1, int p = -1, BlocksWorldBoard s = BlocksWorldBoard{}, int d = 0);
};
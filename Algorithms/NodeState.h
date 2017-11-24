#pragma once

#include "BlocksWorldBoard.h"

using namespace std;

class NodeState {
	public:
		int thisNode;
		int parentNode;
		unsigned __int16 h = 0;
		unsigned __int16 G = 0;
		int depth = 0;
		int dir = 0;
		BlocksWorldBoard state;

	public:
		NodeState(int n = -1, int p = -1, BlocksWorldBoard s = BlocksWorldBoard{}, int d = 0);
};

class SolnNode {
	public:
		int dir = 0;
		int parentNode = 0;

	public:
		SolnNode(int d=-1, int n=-1);
};
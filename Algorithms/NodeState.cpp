#include "NodeState.h"

NodeState::NodeState(int n, int p, BlocksWorldBoard s, int d) : thisNode(n), parentNode(p), state(s), depth(d) {}

SolnNode::SolnNode(int d, int n) : dir(d), parentNode(n) {}
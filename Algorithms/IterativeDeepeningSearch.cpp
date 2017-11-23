#include "IterativeDeepeningSearch.h"

NodeState IterativeDeepeningSearch::top() {
	return fringe.top();
}

SearchOutput IterativeDeepeningSearch::search(int maxDepth) {
	for (int i = 1; i < maxDepth; i++) {
		if (fringe.size() == 0)
			fringe.push(NodeState{ 0,-1,BlocksWorldBoard{} });
		TreeSearch::search(i);
		if (complete)
			break;
	}
	return output;
}
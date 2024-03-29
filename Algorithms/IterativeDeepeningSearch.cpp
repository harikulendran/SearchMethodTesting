#include "IterativeDeepeningSearch.h"

//Sets the search name for use in image IO operations
IterativeDeepeningSearch::IterativeDeepeningSearch(BlocksWorldBoard start) : TreeSearch(start), startBoard(start) {
	searchName = "IDS";
	push(NodeState{ 0,-1,start });
}

//Uses a stack
NodeState IterativeDeepeningSearch::top() {
	return fringe.top();
}

//loops from 0 to the maxDepth calling a stack tree search (DFS) for each value
SearchOutput IterativeDeepeningSearch::search(int maxDepth) {
	for (int i = 0; i < maxDepth; i++) {
		if (fringe.size() == 0) {
			push(NodeState{ 0,-1,startBoard });
		}
		TreeSearch::search(i);
		if (complete)
			break;
	}
	return output;
}
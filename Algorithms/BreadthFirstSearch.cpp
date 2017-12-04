#include "BreadthFirstSearch.h"

//sets search name for image IO operations
BreadthFirstSearch::BreadthFirstSearch(BlocksWorldBoard start) : TreeSearch(start) {
	searchName = "BFS";
	push(NodeState{ 0,-1,start });
}

//uses a queue
NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
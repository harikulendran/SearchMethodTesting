#include "BreadthFirstSearch.h"

//sets search name for image IO operations
BreadthFirstSearch::BreadthFirstSearch() {
	searchName = "BFS";
	push(NodeState{ 0,-1,BlocksWorldBoard{} });
}

//uses a queue
NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
#include "BreadthFirstSearch.h"

//sets search name for image IO operations
BreadthFirstSearch::BreadthFirstSearch() {
	searchName = "BFS";
}

//uses a queue
NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
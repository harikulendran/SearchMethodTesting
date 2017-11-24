#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch() {
	searchName = "BFS";
}

NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
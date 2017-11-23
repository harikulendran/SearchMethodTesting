#include "BreadthFirstSearch.h"

NodeState BreadthFirstSearch::top() {
	return fringe.front();
}
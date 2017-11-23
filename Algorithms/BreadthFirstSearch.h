#pragma once

#include "TreeSearch.h"
#include <queue>


using namespace std;

class BreadthFirstSearch : public TreeSearch<std::queue> {

protected:
	NodeState top();
};
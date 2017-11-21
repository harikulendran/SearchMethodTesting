#pragma once
#include "BlocksWorldBoard.h"
#include "NodeState.h"

template<class Container>
class TreeSearch <class Container> {
	public:
		SearchOutput output{};
		NodeState currentNode;
		bool complete = false;
		Container fringe;

	public:
		SearchOutput search();

	private:
		void expandNode();
		void goalTest();
};
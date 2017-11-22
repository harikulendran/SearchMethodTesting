#pragma once
#include "BlocksWorldBoard.h"
#include "NodeState.h"

template<template<typename...> class Container> class TreeSearch {
	public:
		SearchOutput output{};
		NodeState currentNode;
		int nodeIndex = 0;
		bool complete = false;
		Container<NodeState> fringe;

	public:
		TreeSearch();

	public:
		SearchOutput search();

	private:
		void expandNode();
		void goalReached();
		
	protected:
		virtual NodeState top() = 0;
		virtual void calculateF(NodeState* ns) = 0;
};

template <template<typename...> class Container> TreeSearch<Container>::TreeSearch() {
	fringe.push(NodeState{ 0,-1,BlocksWorldBoard{} });
	//calculateF(&top());
}


template <template<typename...> class Container> SearchOutput TreeSearch<Container>::search() {
	while (fringe.size() != 0) {
		currentNode = top();
		fringe.pop();
		output.nodesExpanded++;

		if (currentNode.state.isSolved()) {
			goalReached();
			break;
		}

		expandNode();
	}
	return output;
}

template <template<typename...> class Container> void TreeSearch<Container>::goalReached() {
	output.solnDepth = currentNode.depth;
	output.isOptimal = (output.solnDepth == 14 + BOARD_SIZE - 4);
	output.nodesInMemory = fringe.size();
}

template <template<typename...> class Container> void TreeSearch<Container>::expandNode() {
	currentNode.state.checkMoves();
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[i]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard(currentNode.state);
			newBoard.move(static_cast<Direction>(i));
			NodeState newNode{ ++nodeIndex,currentNode.thisNode,move(newBoard),currentNode.depth + 1 };
			calculateF(&newNode);
			fringe.push(newNode);
		}
	}
}
#pragma once
#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include "BoardDrawer.h"

template<template<typename...> class Container> class TreeSearch {
	public:
		SearchOutput output{};
		BoardDrawer boardDrawer{};
		NodeState currentNode;
		int nodeIndex = 0;
		bool complete = false;
		Container<NodeState> fringe;
		map<int, SolnNode> solnStore{};
		bool storeSoln = false;

	public:
		TreeSearch();

	public:
		virtual SearchOutput search(int maxDepth = INT32_MAX);

	protected:
		virtual void expandNode();
		void goalReached();
		virtual NodeState top() = 0;
		virtual void calculateF(NodeState* ns);
		
	private:
		void printSoln();
		void printDir(int i);
};

template <template<typename...> class Container> TreeSearch<Container>::TreeSearch() {
	fringe.push(NodeState{ 0,-1,BlocksWorldBoard{} });
	boardDrawer.draw(BlocksWorldBoard{}, nodeIndex);
}


template <template<typename...> class Container> SearchOutput TreeSearch<Container>::search(int maxDepth) {
	while (fringe.size() != 0) {
		currentNode = top();
		fringe.pop();
		output.nodesExpanded++;

		if (currentNode.state.isSolved()) {
			complete = true;
			goalReached();
			if (storeSoln)
				printSoln();
			break;
		}

		if (fringe.size() > 105000000) {
			cout << "BROKE";
			break;
		}

		if (currentNode.depth < maxDepth)
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

			if (storeSoln)
				solnStore.emplace(nodeIndex, SolnNode{i,currentNode.thisNode});
			if (output.nodesExpanded < 20) {
				boardDrawer.draw(newBoard, nodeIndex);
				//printDir(i);
			}
		}
	}
}

template <template<typename...> class Container> void TreeSearch<Container>::calculateF(NodeState* ns) {
	return;
}

template <template<typename...> class Container> void TreeSearch<Container>::printSoln() {
	int index = currentNode.thisNode;
	int size = currentNode.depth;
	int* soln = new int[size];

	for (int i = 0; i < size; i++) {
		soln[i] = solnStore[index].dir;
		index = solnStore[index].parentNode;
	}

	for (int i = size - 1; i >= 0; i--)
		printDir(soln[i]);
	cout << "\n";

	delete(soln);
}

template <template<typename...> class Container> void TreeSearch<Container>::printDir(int i) {
	switch (static_cast<Direction>(i)) {
	case (Direction::UP) :
		cout << "UP ";
		break;
	case (Direction::DOWN) :
		cout << "DOWN ";
		break;
	case (Direction::LEFT) :
		cout << "LEFT ";
		break;
	case (Direction::RIGHT) :
		cout << "RIGHT ";
		break;
	}
}
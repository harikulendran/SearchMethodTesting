#pragma once
#include "ControlPanel.h"
#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include "BoardDrawer.h"

template<template<typename...> class Container> class TreeSearch {
	public:
		string searchName = "TreeSearch";
		SearchOutput output{};
		BoardDrawer boardDrawer{};
		NodeState currentNode;
		int nodeIndex = -1;
		bool complete = false;
		Container<NodeState> fringe;
		map<int, SolnNode> solnStore{};

	public:
		TreeSearch();

	public:
		virtual SearchOutput search(int maxDepth = INT32_MAX);

	protected:
		virtual void expandNode();
		void goalReached();
		//purely virtual function to describe how the top of the
		//fringe should be accessed.
		virtual NodeState top() = 0;
		virtual void calculateF(NodeState* ns);
		void recordExpansion(int i, BlocksWorldBoard b);
		
	private:
		void printSoln();
		void printDir(int i);
};

//Constructor simply adds the root node
template <template<typename...> class Container> TreeSearch<Container>::TreeSearch() {
	fringe.push(NodeState{ 0,-1,BlocksWorldBoard{} });
	boardDrawer.draw("IDS", BlocksWorldBoard{}, ++nodeIndex);
}

//Main tree search code
template <template<typename...> class Container> SearchOutput TreeSearch<Container>::search(int maxDepth) {
	//boardDrawer.draw(searchName, BlocksWorldBoard{}, 0);
	while (fringe.size() != 0) {
		currentNode = top();
		output.nodesExpanded++;
		fringe.pop();
		if (output.nodesExpanded < 100 && SHOW_EXPANSION_ORDER) {
			//boardDrawer.draw("AStarTest", currentNode.state, nodeIndex);
			printDir(currentNode.dir);
		}

		if (currentNode.state.isSolved()) {
			complete = true;
			goalReached();
			break;
		}

		//makes sure memory of system is not exceeded
		if (fringe.size() > MAX_NODES) {
			cout << "Mem limit reached ";
			break;
		}

		if (currentNode.depth < maxDepth)
			expandNode();
	}
	return output;
}

//collects the required data when a solution is found
template <template<typename...> class Container> void TreeSearch<Container>::goalReached() {
	output.solnDepth = currentNode.depth;
	output.isOptimal = (output.solnDepth == 14 + BOARD_SIZE - 4);
	output.nodesInMemory = fringe.size();
	if (STORE_SOLUTION)
		printSoln();
}

//Takes a node and expands it, adding the child nodes to the fringe
template <template<typename...> class Container> void TreeSearch<Container>::expandNode() {
	currentNode.state.checkMoves();
	/*if (output.nodesExpanded < 20) {
		currentNode.state.print();
		cout << currentNode.thisNode << " - F: " << currentNode.h << " - ";
	}*/
	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[i]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard(currentNode.state);
			newBoard.move(static_cast<Direction>(i));
			NodeState newNode{ ++nodeIndex,currentNode.thisNode,move(newBoard),currentNode.depth + 1 };
			newNode.dir = i;
			calculateF(&newNode);
			fringe.push(newNode);

			recordExpansion(i,newBoard);
		}
	}
	//if (output.nodesExpanded < 20)
		//cout << "\n";
}

//Funtion to store nodes required to trace solution/ output move order 
template <template<typename...> class Container> void TreeSearch<Container>::recordExpansion(int i, BlocksWorldBoard b) {
	if (STORE_SOLUTION)
		solnStore.emplace(nodeIndex, SolnNode{i,currentNode.thisNode});
	if (output.nodesExpanded < 41 && SHOW_ADDITION_ORDER) {
		if (SAVE_IMAGES)
			boardDrawer.draw(searchName, b, nodeIndex);
		if (PRINT_TO_CONSOLE)
			printDir(i);
	}
	output.maxNodesInMemory = (output.maxNodesInMemory > fringe.size()) ? output.maxNodesInMemory : fringe.size();
}

//standard heuristic function, to be overridden in derived classes that need it
template <template<typename...> class Container> void TreeSearch<Container>::calculateF(NodeState* ns) {
	return;
}

//Prints the solution as a string of directions moved by the agent in order to solve the problem
template <template<typename...> class Container> void TreeSearch<Container>::printSoln() {
	int index = currentNode.thisNode;
	int size = currentNode.depth;
	int* soln = new int[size];

	for (int i = 0; i < size; i++) {
		soln[i] = solnStore[index].dir;
		index = solnStore[index].parentNode;
	}

	if (PRINT_TO_CONSOLE) {
		for (int i = size - 1; i >= 0; i--)
			printDir(soln[i]);
		cout << "\n";
	} else {
		boardDrawer.displaySoln(soln,size);
	}

	delete(soln);
}

//Takes the direction as an int and prints out the human readable direction
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
		case (Direction::NA) :
			cout << "NA";
			break;
	}
}
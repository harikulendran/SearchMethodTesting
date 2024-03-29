#pragma once
#include "ControlPanel.h"
#include "BlocksWorldBoard.h"
#include "NodeState.h"
#include "BoardDrawer.h"

template<template<typename...> class Container> class TreeSearch {
	public:
		string searchName = "TreeSearch";
		SearchOutput output{};
		BoardDrawer boardDrawer;
		NodeState currentNode;
		int nodeIndex = 0;
		bool complete = false;
		Container<NodeState> fringe;
		map<int, SolnNode> solnStore{};

	public:
		TreeSearch(BlocksWorldBoard start);

	public:
		virtual SearchOutput search(int maxDepth = INT32_MAX);

	protected:
		virtual void expandNode();
		void goalReached();
		//purely virtual function to describe how the top of the
		//fringe should be accessed.
		virtual NodeState top() = 0;
		void push(NodeState n);
		virtual void calculateF(NodeState* ns);
		int freq[BOARD_SIZE][BOARD_SIZE] = { 0 };
		
	private:
		void printSoln();
		void printDir(int i);
};

template <template<typename...> class Container> void TreeSearch<Container>::push(NodeState n) {
	fringe.push(n);
	if (STORE_SOLUTION)
		solnStore.emplace(nodeIndex, SolnNode{n.dir,n.parentNode});
	if (output.nodesExpanded < 45 && SHOW_ADDITION_ORDER) {
		if (SAVE_IMAGES)
			boardDrawer.draw(searchName, n.state, nodeIndex);
		if (PRINT_ADD_TO_CONSOLE)
			printDir(n.dir);
	}
	output.maxNodesInMemory = (output.maxNodesInMemory > fringe.size()) ? output.maxNodesInMemory : fringe.size();
}

//Constructor simply adds the root node
template <template<typename...> class Container> TreeSearch<Container>::TreeSearch(BlocksWorldBoard start) : boardDrawer(BoardDrawer(start)) {}

//Main tree search code
template <template<typename...> class Container> SearchOutput TreeSearch<Container>::search(int maxDepth) {
	//boardDrawer.draw(searchName, blocksworldboard{}, 0);
	while (fringe.size() != 0) {
		currentNode = top();
		fringe.pop();

		//prints the nodes expanded
		if (output.nodesExpanded < 100 && SHOW_EXPANSION_ORDER) {
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


	//print and save image of heat map
	if (DRAW_HEATMAP) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				cout << freq[j][i] << " ";
			}
			cout << endl;
		}
		BoardDrawer vc{ BlocksWorldBoard{} };
		vc.drawHeatMap(searchName, freq);
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
	output.nodesExpanded++;

	freq[currentNode.state.agent.x][currentNode.state.agent.y]++;

	for (int i = 0; i < 4; i++) {
		if (currentNode.state.validMoves[i]) {
			BlocksWorldBoard newBoard = BlocksWorldBoard(currentNode.state);
			newBoard.move(static_cast<Direction>(i));
			NodeState newNode{ ++nodeIndex,currentNode.thisNode,move(newBoard),currentNode.depth + 1 };
			newNode.dir = i;
			calculateF(&newNode);
			push(newNode);
		}
	}
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

	if (PRINT_TO_CONSOLE && size <20) {
		BlocksWorldBoard vs{};
		for (int i = size - 1; i >= 0; i--) {
			boardDrawer.draw("soln", vs, i);
			vs.move(static_cast<Direction>(soln[i]));
			printDir(soln[i]);
		}
		cout << "asdf\n";
	} else if (size < 20) {
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
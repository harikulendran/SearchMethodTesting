#pragma once
#include "BlocksWorldBoard.h"
#include "NodeState.h"

template<template <class> class Container> class TreeSearch {
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
		NodeState top();
};


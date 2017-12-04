#pragma once

//CONTROL THE PROBLEM COMPLEXITY
const static int BOARD_SIZE = 4;
const static int NO_OF_PIECES = 3;

//OUTPUT CONTROLS
const static bool DRAW_HEATMAP = false;

//set show addition order to true to show order nodes
//are added to the fringe up to 45 nodes expanded
//set save images to true to save the nodes as images
//set print to true to also print to the console.
	const static bool SAVE_IMAGES = false;
	const static bool SHOW_ADDITION_ORDER = false;
	const static bool PRINT_ADD_TO_CONSOLE = false;

//set to true in order print the expanded nodes to console
//up to 100 nodes
	const static bool SHOW_EXPANSION_ORDER = false;

//Set store solution to true to in order to view the found solution
//set print to console to true to print the soln to console or false
//in order to display the soln animation in a GUI window.
	const static bool STORE_SOLUTION = true;
	const static bool PRINT_TO_CONSOLE = true;
//MAX MEMORY ALLOWED. roughly equates to 10gigs of ram
const static int MAX_NODES = 105000000;
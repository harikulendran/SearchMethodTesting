#pragma once

//CONTROL THE PROBLEM COMPLEXITY
const static int BOARD_SIZE = 4;
const static int NO_OF_PIECES = 3;

//OUTPUT CONTROLS
const static bool STORE_SOLUTION = false;
const static bool SAVE_IMAGES = true;
const static bool SHOW_EXPANSION_ORDER = false;
const static bool SHOW_ADDITION_ORDER = true;
const static bool PRINT_TO_CONSOLE = false;

//MAX MEMORY ALLOWED. roughly equates to 10gigs of ram
const static int MAX_NODES = 105000000;
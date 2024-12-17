/**
 * @file funcInitializeGame.h
 * @brief This file contains the function declarations for the functions that initialize the game.
 */

// Preprocessor Directives
#include <stdbool.h>

bool isValidPlayers(int nNumberOfPlayers);  // Checker for the validity of number of players
int getSequenceOfPlayers(int nNumberOfPlayers);  // Sequence of turns between entered number of players
void initializeGame(int nNumPlayers, int* nSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);  // Initialize the game
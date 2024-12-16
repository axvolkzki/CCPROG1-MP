/**
 * @file funcInitializeGame.c
 * @brief This file contains the function definitions for the functions that initialize the game.
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdbool.h>

// Function Definitions
/**
 * @brief This function checks if the number of players is valid.
 * @param nNumberOfPlayers is the number of players.
 * @return int
 */
bool isValidPlayers(int nNumberOfPlayers) {
    if (nNumberOfPlayers >= 2 && nNumberOfPlayers <= 5)
        return true;
    else
        return false;
}
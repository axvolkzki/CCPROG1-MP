/**
 * @file funcHelper.c
 * @brief This file contains the function definitions for the functions that help in the game's implementation.
 */

// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>


// Function Definitions
/**
 * @brief This function changes the text color to red.
 * @param void
 * @return void
 */
void red() {
    printf("\033[0;31m");
}

/**
 * @brief This function changes the text color to yellow.
 * @param void
 * @return void
 */
void yellow() {
    printf("\033[0;33m");
}

/**
 * @brief This function changes the text color to green.
 * @param void
 * @return void
 */
void green() {
    printf("\033[0;32m");
}

/**
 * @brief This function changes the text color to blue.
 * @param void
 * @return void
 */
void blue() {
    printf("\033[0;34m");
}

/**
 * @brief This function changes the text color to purple.
 * @param void
 * @return void
 */
void purple() {
    printf("\033[0;35m");
}

/**
 * @brief This function changes the text color to cyan.
 * @param void
 * @return void
 */
void cyan() {
    printf("\033[0;36m");
}

/**
 * @brief This function resets the text color.
 * @param void
 * @return void
 */
void reset() {
    printf("\033[0m");
}

/**
 * @brief This function gets the sequence of players.
 * @param nNumberOfPlayers is the number of players.
 * @return int is the sequence of players.
 */
int getDieSequence(int nNumberOfPlayers) {
    return (int)rand() % nNumberOfPlayers + 1;
}
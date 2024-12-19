/**
 * @file funcHelper.c
 * @brief This file contains the function definitions for the functions that help in the game's implementation.
 */

// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>

#define D10 10


// Function Definitions
/**
 * @brief This function changes the text color to red.
 * @param void
 * @return void
 */
void red() { printf("\033[0;31m"); }

/**
 * @brief This function changes the text color to yellow.
 * @param void
 * @return void
 */
void yellow() { printf("\033[0;33m"); }

/**
 * @brief This function changes the text color to green.
 * @param void
 * @return void
 */
void green() { printf("\033[0;32m"); }

/**
 * @brief This function changes the text color to blue.
 * @param void
 * @return void
 */
void blue() { printf("\033[0;34m"); }

/**
 * @brief This function changes the text color to purple.
 * @param void
 * @return void
 */
void purple() { printf("\033[0;35m"); }

/**
 * @brief This function changes the text color to cyan.
 * @param void
 * @return void
 */
void cyan() { printf("\033[0;36m"); }

/**
 * @brief This function resets the text color.
 * @param void
 * @return void
 */
void reset() { printf("\033[0m"); }

/**
 * @brief This function gets the sequence of players.
 * @param nNumberOfPlayers is the number of players.
 * @return int is the sequence of players.
 */
int getDieSequence(int nNumberOfPlayers) {
    return (int)rand() % nNumberOfPlayers + 1;
}

/**
 * @brief This function generates a random digit from a 10-sided die.
 * @param void
 * @return int is the generated random digit.
 */
int getDieMovement() {
    return (int)rand() % D10 + 1;
}

/**
 * @brief This function gets the updated player sequence.
 * @param nSequence is the sequence of players.
 * @return int is the new sequence of players.
 */
int getUpdatedPlayerSequence(int nSequence) {
    int nValue = 0, count = 0;
    int i, j;
    int nPowerOfTen = 1;
    int nFirstDigit, nRemovedFirstDigit, nNewSeq;

    nValue = nSequence;

    for (i = 1; nSequence > 5; i++) {
        nSequence /= 10;
        nFirstDigit = nSequence;
        count++;
    }

    for (j = 1; j <= count; j++) {
        nPowerOfTen *= 10;
    }

    nRemovedFirstDigit = nValue - (nFirstDigit * nPowerOfTen);
    nNewSeq = (10 * nRemovedFirstDigit) + nFirstDigit;

    return nNewSeq;
}

/**
 * @brief This function gets the current player.
 * @param nSequence is the sequence of players.
 * @return int is the current player.
 */
int getCurrentPlayer(int nSequence) {
    int nFirstNum;

    while (nSequence > 5) {
        nSequence /= 10;
        nFirstNum = nSequence;
    }

    return nFirstNum;
}

/**
 * @brief This function clears the input buffer.
 * @param void
 * @return void
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
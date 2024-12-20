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
 * @brief This function implemennets the roll of double fives.
 * @param nPosition is the position of the player.
 * @param nRow is the row position of the player.
 * @param nColumn is the column position of the player.
 * @return int is the position of the player.
 */
int getRollDoubleFive(int nPosition, int nRow, int nColumn) {
    int nStayRow, nStayColumn;

    if (nPosition % 10 == 0) { // If the player is on the even row
        if (nPosition == 0) {
            nStayRow = 0;
            nStayColumn = 0;
        } else {
            nStayRow = nPosition / 10;
            nStayColumn = (nPosition % 10) + 1;
        }
    } else {
        nStayRow = (nPosition / 10) + 1;
        nStayColumn = nPosition % 10;
    }

    cyan();
    printf("[System] ");
    reset();
    printf("You rolled %d and %d. You missed your turn, don't move!\n", nRow, nColumn);
    cyan();
    printf("[System] ");
    reset();
    printf("Sorry! Please stay on tile %d (row %d, col %d).\n", nPosition, nStayRow, nStayColumn);
    return nPosition; // Will not proceed to objects & go back to main
}

/**
 * @brief This function implements the roll of double threes.
 * @param nPosition is the position of the player.
 * @param nRow is the row position of the player.
 * @param nColumn is the column position of the player.
 * @return int is the position of the player.
 */
int getRollDoubleThree(int nPosition, int nRow, int nColumn) {
    int nTile = 0;

    // If nPosition >= 71 && nPosition <= 99, the player will move to tile 99
    if (nPosition >= 71 && nPosition <= 99) {
        nTile = 99;
        nPosition = nTile;
        nRow = 10;
        nColumn = 2;

        cyan();
        printf("[System] ");
        reset();
        printf("You rolled 3 and 3. Please proceed to tile %d (row: %d, col: %d).\n", nTile, nRow, nColumn);
    } else {
        // Extract the row and column of the player
        if (nPosition % 10 == 0) { // If the player is on the even row
            if (nPosition == 0) {
                nRow = 0;
                nColumn = 0;
            } else {
                nRow = nPosition / 10;
                nColumn = (nPosition % 10) + 1;
            }
        } else {
            nRow = (nPosition / 10) + 1;
            nColumn = nPosition % 10;
        }

        //printf("Debugger (Before): nRow = %d, nColumn = %d\n", nRow, nColumn);
        // Add 3 to the row, and 1 to the column
        nRow += 3;
        
        if (nColumn == 0) {
            nColumn += 1;
        }
        //printf("Debugger (After): nRow = %d, nColumn = %d\n", nRow, nColumn);

        // New tile
        if (nRow % 2 == 0) {
            nTile = ((nRow * 10) - (nColumn - 1));
        } else {
            nTile = (((nRow - 1) * 10) + nColumn);
        }

        cyan();
        printf("[System] ");
        reset();
        printf("You rolled 3 and 3. Please proceed to tile %d (row: %d, col: %d).", nTile, nRow, nColumn);
    }

    return nTile;
}

/**
 * @brief This function gets the tile movement of the player.
 * @param nRow is the row position of the player.
 * @param nColumn is the column position of the player.
 * @return int is the tile movement of the player.
 */
int getTileMovement(int nRow, int nColumn) {
    int nTile = 0;

    if (nRow % 2 == 0) {
        nTile = ((nRow * 10) - (nColumn - 1));
    } else {
        nTile = (((nRow - 1) * 10) + nColumn);
    }

    return nTile;
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
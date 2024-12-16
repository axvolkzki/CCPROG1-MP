/**
 * @file funcDisplay.c
 * @brief This file contains the function definitions for the functions that display the game's needed information.
 */

// Preprocessor Directives
#include <stdio.h>

#include "../Header/funcHelper.h"

// Constant Definitions
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10


/**
 * @brief This function displays the divider of the game.
 * @param void
 * @return void
 */
void displayDivider() {
    // 80 characters
    printf("================================================================================");
    printf("\n");
}


/**
 * @brief This function displays the title of the game.
 * @param void
 * @return void
 */
void displayHeader() {
    // 47 characters
	printf("%63s\n", "Welcome to Doggos, Ladders, Slides and U-turns!");
}

/**
 * @brief This function displays the board of the game.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void displayBoard(int nP1Pos, int nP2Pos, int nP3Pos, int nP4Pos, int nP5Pos) {
    int nRow, nCol;
    int nEvenTile = 100;
    int nOddTile = 101;

    for(nRow = BOARD_HEIGHT; nRow >= 1; nRow--) {
        for(nCol = 1; nCol <= BOARD_WIDTH; nCol++) {
            // printf("   %d\t", nEvenTile);
            // nEvenTile--;

            if (nRow % 2 == 0) {    // for even rows
                
                if (nP1Pos == nEvenTile) {
                    red();
                    printf("   P1\t");
                } else if (nP2Pos == nEvenTile) {
                    yellow();
                    printf("   P2\t");
                } else if (nP3Pos == nEvenTile) {
                    green();
                    printf("   P3\t");
                } else if (nP4Pos == nEvenTile) {
                    blue();
                    printf("   P4\t");
                } else if (nP5Pos == nEvenTile) {
                    purple();
                    printf("   P5\t");
                } else {
                    reset();
                    printf("   %d\t", nEvenTile);
                }

                //printf("   %d\t", nEvenTile);
                nEvenTile--;
                nOddTile = nEvenTile - 9;
            } else {                // for odd rows
                
                if (nP1Pos == nOddTile) {
                    red();
                    printf("   P1\t");
                } else if (nP2Pos == nOddTile) {
                    yellow();
                    printf("   P2\t");
                } else if (nP3Pos == nOddTile) {
                    green();
                    printf("   P3\t");
                } else if (nP4Pos == nOddTile) {
                    blue();
                    printf("   P4\t");
                } else if (nP5Pos == nOddTile) {
                    purple();
                    printf("   P5\t");
                } else {
                    reset();
                    printf("   %d\t", nOddTile);
                }
                    
                //printf("   %d\t", nOddTile);
                nOddTile++;
                nEvenTile--;
            }
        }
        printf("\n");
    }
}

/**
 * @brief This function displays the current position of all players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void displayAllPlayersCurrentPosition(int nP1Pos, int nP2Pos, int nP3Pos, int nP4Pos, int nP5Pos) {
    printf("%55s\n", "[All Player's Current Position]");


    printf("\t\t");
    red();
    printf("P1 @ %d", nP1Pos);

    reset();
    printf(" | ");

    yellow();
    printf("P2 @ %d", nP2Pos);

    reset();
    printf(" | ");

    green();
    printf("P3 @ %d", nP3Pos);

    reset();
    printf(" | ");

    blue();
    printf("P4 @ %d", nP4Pos);

    reset();
    printf(" | ");

    purple();
    printf("P5 @ %d", nP5Pos);

    reset();
    printf("\n");
}
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
 * @brief This function displays the position of Player 1.
 * @param nP1Pos is the position of Player 1.
 * @return void
 */
void displayP1Position(int nP1Pos) {
    red();
    printf("P1 @ %d", nP1Pos);
}

/**
 * @brief This function displays the position of Player 2.
 * @param nP2Pos is the position of Player 2.
 * @return void
 */
void displayP2Position(int nP2Pos) {
    yellow();
    printf("P2 @ %d", nP2Pos);
}

/**
 * @brief This function displays the position of Player 3.
 * @param nP3Pos is the position of Player 3.
 * @return void
 */
void displayP3Position(int nP3Pos) {
    green();
    printf("P3 @ %d", nP3Pos);
}

/**
 * @brief This function displays the position of Player 4.
 * @param nP4Pos is the position of Player 4.
 * @return void
 */
void displayP4Position(int nP4Pos) {
    blue();
    printf("P4 @ %d", nP4Pos);
}

/**
 * @brief This function displays the position of Player 5.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void displayP5Position(int nP5Pos) {
    purple();
    printf("P5 @ %d", nP5Pos);
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
void displayAllPlayersCurrentPosition(int nNumPlayers, int nP1Pos, int nP2Pos, int nP3Pos, int nP4Pos, int nP5Pos) {
    printf("Current Position of All Players\t: ");

    switch (nNumPlayers) {
        case 2:
            displayP1Position(nP1Pos);
            reset();
            printf(" | ");
            displayP2Position(nP2Pos);
            break;
        case 3:
            displayP1Position(nP1Pos);
            reset();
            printf(" | ");
            displayP2Position(nP2Pos);
            reset();
            printf(" | ");
            displayP3Position(nP3Pos);
            break;
        case 4:
            displayP1Position(nP1Pos);
            reset();
            printf(" | ");
            displayP2Position(nP2Pos);
            reset();
            printf(" | ");
            displayP3Position(nP3Pos);
            reset();
            printf(" | ");
            displayP4Position(nP4Pos);
            break;
        case 5:
            displayP1Position(nP1Pos);
            reset();
            printf(" | ");
            displayP2Position(nP2Pos);
            reset();
            printf(" | ");
            displayP3Position(nP3Pos);
            reset();
            printf(" | ");
            displayP4Position(nP4Pos);
            reset();
            printf(" | ");
            displayP5Position(nP5Pos);
            break;
    }

    reset();
    printf("\n");
}

/**
 * @brief This function displays the sequence of players.
 * @param nSequence is the sequence of players.
 * @return void
 */
void displaySequenceOfPlayers(int nSequence) {
    int nFirstNum = 0;
    int nSecondNum = 0;
    int nThirdNum = 0;
    int nFourthNum = 0;
    int nFifthNum = 0;

    printf("Sequence of Players\t\t: ");
    
    if (nSequence > 10000) {
        nFirstNum = nSequence / 10000;
        nSequence %= 10000;
        nSecondNum = nSequence / 1000;
        nSequence %= 1000;
        nThirdNum = nSequence / 100;
        nSequence %= 100;
        nFourthNum = nSequence / 10;
        nSequence %= 10;
        nFifthNum = nSequence;

        red();
        printf("P%d", nFirstNum);

        reset();
        printf(" -> ");

        yellow();
        printf("P%d", nSecondNum);

        reset();
        printf(" -> ");

        green();
        printf("P%d", nThirdNum);

        reset();
        printf(" -> ");

        blue();
        printf("P%d", nFourthNum);

        reset();
        printf(" -> ");

        purple();
        printf("P%d", nFifthNum);

        reset();
    } else if (nSequence > 1000) {
        nFirstNum = nSequence / 1000;
        nSequence %= 1000;
        nSecondNum = nSequence / 100;
        nSequence %= 100;
        nThirdNum = nSequence / 10;
        nSequence %= 10;
        nFourthNum = nSequence;

        red();
        printf("P%d", nFirstNum);

        reset();
        printf(" -> ");

        yellow();
        printf("P%d", nSecondNum);

        reset();
        printf(" -> ");

        green();
        printf("P%d", nThirdNum);

        reset();
        printf(" -> ");

        blue();
        printf("P%d", nFourthNum);

        reset();
    } else if (nSequence > 100) {
        nFirstNum = nSequence / 100;
        nSequence %= 100;
        nSecondNum = nSequence / 10;
        nSequence %= 10;
        nThirdNum = nSequence;

        red();
        printf("P%d", nFirstNum);

        reset();
        printf(" -> ");

        yellow();
        printf("P%d", nSecondNum);

        reset();
        printf(" -> ");

        green();
        printf("P%d", nThirdNum);

        reset();
    } else if (nSequence > 10) {
        nFirstNum = nSequence / 10;
        nSequence %= 10;
        nSecondNum = nSequence;

        red();
        printf("P%d", nFirstNum);
    }

    reset();
    printf("\n");
}

/**
 * @brief This function displays the initialization status of the game.
 * @param nNumPlayers is the number of players.
 * @param nSequence is the sequence of players.
 * @return void
 */
void displayInitializeStatus(int nNumPlayers, int nSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    displayDivider();
    displayHeader();
    displayDivider();

    printf("\n");
    cyan();
    printf("%50s\n", "[Game Initializated!]");
    printf("\n");
    reset();
    displayBoard(*nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
    printf("\n\n");
    displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
 
    displaySequenceOfPlayers(nSequence);
    printf("\n\n");
}
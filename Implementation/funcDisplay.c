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
void displayGameTitle() {
    // 43 characters
    cyan();
	printf("%61s\n", "Doggos, Ladders, Slides and U-turns (DLSU)!");
    reset();
}

/**
 * @brief This function displays the end of the game.
 * @param void
 * @return void
 */
void displayEndGame() {
    displayDivider();
    displayGameTitle();
    displayDivider();
    printf("\n\n");

    cyan();
    printf("%69s", "Thank you for playing Doggos, Ladders, Slides, and U-Turns!");
    printf("\n");
    printf("%47s", "SEE YOU AGAIN!");
    reset();

    printf("\n\n");
    displayDivider();
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

    reset();
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
    reset();
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
void displaySequenceOfPlayers(int nSequence, int nCurrentPlayer) {
    int nFirstNum = 0;
    int nSecondNum = 0;
    int nThirdNum = 0;
    int nFourthNum = 0;
    int nFifthNum = 0;

    reset();
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
        
        if (nCurrentPlayer == nFirstNum) {
            cyan();
            printf("P%d", nFirstNum);
        } else {
            reset();
            printf("P%d", nFirstNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nSecondNum) {
            cyan();
            printf("P%d", nSecondNum);
        } else {
            reset();
            printf("P%d", nSecondNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nThirdNum) {
            cyan();
            printf("P%d", nThirdNum);
        } else {
            reset();
            printf("P%d", nThirdNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nFourthNum) {
            cyan();
            printf("P%d", nFourthNum);
        } else {
            reset();
            printf("P%d", nFourthNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nFifthNum) {
            cyan();
            printf("P%d", nFifthNum);
        } else {
            reset();
            printf("P%d", nFifthNum);
        }

    } else if (nSequence > 1000) {
        nFirstNum = nSequence / 1000;
        nSequence %= 1000;
        nSecondNum = nSequence / 100;
        nSequence %= 100;
        nThirdNum = nSequence / 10;
        nSequence %= 10;
        nFourthNum = nSequence;

        if (nCurrentPlayer == nFirstNum) {
            cyan();
            printf("P%d", nFirstNum);
        } else {
            reset();
            printf("P%d", nFirstNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nSecondNum) {
            cyan();
            printf("P%d", nSecondNum);
        } else {
            reset();
            printf("P%d", nSecondNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nThirdNum) {
            cyan();
            printf("P%d", nThirdNum);
        } else {
            reset();
            printf("P%d", nThirdNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nFourthNum) {
            cyan();
            printf("P%d", nFourthNum);
        } else {
            reset();
            printf("P%d", nFourthNum);
        }

    } else if (nSequence > 100) {
        nFirstNum = nSequence / 100;
        nSequence %= 100;
        nSecondNum = nSequence / 10;
        nSequence %= 10;
        nThirdNum = nSequence;

        if (nCurrentPlayer == nFirstNum) {
            cyan();
            printf("P%d", nFirstNum);
        } else {
            reset();
            printf("P%d", nFirstNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nSecondNum) {
            cyan();
            printf("P%d", nSecondNum);
        } else {
            reset();
            printf("P%d", nSecondNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nThirdNum) {
            cyan();
            printf("P%d", nThirdNum);
        } else {
            reset();
            printf("P%d", nThirdNum);
        }

    } else if (nSequence > 10) {
        nFirstNum = nSequence / 10;
        nSequence %= 10;
        nSecondNum = nSequence;

        if (nCurrentPlayer == nFirstNum) {
            cyan();
            printf("P%d", nFirstNum);
        } else {
            reset();
            printf("P%d", nFirstNum);
        }

        reset();
        printf(" -> ");

        if (nCurrentPlayer == nSecondNum) {
            cyan();
            printf("P%d", nSecondNum);
        } else {
            reset();
            printf("P%d", nSecondNum);
        }
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
    displayGameTitle();
    displayDivider();

    printf("\n");
    cyan();
    printf("%50s\n", "[Game Initializated!]");
    printf("\n");
    reset();
    displayBoard(*nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
    printf("\n\n");
    displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
 
    displaySequenceOfPlayers(nSequence, 0);
    printf("\n\n");
}

/**
 * @brief This function displays the current player.
 * @param nCurrentPlayer is the current player.
 * @return void
 */
void displayCurrentPlayer(int nCurrentPlayer) {
    cyan();
    printf("[System] ");
    reset();
    printf("Now Playing\t\t: P%d\n", nCurrentPlayer);
    reset();
}

/**
 * @brief This function displays the rankings of the players based on their positions.
 * @param nNumPlayers is the number of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void displayRankings(int nNumPlayers, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    
    // Display the rankings
    // Header
    printf("%48s", "+------+--------+");
    printf("\n");
    printf("%48s", "| RANK | PLAYER |");
    printf("\n");
    printf("%48s", "+------+--------+");
    printf("\n");

    switch (nNumPlayers) {
        case 2:
            int nPositions[2] = {*nP1Pos, *nP2Pos};
            char* arrPlayers[3] = {"P1", "P2"};
            int arrIndices[3];

            // Initialize the array
            for (int i = 0; i < 3; i++) {
                arrIndices[i] = i;
            }

            // Sort based on the positions
            for (int i = 0; i < 2; i++) {
                for (int j = i + 1; j < 2; j++) {
                    if (nPositions[i] < nPositions[j]) {
                        int temp = nPositions[i];
                        nPositions[i] = nPositions[j];
                        nPositions[j] = temp;

                        int tempIndex = arrIndices[i];
                        arrIndices[i] = arrIndices[j];
                        arrIndices[j] = tempIndex;
                    }
                }
            }

            for (int i = 0; i < nNumPlayers; i++) {
                printf("%32s", "|");
                printf("  %d   |  ", i + 1);
                switch (arrIndices[i]) {
                    case 0: red(); break;
                    case 1: yellow(); break;
                    case 2: green(); break;
                    case 3: blue(); break;
                    case 4: purple(); break;
                }
                printf("%s ", arrPlayers[arrIndices[i]]);
                reset();

                printf("   |\n");
            }
    }

    // Footer
    printf("%48s", "+------+--------+");
    printf("\n");   
}

/**
 * @brief This function displays the winner of the game.
 * @param nCurrentPlayer is the current player.
 * @param nCurrDoggo is the current number of doggos.
 * @param nCurrLadder is the current number of ladders.
 * @param nCurrSlide is the current number of slides.
 * @param nCurrUTurn is the current number of U-turns.
 * @param nCurrObjectNavFarthest is the farthest object navigated.
 * @param nWinningMove is the winning move.
 * @return void
 */
void displayWinnerSummary(int nCurrentPlayer, int* nCurrDoggos, int* nCurrLadders, int* nCurrSlides, int* nCurrUTurns, int* nCurrObjectNavFarthest, int* nWinningMove) {
    printf("\n");
    cyan();
    printf("%55s", "[Winner Winner Chicken Dinner!]\n");
    printf("\n");
    reset();
    printf("You reached the goal! YOU WIN!\n");
    printf("Doggo appeared %d times.\n", *nCurrDoggos);
    printf("You climbed ladders %d times.\n", *nCurrLadders);
    printf("You rode slides %d times.\n", *nCurrSlides);
    printf("You took U-turns %d times.\n", *nCurrUTurns);

    switch (*nCurrObjectNavFarthest) {
        case 1:
            printf("The doggo took you to the farthest tile.\n");
            break;
        case 2:
            printf("The ladder took you to the farthest tile.\n");
            break;
        case 3:
            printf("The slide took you to the farthest tile.\n");
            break;
        case 4:
            printf("The U-turn took you to the farthest tile.\n");
            break;
    }

    switch (*nWinningMove) {
        case 1:
            printf("The winning move was when you followed the doggo.\n");
            break;
        case 2:
            printf("The winning move was when you climbed the ladder.\n");
            break;
        case 3:
            printf("The winning move was when you rode the slide.\n");
            break;
        case 4:
            printf("The winning move was when you took the U-turn.\n");
            break;
    }
    printf("\n\n");
}
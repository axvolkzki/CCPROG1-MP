/**
 * @file funcGamePlay.c
 * @brief This file contains the function definitions for the functions that handle the game's gameplay.
 */

// Preprocessor directives>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "../Header/funcHelper.h"
#include "../Header/funcDisplay.h"


/**
 * @brief This function checks if the response is valid for replaying the game.
 * @param x is the response of the user.
 * @return boolean if the response is valid.
 */
bool isValidResponse(char x) {
    if (x == 'Y' || x == 'y' || x == 'N' || x == 'n')
        return true;
    else
        return false;
}

/**
 * @brief This function asks the user if they want to play again.
 * @param void
 * @return boolean if the user wants to play again.
 */
bool wantPlayAgain() {
    char cResponse = ' ';
    bool isValidRes = false;

    // Ask user to play again
    printf("\n\n");
    printf("Would you like to play again?\n");
    printf("Enter\t: ");
    blue();
    printf("[Y]es \t");
    red();
    printf("[N]o \n");
    reset();
    printf("Answer\t: ");
    scanf(" %c", &cResponse);

    isValidRes = isValidResponse(cResponse);

    while(!isValidRes) {
        red();
        printf("\nSystem\t: \"Invalid input! Try again!\"\n");

        reset();
        printf("Answer\t: ");
        scanf(" %c", &cResponse);

        isValidRes = isValidResponse(cResponse);
    }

    if(isValidRes) {
        if(cResponse == 'Y' || cResponse == 'y')
            return true;
        else if(cResponse == 'N' || cResponse == 'n')
            return false;
    }
}

/**
 * @brief This function handles the gameplay of a player.
 * @param nCurrentPlayer is the current player.
 * @param currPlayerPos is the current position of the player.
 * @param currPlayerDoggos is the number of doggos the player has.
 * @param currPlayerLadders is the number of ladders the player has.
 * @param currPlayerSlides is the number of slides the player has.
 * @param currPlayerUTurns is the number of U-turns the player has.
 * @param currPlayerObjectNavFarthest is the farthest object navigated by the player.
 * @param nWinningMove is the winning move.
 * @return int is the new position that triggers if there is a winning move.
 */
int getGameplay(int nCurrentPlayer, int* currPlayerPos, int* currPlayerDoggos, int* currPlayerLadders, int* currPlayerSlides, int* currPlayerUTurns, int* currPlayerObjectNavFarthest, int* nWinningMove) {
    // Variables
    int nRow, nColumn, nTile, nDiceObject;
    int nDoggos = *currPlayerDoggos;
    int nLadders = *currPlayerLadders;
    int nSlides = *currPlayerSlides;
    int nUTurns = *currPlayerUTurns;
    int nObjectNavFarthest = *currPlayerObjectNavFarthest;
    int cResponse = ' ';
    int nPosition = *currPlayerPos;
    int tempTile = 0;

    //printf("Debugger: nPosition = %d\n", nPosition);
    // Debugger - for testing the winning move
    // if (nCurrentPlayer == 1) {
    //     *currPlayerPos = 100;
    //     *currPlayerDoggos = 1;
    //     *currPlayerLadders = 10;
    //     *currPlayerSlides = 20;
    //     *currPlayerUTurns = 30;
    //     *currPlayerObjectNavFarthest = 2;
    //     *nWinningMove = 1;
    //     return 100;
    // }

    // Start of the game
    cyan();
    printf("[System] ");
    reset();
    printf("[%d] Player %d, please roll a pair of D10 dice by entering any key.", nPosition, nCurrentPlayer);
    scanf(" %c", &cResponse);
    

    if (nPosition >= 90 && nPosition <= 99) {
        // Start moving the player
        nColumn = getDieMovement();
        nTile = nPosition + nColumn;
        
        if (nTile > 100) {
            nTile = 100 - (nTile - 100);
        }

        // Check if there is an object in the tile
        nDiceObject = getDieMovement();
        //nDiceObject = 4;    // Debugger

        // Restrict ladders on tiles 90 to 99
        if (nTile >= 90 && nTile <= 99 && nDiceObject == 2) {
            while (nDiceObject == 2) {
                nDiceObject = getDieMovement();
            }
        }

        // Get movement of the player based on the object
        nRow = getDieMovement();
        nColumn = getDieMovement();

        // Get the destination tile based on the object
        tempTile = getTileMovement(nRow, nColumn);

        switch (nDiceObject) {
            case 1: // Doggo
                // Goes anywhere on the board
                if (nTile < tempTile) {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A doggo is on tile %d. Yay! Please follow the doggo to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nDoggos++;

                    if (nTile > nObjectNavFarthest) {
                        nObjectNavFarthest = nTile;
                    }
                } else {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A doggo is on tile %d. Nay! Please follow the doggo to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nDoggos++;
                }
                break;
            case 2: // Ladder
                // No Ladders allowed on tiles 90 to 99
                //nDiceObject = getDieMovement();
                break;
            case 3: // Slide
                // Ensure that the destination tile is less than the current tile
                while (nTile <= tempTile) {
                    nRow = getDieMovement();
                    nColumn = getDieMovement();

                    if (nRow % 2 == 0) {
                        tempTile = ((nRow * 10) - (nColumn - 1));
                    } else {
                        tempTile = (((nRow - 1) * 10) + nColumn);
                    }
                }

                if (nTile > tempTile) {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A slide is on tile %d. Nay! Please slide down to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nSlides++;
                }
                break;
            case 4: // U-Turn
                // The user will go back to the previous position
                int nPrevRow, nPrevColumn;
                
                if (nPosition % 10 == 0) { // If the player is on the even row
                    if (nPosition == 0) {
                        nPrevRow = 0;
                        nPrevColumn = 0;
                    } else {
                        nPrevRow = nPosition / 10;
                        nPrevColumn = (nPosition % 10) + 1;
                    }
                } else {
                    nPrevRow = (nPosition / 10) + 1;
                    nPrevColumn = nPosition % 10;
                }

                cyan();
                printf("[System] ");
                reset();
                printf("A U-turn is on tile %d. Sorry! Please go back to tile %d (row: %d, col: %d).\n", nTile, nPosition, nPrevRow, nPrevColumn);

                nTile = nPosition;
                break;
            default:
                cyan();
                printf("[System] ");
                reset();
                printf("There is no doggo, ladder, slide nor U-turn on tile %d. Switching Players!\n", nTile);
                break;
        }

    } else if (nPosition >= 0 && nPosition <= 89) {
        // Start moving the player
        nRow = getDieMovement();
        nColumn = getDieMovement();

        // Debugger
        //nRow = 3;
        //nColumn = 3;

        // If nRow == 5 and nColumn == 5, the player will miss their turn
        if (nRow == 5 && nColumn == 5) {
            nPosition = getRollDoubleFive(nPosition, nRow, nColumn);
            return nPosition;
        }

        // If nRow == 3 and nColumn == 3, the player will move to the tile directly 3 rows above
        if (nRow == 3 && nColumn == 3) {
            nTile = getRollDoubleThree(nPosition, nRow, nColumn);
        } else {
            // Get the destination tile on normal circumstances
            nTile = getTileMovement(nRow, nColumn);

            cyan();
            printf("[System] ");
            reset();
            printf("You rolled %d and %d. Please proceed to tile %d.\n", nRow, nColumn, nTile);
        }
        
        
        // Check if there is an object in the tile
        nDiceObject = getDieMovement();
        //nDiceObject = 4;    // Debugger

        // Restrict slides on tiles 1 to 10
        if (nTile >= 1 && nTile <= 10 && nDiceObject == 3) {
            while (nDiceObject == 3) {
                nDiceObject = getDieMovement();
            }
        }

        // Get movement of the player based on the object
        nRow = getDieMovement();
        nColumn = getDieMovement();

        // Get the destination tile based on the object
        tempTile = getTileMovement(nRow, nColumn);

        switch (nDiceObject) {
            case 1: // Doggo
                // Goes anywhere on the board
                if (nTile < tempTile) {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A doggo is on tile %d. Yay! Please follow the doggo to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nDoggos++;

                    if (nTile > nObjectNavFarthest) {
                        nObjectNavFarthest = nTile;
                    }
                } else {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A doggo is on tile %d. Nay! Please follow the doggo to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nDoggos++;
                }
                break;
            case 2: // Ladder
                // Ensure that the destination tile is greater than the current tile
                while (nTile >= tempTile) {
                    nRow = getDieMovement();
                    nColumn = getDieMovement();

                    if (nRow % 2 == 0) {
                        tempTile = ((nRow * 10) - (nColumn - 1));
                    } else {
                        tempTile = (((nRow - 1) * 10) + nColumn);
                    }
                }

                if (nTile < tempTile) {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A ladder is on tile %d. Yay! Please climb the ladder to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nLadders++;

                    if (nTile > nObjectNavFarthest) {
                        nObjectNavFarthest = nTile;
                    }
                }
                break;
            case 3: // Slide
                // Ensure that the destination tile is greater than the current tile
                while (nTile <= tempTile) {
                    nRow = getDieMovement();
                    nColumn = getDieMovement();

                    if (nRow % 2 == 0) {
                        tempTile = ((nRow * 10) - (nColumn - 1));
                    } else {
                        tempTile = (((nRow - 1) * 10) + nColumn);
                    }
                }

                if (nTile > tempTile) {
                    cyan();
                    printf("[System] ");
                    reset();
                    printf("A slide is on tile %d. Nay! Please slide down to tile %d (row: %d, col: %d).\n", nTile, tempTile, nRow, nColumn);
                    
                    nTile = tempTile;
                    nSlides++;
                }
                break;
            case 4: // U-Turn
                // The user will go back to the previous position
                int nPrevRow, nPrevColumn;
                
                if (nPosition % 10 == 0) { // If the player is on the even row
                    if (nPosition == 0) {
                        nPrevRow = 0;
                        nPrevColumn = 0;
                    } else {
                        nPrevRow = nPosition / 10;
                        nPrevColumn = (nPosition % 10) + 1;
                    }
                } else {
                    nPrevRow = (nPosition / 10) + 1;
                    nPrevColumn = nPosition % 10;
                }

                cyan();
                printf("[System] ");
                reset();
                printf("A U-turn is on tile %d. Sorry! Please go back to tile %d (row: %d, col: %d).\n", nTile, nPosition, nPrevRow, nPrevColumn);

                nTile = nPosition;
                break;
            default:
                cyan();
                printf("[System] ");
                reset();
                printf("There is no doggo, ladder, slide nor U-turn on tile %d. Switching Players!\n", nTile);
                break;
        }
    }

    nPosition = nTile;
    *currPlayerPos = nTile;
    *currPlayerDoggos = nDoggos;
    *currPlayerLadders = nLadders;
    *currPlayerSlides = nSlides;
    *currPlayerUTurns = nUTurns;
    *currPlayerObjectNavFarthest = nObjectNavFarthest;

    if (nPosition == 100) {
        *nWinningMove = nDiceObject;
    }

    
    return nPosition;
}

/**
 * @brief This function handles the gameplay for two players.
 * @param nNumPlayers is the number of players.
 * @param nPlayerSequence is the sequence of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @return void
 */
void twoPlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos) {
    // Variables
    int nP1Doggos = 0, nP2Doggos = 0;
    int nP1Ladders = 0, nP2Ladders = 0;
    int nP1Slides = 0, nP2Slides = 0;
    int nP1UTurns = 0, nP2UTurns = 0;
    int nP1ObjectNavFarthest = 0, nP2ObjectNavFarthest = 0;
    int nWinningMove = 0;

    int nTurns = 0;
    int nCurrentPlayer = 0;
    int nNewSequence = *nPlayerSequence;
    char cResponse = ' ';

    // Start the game
    do {
        nCurrentPlayer = getCurrentPlayer(nNewSequence);
        printf("\n\n");
        displayCurrentPlayer(nCurrentPlayer);

        switch (nCurrentPlayer) {
            case 1:
                *nPosition = getGameplay(nCurrentPlayer, nP1Pos, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);

                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
            case 2:
                *nPosition = getGameplay(nCurrentPlayer, nP2Pos, &nP2Doggos, &nP2Ladders, &nP2Slides, &nP2UTurns, &nP2ObjectNavFarthest, &nWinningMove);
                
                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }
                
                break;
        }

        nTurns++;
        nNewSequence = getUpdatedPlayerSequence(nNewSequence);
    } while (*nPosition != 100 && nTurns != nNumPlayers);

    nTurns = 0;

    printf("\n\n");
    printf("Would you like to display the board?");
    blue();
    printf("[Y]es \t");
    red();
    printf("[N]o \n");
    reset();
    printf("Answer\t: ");
    scanf(" %c", &cResponse);

    // Validate input for rankings display
    while (cResponse != 'Y' && cResponse != 'y' && cResponse != 'N' && cResponse != 'n') {
        red();
        printf("\nSystem\t: \"Invalid input! Try again\"\n");
        reset();
        printf("Answer\t: ");
        scanf(" %c", &cResponse);
    }

    // Display the board
    if (cResponse == 'Y' || cResponse == 'y') {
        printf("\n");
        cyan();
        printf("%45s", "[B O A R D]");
        printf("\n\n");
        reset();
        displayBoard(*nP1Pos, *nP2Pos, 0, 0, 0);
    }

    printf("\n\n");
    printf("Would you like to display the rankings?");
    blue();
    printf("[Y]es \t");
    red();
    printf("[N]o \n");
    reset();
    printf("Answer\t: ");
    scanf(" %c", &cResponse);

    // Validate input for rankings display
    while (cResponse != 'Y' && cResponse != 'y' && cResponse != 'N' && cResponse != 'n') {
        red();
        printf("\nSystem\t: \"Invalid input! Try again\"\n");
        reset();
        printf("Answer\t: ");
        scanf(" %c", &cResponse);
    }

    // Display the rankings
    if (cResponse == 'Y' || cResponse == 'y') {
        printf("\n");
        cyan();
        printf("%48s", "[R A N K I N G S]");
        printf("\n\n");
        reset();
        displayRankings(nNumPlayers, nP1Pos, nP2Pos, 0, 0, 0);
    }

    // End of the round
    printf("\n\n");
    cyan();
    printf("[System] Press any key to continue...");
    reset();
    // getchar(); // Consume newline from previous input
    // getchar(); // Wait for Enter key press
    scanf(" %c", &cResponse);
}


/**
 * @brief This function handles the gameplay for five players.
 * @param nNumPlayers is the number of players.
 * @param nPlayerSequence is the sequence of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 */
void fivePlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    // Variables
    int nP1Doggos = 0, nP2Doggos = 0, nP3Doggos = 0, nP4Doggos = 0, nP5Doggos = 0;
    int nP1Ladders = 0, nP2Ladders = 0, nP3Ladders = 0, nP4Ladders = 0, nP5Ladders = 0;
    int nP1Slides = 0, nP2Slides = 0, nP3Slides = 0, nP4Slides = 0, nP5Slides = 0;
    int nP1UTurns = 0, nP2UTurns = 0, nP3UTurns = 0, nP4UTurns = 0, nP5UTurns = 0;
    int nP1ObjectNavFarthest = 0, nP2ObjectNavFarthest = 0, nP3ObjectNavFarthest = 0, nP4ObjectNavFarthest = 0, nP5ObjectNavFarthest = 0;
    int nWinningMove = 0;

    int nTurns = 0;
    int nCurrentPlayer = 0;
    int nNewSequence = *nPlayerSequence;
    char cResponse = ' ';

    // Start the game
    do {
        nCurrentPlayer = getCurrentPlayer(nNewSequence);
        printf("\n\n");
        displayCurrentPlayer(nCurrentPlayer);

        switch (nCurrentPlayer) {
            case 1:
                *nPosition = getGameplay(nCurrentPlayer, nP1Pos, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);

                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
            case 2:
                *nPosition = getGameplay(nCurrentPlayer, nP2Pos, &nP2Doggos, &nP2Ladders, &nP2Slides, &nP2UTurns, &nP2ObjectNavFarthest, &nWinningMove);
                
                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
            case 3:
                *nPosition = getGameplay(nCurrentPlayer, nP3Pos, &nP3Doggos, &nP3Ladders, &nP3Slides, &nP3UTurns, &nP3ObjectNavFarthest, &nWinningMove);
                
                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
            case 4:
                *nPosition = getGameplay(nCurrentPlayer, nP4Pos, &nP4Doggos, &nP4Ladders, &nP4Slides, &nP4UTurns, &nP4ObjectNavFarthest, &nWinningMove);
                
                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
            case 5:
                *nPosition = getGameplay(nCurrentPlayer, nP5Pos, &nP5Doggos, &nP5Ladders, &nP5Slides, &nP5UTurns, &nP5ObjectNavFarthest, &nWinningMove);
                
                if (*nPosition == 100) {
                    displayWinnerSummary(nCurrentPlayer, &nP1Doggos, &nP1Ladders, &nP1Slides, &nP1UTurns, &nP1ObjectNavFarthest, &nWinningMove);
                }

                break;
        }

        nTurns++;
        nNewSequence = getUpdatedPlayerSequence(nNewSequence);
    } while (*nPosition != 100 && nTurns != nNumPlayers);

    nTurns = 0;

    printf("\n\n");
    printf("Would you like to display the board?");
    blue();
    printf("[Y]es \t");
    red();
    printf("[N]o \n");
    reset();
    printf("Answer\t: ");
    scanf(" %c", &cResponse);

    // Validate input for rankings display
    while (cResponse != 'Y' && cResponse != 'y' && cResponse != 'N' && cResponse != 'n') {
        red();
        printf("\nSystem\t: \"Invalid input! Try again\"\n");
        reset();
        printf("Answer\t: ");
        scanf(" %c", &cResponse);
    }

    // Display the board
    if (cResponse == 'Y' || cResponse == 'y') {
        printf("\n");
        cyan();
        printf("%45s", "[B O A R D]");
        printf("\n\n");
        reset();
        displayBoard(*nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
    }

    printf("\n\n");
    printf("Would you like to display the rankings?");
    blue();
    printf("[Y]es \t");
    red();
    printf("[N]o \n");
    reset();
    printf("Answer\t: ");
    scanf(" %c", &cResponse);

    // Validate input for rankings display
    while (cResponse != 'Y' && cResponse != 'y' && cResponse != 'N' && cResponse != 'n') {
        red();
        printf("\nSystem\t: \"Invalid input! Try again\"\n");
        reset();
        printf("Answer\t: ");
        scanf(" %c", &cResponse);
    }

    // Display the rankings
    if (cResponse == 'Y' || cResponse == 'y') {
        printf("\n");
        cyan();
        printf("%48s", "[R A N K I N G S]");
        printf("\n\n");
        reset();
        displayRankings(nNumPlayers, nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);
    }

    printf("\n\n");
    cyan();
    printf("Press any key to continue...");
    reset();
    getchar(); // Consume newline from previous input
    getchar(); // Wait for Enter key press
}


/**
 * @brief This function starts the game.
 * @param nNumPlayers is the number of players.
 * @param nPlayerSequence is the sequence of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void startGame(int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    // Variables
    int nRound = 0, nPosition = 0;
    int nCurrentPlayer = 0, nNewSequence = 0;

    // Start the game
    do {
        system("cls");
        nRound++;
        displayDivider();
        displayGameTitle();
        displayDivider();
        printf("\n");

        cyan();
        printf("%46s", "[R O U N D - ");
        printf("%d]", nRound);
        reset();
        printf("\n\n");

        //displayBoard(*nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
        //printf("\n\n");

        cyan();
        printf("\n[System]\n");
        reset();
        displaySequenceOfPlayers(*nPlayerSequence, nCurrentPlayer);
        displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, 0, 0, 0);
        
        switch (nNumPlayers) {
            case 2:
                twoPlayersGamePlay(&nPosition, nNumPlayers, nPlayerSequence, nP1Pos, nP2Pos);
                break;
            case 5:
                fivePlayersGamePlay(&nPosition, nNumPlayers, nPlayerSequence, nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);
                break;
        }


    } while (nPosition != 100);
}

/**
 * @brief This function resets the game.
 * @param nNumPlayers is the number of players.
 * @param nPlayerSequence is the sequence of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void resetGame(int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    *nPlayerSequence = 0;
    *nP1Pos = 0;
    *nP2Pos = 0;
    *nP3Pos = 0;
    *nP4Pos = 0;
    *nP5Pos = 0;
}
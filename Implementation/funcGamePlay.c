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
    int nP1Doggos = 0, nP2Doggos = 0, nP3Doggos = 0, nP4Doggos = 0, nP5Doggos = 0;
    int nP1Ladders = 0, nP2Ladders = 0, nP3Ladders = 0, nP4Ladders = 0, nP5Ladders = 0;
    int nP1Slides = 0, nP2Slides = 0, nP3Slides = 0, nP4Slides = 0, nP5Slides = 0;
    int nP1UTurns = 0, nP2UTurns = 0, nP3UTurns = 0, nP4UTurns = 0, nP5UTurns = 0;
    int nP1ObjectNavFarthest = 0, nP2ObjectNavFarthest = 0, nP3ObjectNavFarthest = 0, nP4ObjectNavFarthest = 0, nP5ObjectNavFarthest = 0;
    int nWinningMove = 0;

    int nRound = 0, nTurns = 0, nPosition = 0;
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

        displayBoard(*nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
        printf("\n\n");

        switch (nNumPlayers) {
            case 2:
                displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, 0, 0, 0);
                displaySequenceOfPlayers(*nPlayerSequence);

                nCurrentPlayer = getCurrentPlayer(*nPlayerSequence);
                displayCurrentPlayer(nCurrentPlayer);

                char cResponse = ' ';
                printf("Answer\t: ");
                scanf(" %c", &cResponse);
                nPosition++;
                *nP1Pos = 5 +  *nP1Pos;
                *nP2Pos = 10 + *nP2Pos;
                    

                *nPlayerSequence = getUpdatedPlayerSequence(*nPlayerSequence);



                break;
        }


    } while (nPosition != 5);
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
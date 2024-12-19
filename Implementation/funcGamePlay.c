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
        
        printf("\n");
        displaySequenceOfPlayers(*nPlayerSequence, nCurrentPlayer);
        displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, 0, 0, 0);
        displayCurrentPlayer(nCurrentPlayer);

        
        printf("Answer\t: ");
        scanf(" %c", &cResponse);

        switch (nCurrentPlayer) {
            case 1:
                //nP1Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, 0, 0, 0);
                *nP1Pos = *nP1Pos + 10;
                *nPosition = *nPosition + 1;
                break;
            case 2:
                //nP2Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, 0, 0, 0);
                *nP2Pos = *nP2Pos + 5;
                *nPosition = *nPosition + 1;
                break;
        }

        nTurns++;
        nNewSequence = getUpdatedPlayerSequence(nNewSequence);
    } while (*nPosition != 5 && nTurns != nNumPlayers);

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
    printf("Press any key to continue...");
    reset();
    getchar(); // Consume newline from previous input
    getchar(); // Wait for Enter key press
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
        
        printf("\n");
        displaySequenceOfPlayers(*nPlayerSequence, nCurrentPlayer);
        displayAllPlayersCurrentPosition(nNumPlayers, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
        displayCurrentPlayer(nCurrentPlayer);

        
        printf("Answer\t: ");
        scanf(" %c", &cResponse);

        switch (nCurrentPlayer) {
            case 1:
                //nP1Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
                *nPosition = *nPosition + 1;
                break;
            case 2:
                //nP2Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
                *nPosition = *nPosition + 1;
                break;
            case 3:
                //nP3Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
                *nPosition = *nPosition + 1;
                break;
            case 4:
                //nP4Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
                *nPosition = *nPosition + 1;
                break;
            case 5:
                //nP5Pos = getGameplay(nCurrentPlayer, nPosition, *nP1Pos, *nP2Pos, *nP3Pos, *nP4Pos, *nP5Pos);
                *nPosition = *nPosition + 1;
                break;
        }
        nTurns++;
        nNewSequence = getUpdatedPlayerSequence(nNewSequence);
    } while (*nPosition != 5 && nTurns != nNumPlayers);

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

        switch (nNumPlayers) {
            case 2:
                twoPlayersGamePlay(&nPosition, nNumPlayers, nPlayerSequence, nP1Pos, nP2Pos);
                break;
            case 5:
                fivePlayersGamePlay(&nPosition, nNumPlayers, nPlayerSequence, nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);
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
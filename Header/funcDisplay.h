/**
 * @file funcDisplay.h
 * @brief This file contains the function declarations for the functions that display the game's needed information.
 */

void displayDivider();      // Game's divider
void displayGameTitle();    // Game's title
void displayEndGame();      // End of the game

void displayBoard(int nP1Pos, int nP2Pos, int nP3Pos, int nP4Pos, int nP5Pos);  // Game's board
void displaySequenceOfPlayers(int nSequence, int nCurrentPlayer);  // Sequence of players

void displayP1Position(int nP1Pos);  // Player 1's position
void displayP2Position(int nP2Pos);  // Player 2's position
void displayP3Position(int nP3Pos);  // Player 3's position
void displayP4Position(int nP4Pos);  // Player 4's position
void displayP5Position(int nP5Pos);  // Player 5's position
void displayAllPlayersCurrentPosition(int nNumPlayers, int nP1Pos, int nP2Pos, int nP3Pos, int nP4Pos, int nP5Pos);  // Players' current position


void displayInitializeStatus(int nNumPlayers, int nSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);  // Game's initialization status

void displayCurrentPlayer(int nCurrentPlayer);  // Current player

void displayRankings(int nNumPlayers, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);  // Rankings of the players
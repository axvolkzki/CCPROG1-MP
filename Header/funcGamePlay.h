/**
 * @file funcGamePlay.h
 * @brief This file contains the function declarations for the functions that handle the game's gameplay.
 */

#include <stdbool.h>

bool isValidResponse(char x);
bool wantPlayAgain();


void twoPlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos);

void fivePlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);

void startGame(int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);

void resetGame(int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);
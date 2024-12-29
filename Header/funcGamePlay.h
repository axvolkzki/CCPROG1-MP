/**
 * @file funcGamePlay.h
 * @brief This file contains the function declarations for the functions that handle the game's gameplay.
 */

#include <stdbool.h>

bool isValidResponse(char x);
bool wantPlayAgain();

int getGameplay(int nCurrentPlayer, int* currPlayerPos, int* currPlayerDoggos, int* currPlayerLadders, int* currPlayerSlides, int* currPlayerUTurns, int* currPlayerObjectNavFarthest, int* nWinningMove);
void endRound(int nNumPlayers, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);

void twoPlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos);
void threePlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos);
void fourPlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos);
void fivePlayersGamePlay(int* nPosition, int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);

void startGame(int nNumPlayerss, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);
void resetGame(int nNumPlayers, int* nPlayerSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos);

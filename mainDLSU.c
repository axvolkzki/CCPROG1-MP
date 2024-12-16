/**
 * Description: This program is titled "Doggos, Ladders, Slides, and U-Turns" (DLSU). 
 * It is a machine project created as a course requirement for Logic Formulation and Introductory Programming (CCPROG1). 
 * The game is a modern Command-Line Interface (CLI) turn-based offline board game inspired by the traditional Snakes and Ladders board game. 
 * Like Snakes and Ladders, it features a board with a 10 x 10 grid of tiles numbered from 1 to 100. 
 * 
 * Players participate in a Spartan race with an exciting twist in this board game. 
 * Instead of the traditional snakes and ladders, the game features dogs, ladders, slides, and U-turns that can appear randomly on different tiles. 
 * These elements can assist or hinder players navigating the board to reach tile 100. 
 * The first player to land on this tile is declared the winner.
 * 
 * 
 * Programmed by: Amelia Joyce Abenoja      S12A
 * Last modified: 16 December 2024
 * Version: 2.0
 * 
 * Acknowledgements:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "Header/funcHelper.h"
#include "Header/funcDisplay.h"
#include "Header/funcGamePlay.h"

int main() {
    // Variables
    int nP1Pos = 0, nP2Pos = 0, nP3Pos = 0, nP4Pos = 0, nP5Pos = 0;


    system("cls");  // Clear screen

    displayDivider();
    displayHeader();
    displayDivider();

    printf("\n\n");
    displayBoard(nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);
    printf("\n\n");

    displayAllPlayersCurrentPosition(nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);

    
    return 0;
}
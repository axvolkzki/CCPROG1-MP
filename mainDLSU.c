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
 * Last modified: 29 December 2024
 * Version: 2.0
 * 
 * Acknowledgements:
 * 1. Can someone explain how to append an element to an array in C programming? (n.d.). Stack Overflow. https://stackoverflow.com/questions/26208788/can-someone-explain-how-to-append-an-element-to-an-array-in-c-programming
 * 2. C library function to perform sort. (n.d.). Stack Overflow. https://stackoverflow.com/questions/1787996/c-library-function-to-perform-sort
 * 3. Conditional (ternary) operator - JavaScript | MDN. (2024, December 19). MDN Web Docs. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Conditional_operator
 * 4. How to remove duplicate output in C program? (n.d.). Stack Overflow. https://stackoverflow.com/questions/27972225/how-to-remove-duplicate-output-in-c-program
 * 5. Malagi, S. S. (2021, August 2). Introduction to C/C++ Documentation with Doxygen. https://www.linkedin.com/pulse/doxygen-santosh-s-malagi#:~:text=A%20function's%20documentation%20must%20include%20the%20following,*%20@see%20to%20refer%20to%20related%20functions.
 * 6. Penguin, U. (2022, September 12). Adding color to your output from C. The Urban Penguin. https://www.theurbanpenguin.com/4184-2/
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Header/funcHelper.h"
#include "Header/funcDisplay.h"
#include "Header/funcInitialize.h"
#include "Header/funcGamePlay.h"

int main() {
    // Variables
    int nNumPlayers = 0;
    int nP1Pos = 0, nP2Pos = 0, nP3Pos = 0, nP4Pos = 0, nP5Pos = 0;
    int nPlayerSequence = 0;
    bool playAgain = true;

    // For random number generation
    time_t t;
	srand(time(&t));

    // Main loop
    do {
        resetGame(nNumPlayers, &nPlayerSequence, &nP1Pos, &nP2Pos, &nP3Pos, &nP4Pos, &nP5Pos);
        system("cls");  // Clear screen

        displayDivider();
        displayGameTitle();
        displayDivider();

        printf("\n\n");
        displayBoard(nP1Pos, nP2Pos, nP3Pos, nP4Pos, nP5Pos);
        printf("\n\n");

        // Ask user how many players
        printf("Enter the number of players (2-5): ");
        scanf("%d", &nNumPlayers);

        // Validate number of players
        if(isValidPlayers(nNumPlayers)) {
            // Initialize the game
            initializeGame(nNumPlayers, &nPlayerSequence, &nP1Pos, &nP2Pos, &nP3Pos, &nP4Pos, &nP5Pos);

            // Clear screen
            system("cls");  

            // Display the initialization status
            displayInitializeStatus(nNumPlayers, nPlayerSequence, &nP1Pos, &nP2Pos, &nP3Pos, &nP4Pos, &nP5Pos);

            // Start the game
            startGame(nNumPlayers, &nPlayerSequence, &nP1Pos, &nP2Pos, &nP3Pos, &nP4Pos, &nP5Pos);
        } else {
            printf("Invalid number of players! Please try again.\n");
        }

        // Ask user if they want to play again
        playAgain = wantPlayAgain();
    } while (playAgain); 

    system("cls");  // Clear screen
    displayEndGame();  // Display end of game

    
    return 0;
}
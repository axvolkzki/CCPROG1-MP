/**
 * @file funcHelper.h
 * @brief This file contains the function declarations for the functions that help in the game's implementation.
 */

void red();         // Red color    - Player 1
void yellow();      // Yellow color - Player 2
void green();       // Green color  - Player 3
void blue();        // Blue color   - Player 4
void purple();      // Purple color - Player 5
void cyan();        // Cyan color   - Winner Player
void reset();       // Reset color

int getDieSequence(int nNumberOfPlayers);  // Sequence of players

int getDieMovement();  // Die generator for movement of players in the board

int getUpdatedPlayerSequence(int nSequence);  // New Turn of Player

int getCurrentPlayer(int nSequence);  // Current player
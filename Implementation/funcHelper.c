/**
 * @file funcHelper.c
 * @brief This file contains the function definitions for the functions that help in the game's implementation.
 */

#include <stdio.h>

/**
 * @brief This function changes the text color to red.
 * @param void
 * @return void
 */
void red() {
  printf("\033[1;31m");
}

/**
 * @brief This function changes the text color to yellow.
 * @param void
 * @return void
 */
void yellow() {
  printf("\033[1;33m");
}

/**
 * @brief This function changes the text color to green.
 * @param void
 * @return void
 */
void green() {
  printf("\033[1;32m");
}

/**
 * @brief This function changes the text color to blue.
 * @param void
 * @return void
 */
void blue() {
  printf("\033[1;34m");
}

/**
 * @brief This function changes the text color to purple.
 * @param void
 * @return void
 */
void purple() {
  printf("\033[1;35m");
}


/**
 * @brief This function changes the text color to cyan.
 * @param void
 * @return void
 */
void cyan() {
  printf("\033[1;36m");
}


/**
 * @brief This function resets the text color to default.
 * @param void
 * @return void
 */
void reset() {
  printf("\033[0m");
}
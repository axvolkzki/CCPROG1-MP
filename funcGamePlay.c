#include "funcGamePlay.h"       // User-defined Header File

#include <stdbool.h>

/* Function Definitions */

/*	Header
    This function displays the title of the game
	everytime a game starts.
*/
void displayHeader( ) {
    printf("\n");
	printf("==============================================================================");
	printf("\n\t\tWelcome to Doggos, Ladders, Slides and U-turns!\n");
	printf("==============================================================================\n");
}

/*	
    <Short description>

	Precondition:   <none>
    @param          <void>
    @return         boolean
*/
bool wantPlayAgain( ) {
    char cResponse = ' ';
    bool isValidRes = false;

    // Ask user to play again
    printf("\n\nWould you like to play again?");
    printf("\nEnter: \n\t[Y] - Yes\n\t[N] - No");
    printf("\nAnswer: \t");
    scanf(" %c", &cResponse);

    isValidRes = isValidResponse(cResponse);

    while(!isValidRes) {
        printf("Status: \t\"Invalid input! Try again!\"\n");
        printf("\nAnswer: ");
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

/*	
    <Short description>
    
	Precondition:   <none>
    @param          <void>
    @return         boolean
*/
bool isValidResponse(char x) {
    if (x == 'Y' || x == 'y' || x == 'N' || x == 'n')
        return true;
    else
        return false;
}
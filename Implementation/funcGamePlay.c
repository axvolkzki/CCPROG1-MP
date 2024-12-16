// Preprocessor directives>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "../Header/funcHelper.h"



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


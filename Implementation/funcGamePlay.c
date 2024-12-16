// Preprocessor directives>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>



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


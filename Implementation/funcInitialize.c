/**
 * @file funcInitializeGame.c
 * @brief This file contains the function definitions for the functions that initialize the game.
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdbool.h>

#include "../Header/funcHelper.h"

// Function Definitions
/**
 * @brief This function checks if the number of players is valid.
 * @param nNumberOfPlayers is the number of players.
 * @return int
 */
bool isValidPlayers(int nNumberOfPlayers) {
    return (nNumberOfPlayers >= 2 && nNumberOfPlayers <= 5);
}

/**
 * @brief This function gets the sequence of players.
 * @param nNumberOfPlayers is the number of players.
 * @return int is the sequence of players.
 */
int getSequenceOfPlayers(int nNumPlayers) {
    int nSeqTurn1, nSeqTurn2, nSeqTurn3, nSeqTurn4, nSeqTurn5;
		
	nSeqTurn1 = getDieSequence(nNumPlayers);
    nSeqTurn2 = getDieSequence(nNumPlayers);
    nSeqTurn3 = getDieSequence(nNumPlayers);	
    nSeqTurn4 = getDieSequence(nNumPlayers);	
    nSeqTurn5 = getDieSequence(nNumPlayers);

		
    if(nNumPlayers == 1)
    {
    	return nSeqTurn1;
    }
    else if(nNumPlayers == 2)
    {
    	if(nSeqTurn2 != nSeqTurn1)
        {
        	return(nSeqTurn1*10) + nSeqTurn2;
        }
        else 
        {
        	while(nSeqTurn2 == nSeqTurn1)
        	{
        		nSeqTurn2 = getDieSequence(nNumPlayers);
        		if(nSeqTurn2 != nSeqTurn1)
        		{
        			return (nSeqTurn1*10)+nSeqTurn2;
        		}
			}
		}
	}
    else if(nNumPlayers == 3)
    {
		if(nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1 && nSeqTurn2 != nSeqTurn1)
       	{
       		return (nSeqTurn1*100)+(nSeqTurn2*10)+nSeqTurn3;
		}
		else
		{
			while(nSeqTurn3 == nSeqTurn2 || nSeqTurn3 == nSeqTurn1 
					|| nSeqTurn2 == nSeqTurn1)	
			{
				nSeqTurn3 = getDieSequence(nNumPlayers);
				nSeqTurn2 = getDieSequence(nNumPlayers);
				if(nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
					 && nSeqTurn2 != nSeqTurn1)
				{
					return (nSeqTurn1*100)+(nSeqTurn2*10)+nSeqTurn3;
				}
			}
		}
	}
    else if(nNumPlayers == 4)
    {
		if(nSeqTurn4 != nSeqTurn3 && nSeqTurn4 != nSeqTurn2 && nSeqTurn4 != nSeqTurn1 
			&& nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
			&& nSeqTurn2 != nSeqTurn1 )
			{
				return (nSeqTurn1*1000)+(nSeqTurn2*100)+(nSeqTurn3*10)+nSeqTurn4;
			}
		else 
		{
			while(nSeqTurn4 == nSeqTurn3 || nSeqTurn4 == nSeqTurn2 || nSeqTurn4 == nSeqTurn1 
					|| nSeqTurn3 == nSeqTurn2 || nSeqTurn3 == nSeqTurn1
					|| nSeqTurn2 == nSeqTurn1)
			{
				nSeqTurn4 = getDieSequence(nNumPlayers);
				nSeqTurn3 = getDieSequence(nNumPlayers);
				nSeqTurn2 = getDieSequence(nNumPlayers);
			if(nSeqTurn4 != nSeqTurn3 && nSeqTurn4 != nSeqTurn2 && nSeqTurn4 != nSeqTurn1 
				&& nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
				&& nSeqTurn2 != nSeqTurn1)
				{
					return (nSeqTurn1*1000)+(nSeqTurn2*100)+(nSeqTurn3*10)+nSeqTurn4;
				}	
			}
		}
	}
	else if (nNumPlayers == 5 )
	{
		if(nSeqTurn5 != nSeqTurn4 && nSeqTurn5 != nSeqTurn3 && nSeqTurn5 != nSeqTurn2 && nSeqTurn5 != nSeqTurn1 
			&& nSeqTurn4 != nSeqTurn3 && nSeqTurn4 != nSeqTurn2 && nSeqTurn4 != nSeqTurn1 
			&& nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
			&& nSeqTurn2 != nSeqTurn1)
		{
			return (nSeqTurn1*10000)+(nSeqTurn2*1000)+(nSeqTurn3*100)+(nSeqTurn4*10)+nSeqTurn5;
		}
		else 
		{
			while(nSeqTurn5 == nSeqTurn4 || nSeqTurn5 == nSeqTurn3 || nSeqTurn5 == nSeqTurn2 || nSeqTurn5 == nSeqTurn1 
					|| nSeqTurn4 == nSeqTurn3 || nSeqTurn4 == nSeqTurn2 || nSeqTurn4 == nSeqTurn1 
					|| nSeqTurn3 == nSeqTurn2 || nSeqTurn3 == nSeqTurn1
					|| nSeqTurn2 == nSeqTurn1)
			{
				nSeqTurn5 = getDieSequence(nNumPlayers);
				nSeqTurn4 = getDieSequence(nNumPlayers);
				nSeqTurn3 = getDieSequence(nNumPlayers);
				nSeqTurn2 = getDieSequence(nNumPlayers);
        		if(nSeqTurn5 != nSeqTurn4 && nSeqTurn5 != nSeqTurn3 && nSeqTurn5 != nSeqTurn2 && nSeqTurn5 != nSeqTurn1 
					&& nSeqTurn4 != nSeqTurn3 && nSeqTurn4 != nSeqTurn2 && nSeqTurn4 != nSeqTurn1 
					&& nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
					&& nSeqTurn2 != nSeqTurn1)
				{
					return (nSeqTurn1*10000)+(nSeqTurn2*1000)+(nSeqTurn3*100)+(nSeqTurn4*10)+nSeqTurn5;	
				}
			}
		}
	}
}

/**
 * @brief This function initializes the game.
 * @param nNumPlayers is the number of players.
 * @param nSequence is the sequence of players.
 * @param nP1Pos is the position of Player 1.
 * @param nP2Pos is the position of Player 2.
 * @param nP3Pos is the position of Player 3.
 * @param nP4Pos is the position of Player 4.
 * @param nP5Pos is the position of Player 5.
 * @return void
 */
void initializeGame(int nNumPlayers, int* nSequence, int* nP1Pos, int* nP2Pos, int* nP3Pos, int* nP4Pos, int* nP5Pos) {
    // Initialize positions
    *nP1Pos = 0;
    *nP2Pos = 0;
    *nP3Pos = 0;
    *nP4Pos = 0;
    *nP5Pos = 0;

	// Get sequence of players
    int Seq = getSequenceOfPlayers(nNumPlayers);
    *nSequence = Seq;
}
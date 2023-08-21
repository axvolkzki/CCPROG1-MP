/******************************************************************
This is to certify that this project is my own work, based on my 
personal efforts in studying and applying the concepts learned. 
I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and 
debugged by my own efforts. I further certify that I have not copied 
in part or whole or otherwise plagiarized the work of other students 
and/or persons. 

<Amelia Joyce L. Abenoja>, DLSU ID# <12108107>
******************************************************************/

/*
    Description: This program is called Doggos, Ladders, Slides, and 
	U-turns (DLSU), a modern turn-based offline board game inspired 
	by the traditional Snake and Ladders board game. Like the Snake 
	and Ladders, it has a board with a grid of 10 x 10 tiles from 1 
	to 100. This board game is a simple race game with a plot twist; 
	instead of only snakes and ladders, the objects are doggos, ladders, 
	slides, and u-turns and may randomly appear on a tile that can help 
	or hinder the player in navigating the board to achieve their goal,
	to reach the tile 100. The first player to reach the goal is the 
	winner.
	
	 
    Programmed by: ABENOJA, Amelia Joyce L. | S12A
    Last modified: 05 February 2022
    Version: 9
    [Acknowledgements: <list of sites or borrowed libraries and sources>]
*/


//<Preprocessor directives>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//<Constant definitions>
#define D10 10
#define BOARD 10



//<Function Prototypes>
void displayHeader( ); 														//#1 - Header
int displayBoard( int nPosition ); 											//#2 - Board
int isValidPlayers( int nNumberOfPlayers ); 								//#3 - Valid Players (Checker for the validity of number of players)
int getDieSequence( int nNumberOfPlayers ); 								//#4 - Random digit generator for sequence of players
int getSequenceOfPlayers( int nNumberOfPlayers ); 							//#5 - Sequence of turns between entered number of players
int getCurrentPlayer( int nSequence ); 										//#6 - Current player
int getNewSequence( int nSequence ); 										//#7 - New Turn of Player
int getDieMovement( ); 														//#8 - Die generator for movement of players in the board
int getGameplay(int nCurrentPlayer, int nPosition, int tempPosP1, 
				int tempPosP2, int tempPosP3, int tempPosP4, int tempPosP5);//#9 - Gameplay



//<Main function>
int main ( void )
{
	//List of Input
	int	nNumberOfPlayers;
	
	//List of variables
	char ch, cResponseSequence, cResponsePlayAgain, cResponseRepeat, cDisplayRank;
    int	nSequence, nCurrentPlayer, nNewSequence; //For changing of turns between players
	int nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5; //For storing the current position of a player
	int nRound, nTurn; //To change rounds
	
	//For random D10 generator
	time_t t;
	srand(time(&t));
	
	//Outputs:
	//Gameplay
	do
	{
		//setting the variables to 0
		nRound=0;
		nPosition=0;
		tempPosP1=0, tempPosP2=0, tempPosP3=0, tempPosP4=0, tempPosP5=0;
		
		
		displayHeader( );
		displayBoard( nPosition );
		
		printf("\n\t\t\tLET THE GAME BEGINS!!!");
		printf("\nEnter number of players: "); //Ask for input
    	scanf("%d", &nNumberOfPlayers);
		
		if(!isValidPlayers( nNumberOfPlayers )) //if not valid number of players
    	{
    		printf(">Invalid number of players!");
		}
		else //for valid
		{
			nSequence = getSequenceOfPlayers( nNumberOfPlayers );
			printf("Determining the sequence of turns between %d players...[%d]\t(Enter any key to continue...)", nNumberOfPlayers, nSequence );
			scanf("%c", &cResponseSequence);
			
			do //gameplay starts
			{
				nRound++;
				printf("\n\n==========ROUND %d==========", nRound);
				printf("\n>Sequence: %d", nSequence);
				nTurn=0;
				
				switch(nNumberOfPlayers) //gameplay depending on number of players
				{
					case 2:	printf("\n>2 players will be playing...");
							do
							{
								nCurrentPlayer	= getCurrentPlayer( nSequence );
								nNewSequence	= getNewSequence( nSequence );
								nSequence		= nNewSequence; //Changing the old sequence to new one
								printf("\n\n--->>NEW TURN<<---"); //divider betwwen turns of players
								switch(nCurrentPlayer)
								{
									case 1: tempPosP1 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP1);
											nPosition = tempPosP1;
											break;
									case 2:	tempPosP2 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP2);
											nPosition = tempPosP2;
											break;	
								}
							
								nTurn++;
								
								if(nTurn == nNumberOfPlayers)
								{
									printf("\n\n=====Would you like to display the ranking? (Y/N)=====");
									scanf("%c", &cDisplayRank);
								
									switch(cDisplayRank)
									{
										case 'Y':	
										case 'y':	printf("\n RANK \tPLAYER");
													if(tempPosP1 > tempPosP2)
													{
														printf("\n 1 \tP1");
														printf("\n 2 \tP2");
													}
													else
													{
														printf("\n 1 \tP2");
														printf("\n 2 \tP1");
													}
													break;
									}
								}
								
								printf("\n\nEnter any key to change player!");
								scanf("%c%c", &ch, &cResponseRepeat);
							}while(nTurn!=nNumberOfPlayers && nPosition!=100 && ch && cResponseRepeat);
							break;
					case 3: printf("\n>3 players will be playing...");
							do
							{
								nCurrentPlayer	= getCurrentPlayer( nSequence );
								nNewSequence	= getNewSequence( nSequence );
								nSequence		= nNewSequence; //Changing the old sequence to new one
								printf("\n\n--->>NEW TURN<<---"); //divider betwwen turns of players
								switch(nCurrentPlayer)
								{
									case 1: tempPosP1 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP1);
											nPosition = tempPosP1;
											break;
									case 2:	tempPosP2 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP2);
											nPosition = tempPosP2;
											break;
									case 3:	tempPosP3 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP3);
											nPosition = tempPosP3;
											break;	
								}
								nTurn++;
								printf("\n\nEnter any key to change player!");
								scanf("%c%c", &ch, &cResponseRepeat);
							}while(nTurn!=nNumberOfPlayers && nPosition!=100 && ch && cResponseRepeat);
							break;
					case 4: printf("\n>4 players will be playing...");
							do
							{
								nCurrentPlayer	= getCurrentPlayer( nSequence );
								nNewSequence	= getNewSequence( nSequence );
								nSequence		= nNewSequence; //Changing the old sequence to new one
								printf("\n\n--->>NEW TURN<<---"); //divider betwwen turns of players
								switch(nCurrentPlayer)
								{
									case 1: tempPosP1 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP1);
											nPosition = tempPosP1;
											break;
									case 2:	tempPosP2 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP2);
											nPosition = tempPosP2;
											break;
									case 3:	tempPosP3 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP3);
											nPosition = tempPosP3;
											break;
									case 4:	tempPosP4 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP4);
											nPosition = tempPosP4;
											break;	
								}
								nTurn++;
								printf("\n\nEnter any key to change player!");
								scanf("%c%c", &ch, &cResponseRepeat);
							}while(nTurn!=nNumberOfPlayers && nPosition!=100 && ch && cResponseRepeat);
							break;
					case 5: printf("\n>It's a full house! 5 players will be playing!");
							do
							{
								nCurrentPlayer	= getCurrentPlayer( nSequence );
								nNewSequence	= getNewSequence( nSequence );
								nSequence		= nNewSequence; //Changing the old sequence to new one
								printf("\n\n--->>NEW TURN<<---"); //divider betwwen turns of players
								switch(nCurrentPlayer)
								{
									case 1: tempPosP1 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP1);
											nPosition = tempPosP1;
											break;
									case 2:	tempPosP2 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP2);
											nPosition = tempPosP2;
											break;
									case 3:	tempPosP3 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP3);
											nPosition = tempPosP3;
											break;
									case 4:	tempPosP4 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP4);
											nPosition = tempPosP4;
											break;
									case 5:	tempPosP5 = getGameplay(nCurrentPlayer, nPosition, tempPosP1, tempPosP2, tempPosP3, tempPosP4, tempPosP5);
											printf("\nCurrent Position: [%d]", tempPosP5);
											nPosition = tempPosP5;
											break;	
								}
								nTurn++;
								printf("\n\nEnter any key to change player!");
								scanf("%c%c", &ch, &cResponseRepeat);
							}while(nTurn!=nNumberOfPlayers && nPosition!=100 && ch && cResponseRepeat);
							break;
				}
			}while(nPosition != 100);
		}
		
		//Ask the user to play again
		printf("\n\nWould you like to play again?");
		printf("\nEnter: \n\t[Y] - Yes\n\t[N] - No");
		printf("\nAnswer: ");
		scanf("%c%c", &ch, &cResponsePlayAgain);
	}while(cResponsePlayAgain=='Y' || cResponsePlayAgain=='y'||
	       ch=='Y' || ch=='y');
	
	//Displays after the game if cResponsePlayAgain != Y or != y
    printf("\n\nHope you enjoyed Doggos, Ladders, Slides and U-turns!\nThank you for playing! :)");
	
	
	
	return 0;
}






//<Function implementation>
//#1 - Header
/*	This function displays the title of the game
	everytime a game starts.
*/
void displayHeader( )
{
	printf("==============================================================================");
	printf( "\n\t\tWelcome to Doggos, Ladders, Slides and U-turns!\n" );
	printf("==============================================================================\n");
}


//#2 - Board
/*	This function displays a 10x10 board with values
	from 100 to 1 (decresing mannner).
	Precondition: Each digit is a non-negative number. 
	Rows are divided into, odd and evemn rows.
	Even rows display numbers from left to right
	while odd rows displays numbers from right to left.
	Precondition: all numbers are non-negative
	digit from 1 to 100.
    @param nPosition is the position of a player to be
    displayed in the board.
    @return the board of the game
*/
int displayBoard( int nPosition )
{
	int nRow1, nCol, nRow2;
	int nEven=100, nOdd=101;
	
	for(nRow1=BOARD; nRow1>=1; nRow1--) //all rows
	{
		for(nCol=1 ; nCol<=BOARD; nCol++) //all columns
		{
			if(nRow1%2==0) // for even rows
			{
				printf("  %d\t", nEven); //values: 100 to 1 in even rows
			}
			nEven--;
			nOdd--;
		}
		for(nRow2=nRow1 && nRow2==nCol; nRow2<nCol; nRow2++) // for odd rows
		{
			if(nRow1%2!=0) //for odd rows
			{
				printf("  %d\t", nOdd); //values: 101 to 1 in odd rows
				nOdd++;
			}
		}
		printf("\n");
		if(nRow1%2!=0) // for odd rows
		{
			nOdd-=10;
		}
	}
	
	printf("==============================================================================\n");
	return 0;
}


//#3 - Valid Players (Checker for the validity of number of players)
/*	This function checks for the validity of entered number
	of players in the program.
	Precondition: number of players are non-negative values
	that must be greater than or equal to 1 but 
	less than or equal to 5.
	@param nNumberOfPlayers is the number of players will be 
	playing in the game.
	@return the validity of number of players
*/
int isValidPlayers( int nNumberOfPlayers )
{
	return (nNumberOfPlayers>=2 && nNumberOfPlayers<=5);
}


//#4 - Random digit generator for sequence of players
/*	This function generates a one digit random number to be 
	used as sequence of players that will be playing in
	the game.
	Precondition: generated digit are non-negative values
	and within the range of entered number of players.
	@param nNUmberOfPlayers is the range of generated
	digit random digit starting from 1.
	@return the generated one random digit

*/
int getDieSequence( int nNumberOfPlayers )
{
	return ( int )rand()%nNumberOfPlayers+1;
}


//#5 - Sequence of turns between entered number of players
/*	This function gets the one random generated digit in 
	function getDieSequence( nNumberOfPlayers )
	for each nSequenceOfTurns and compare each random digit
	to have a unique set of numbers.
	Precondition: the set of unique generated numbers are 
	non-negative values and it depends on the entered
	number of players.
	@param nNumberOfPlayers is ther ranged of the new set
	of unique sequence of numbers.
	@return the new set of unique sequence of numbers
*/
int getSequenceOfPlayers( int nNumberOfPlayers )
{
	int nSeqTurn1, nSeqTurn2, nSeqTurn3, nSeqTurn4, nSeqTurn5;
		
	nSeqTurn1 = getDieSequence( nNumberOfPlayers );
    nSeqTurn2 = getDieSequence( nNumberOfPlayers );
    nSeqTurn3 = getDieSequence( nNumberOfPlayers );	
    nSeqTurn4 = getDieSequence( nNumberOfPlayers );	
    nSeqTurn5 = getDieSequence( nNumberOfPlayers );

		
    if(nNumberOfPlayers == 1)
    {
    	return nSeqTurn1;
    }
    else if(nNumberOfPlayers == 2)
    {
    	if(nSeqTurn2 != nSeqTurn1)
        {
        	return(nSeqTurn1*10) + nSeqTurn2;
        }
        else 
        {
        	while(nSeqTurn2 == nSeqTurn1)
        	{
        		nSeqTurn2 = getDieSequence( nNumberOfPlayers );
        		if(nSeqTurn2 != nSeqTurn1)
        		{
        			return (nSeqTurn1*10)+nSeqTurn2;
        		}
			}
		}
	}
    else if(nNumberOfPlayers == 3)
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
				nSeqTurn3 = getDieSequence( nNumberOfPlayers );
				nSeqTurn2 = getDieSequence( nNumberOfPlayers );
				if(nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
					 && nSeqTurn2 != nSeqTurn1)
				{
					return (nSeqTurn1*100)+(nSeqTurn2*10)+nSeqTurn3;
				}
			}
		}
	}
    else if(nNumberOfPlayers == 4)
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
				nSeqTurn4 = getDieSequence( nNumberOfPlayers );
				nSeqTurn3 = getDieSequence( nNumberOfPlayers );
				nSeqTurn2 = getDieSequence( nNumberOfPlayers );
			if(nSeqTurn4 != nSeqTurn3 && nSeqTurn4 != nSeqTurn2 && nSeqTurn4 != nSeqTurn1 
				&& nSeqTurn3 != nSeqTurn2 && nSeqTurn3 != nSeqTurn1
				&& nSeqTurn2 != nSeqTurn1)
				{
					return (nSeqTurn1*1000)+(nSeqTurn2*100)+(nSeqTurn3*10)+nSeqTurn4;
				}	
			}
		}
	}
	else if ( nNumberOfPlayers == 5 )
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
				nSeqTurn5 = getDieSequence( nNumberOfPlayers );
				nSeqTurn4 = getDieSequence( nNumberOfPlayers );
				nSeqTurn3 = getDieSequence( nNumberOfPlayers );
				nSeqTurn2 = getDieSequence( nNumberOfPlayers );
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
	
	return 0;
}


//#6 - Current Player
/*	This function computes for the first digit of the sequence
	as the current player of every turn.
	Precondition: all numbers are non-negative values from 
	1 to 5.
	@param nSequence is the sequence of turns between the players
	@return nFirstNum the first digit of the sequence and the current 
	player
*/
int getCurrentPlayer( int nSequence )
{
	int nFirstNum;
	
	while(nSequence>5)
	{  
  		nSequence	/= 10;
  		nFirstNum	= nSequence;
	}
	
	return nFirstNum;
}


//#7 - New Turn of Player
/*	This function replace the first digit of the sequence to the 
	last digit position.
	Precondition: all numbers are non-negative values from 
	1 to 5.
	@param nNumberOfPlayers sets the limit on how many times
	the function keep computing the new turns 
	@param nSequence is the sequence of turns of players that
	needs to be computed
	@return nNewSeq the new sequence of turns between players

*/
int getNewSequence( int nSequence )
{
	int nValue=0, count=0;
	int i, j;
	int nPowerOfTen=1;
	int nFirstDigit, nRemovedFirstDigit, nNewSeq;
	
	nValue=nSequence;
		
	for(i=1; nSequence>5; i++)
	{
        nSequence/=10;
        nFirstDigit=nSequence;
        count++;
    }
	
	for(j=1; j<=count; j++) 
	{
    	nPowerOfTen*=10;
	}

	nRemovedFirstDigit 	= nValue-(nFirstDigit*nPowerOfTen);
	nNewSeq				= (10*nRemovedFirstDigit)+nFirstDigit;

	return nNewSeq;	
}


//#8 - Die generator for movement of players in the board
/*	This function generates a random digit from a 10-sided
	die, also known as pentagonal trapezohedron, that serves
	as the movement of each player in the game.
	Precondition: the generated one random digit is a 
	non-negative value starting from 1 to 10.
	@return the generated one random digit
*/
int getDieMovement( )
{
    return ( int )rand()%D10+1;
}


//#9 - Gameplay
/*	This function generates the whole gameplay for a each player
	until a player reaches the tile 100 (goal) and declare 
	the player as winner.
	Precondition: all numbers are non-negative values from 
	0 to 1. The current position is keep on updating until 
	one player is a winner.
	@param nCurrentPlayer is the player who is currently playing
	@param nPosition is the current position of the player
	@param tempPosP1 is the temporary position of player 1 
			that keeps on updating
	@param tempPosP2 is the temporary position of player 2 
			that keeps on updating
	@param tempPosP3 is the temporary position of player 3 
			that keeps on updating
	@param tempPosP4 is the temporary position of player 4 
			that keeps on updating
	@param tempPosP5 is the temporary position of player 5 
			that keeps on updating
	@return nPosition is the new position of a player
*/
int getGameplay( int nCurrentPlayer, int nPosition, int tempPosP1, int tempPosP2, int tempPosP3, int tempPosP4, int tempPosP5)
{
	//Variables
	int nRow, nColumn, nTile, nDiceObject;
	char ch, cResponse;
	int *ptrRow, *ptrColumn; 			//Used in double-3
	int tempUTurn, *ptrCurrentPosition; //Used in U-Turn
	int tempRow; 						//Use for restriction in ladders and slides
	int tempPos; 						//Used in nRow==10, when players gets off the board
	int nCountDoggos=0, nCountLadders=0, nCountSlides=0, nCountUTurns=0; //Counter for objects
	
	//Assigning the position based on players
	switch(nCurrentPlayer) 
	{
		case 1: nPosition = tempPosP1; break;
		case 2: nPosition = tempPosP2; break;
		case 3: nPosition = tempPosP3; break;
		case 4: nPosition = tempPosP4; break;
		case 5: nPosition = tempPosP5; break;
	}
	
	
	
	//START OF THE GAME
	while(nPosition!=100)
	{
		//Assigning the variables
		ptrCurrentPosition	 = &nPosition;
		nRow				 = getDieMovement( );
		nColumn				 = getDieMovement( );
		ptrRow				 = &nRow;
		ptrColumn			 = &nColumn;
		
		
		//FOR TILE 0 TO 89		
		if(nPosition>=0 && nPosition<=89)
		{	
			//for U-Turn
			tempUTurn	= *ptrCurrentPosition;
			
			//Start
			printf("\n\nNow playing: Player %d", nCurrentPlayer);
			printf("\nCurrent Position: [%d] \t(Enter any key to roll a pair of D10)", nPosition);
			scanf("%c%c", &ch, &cResponse);		
			
			printf(">Generating a pair of D10 dice...(%d) (%d)", nRow, nColumn);
		
			
			if(nRow==10 && nColumn==1) //For instant winner 
			{
				nTile		= 100;
				nPosition	= nTile;
				printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
				printf("\nYou reached the goal! YOU WIN!");
				printf("\nDoggo appeared %d times.", nCountDoggos);
				printf("\nYou climbed ladders %d times.", nCountLadders);
				printf("\nYou rode slides %d times.", nCountSlides);
				printf("\nYou took U-turns %d time.", nCountUTurns);
				/*The ladder took you to the farthest tile.
				The winning move was when you followed the doggo.*/
				printf("\nCONGRATULATIONS!");
				return nPosition; //Will not proceed to objects & back to main
			}
			if(nRow==5 && nColumn==5) //Can't move
			{
				printf("\nYou rolled %d and %d. You missed your turn, don't move!", nRow, nColumn);
				return nPosition; //Will not proceed to objects & go back to main
			}
			if(nPosition==0 && nRow==3 && nColumn==3) //Non-existing tile
			{
				printf("\nYou rolled %d and %d. Non-existing tile, don't move!", nRow, nColumn);
				return nPosition; //Will not proceed to objects & go back to main
			}
			if(nPosition!=0 && nRow==3 && nColumn==3)
			{
				nRow	= *ptrRow + 3;
				nColumn	= *ptrColumn;
				if(nRow==8 || nRow==9 || nRow==10)
				{
					nTile		= 99;
					nPosition	= nTile;
					nRow 		= 10;
					nColumn		= 2;
					printf("\nYou rolled 3 and 3. Please proceed to tile %d (row: %d, col: %d).", nTile, nRow, nColumn);
				}
				if(nRow%2!=0)
				{
					nTile		= ((nRow*10) - (10-*ptrColumn));
					nPosition	= nTile;
					printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d). \t(Enter any key to continue)", nRow, nColumn, nTile, nRow, nColumn);
				}
				else if(nRow%2==0)
				{
					nTile		= (( (nRow*10) +1 ) - *ptrColumn);
					nPosition	= nTile;
					printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d). \t(Enter any key to continue)", nRow, nColumn, nTile, nRow, nColumn);
				}
			} 
			if(!(nPosition==0 && nRow==3 && nColumn==3) && !(nRow==5 && nColumn==5))
			{
				if(nRow%2 != 0)
				{
					nTile		= ((nRow*10) - (10-nColumn));
					nPosition	= nTile;
				}
				else if(nRow%2 == 0)    
				{
					nTile		= (( (nRow*10)+ 1) - nColumn);
					nPosition	= nTile;
				}
				printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
			}
			
			//For objects
			if(nPosition>=1 && nPosition<=89)
			{
				printf("\n>Determining if there's an object in the tile... \t(Enter any key to roll a die)");
				scanf("%c%c",&ch, &cResponse);
			
				if(nPosition>=1 && nPosition<=89) //If player is between tile 1 to 89
				{
					nDiceObject	= getDieMovement( );
					nRow 		= getDieMovement( );
					nColumn		= getDieMovement( );
					
					if(nPosition>=1 && nPosition<=10 && nDiceObject==3) //To make sure no slides will appear on nRow==1;
					{
						while(nDiceObject == 3)
						{
							nDiceObject = getDieMovement( );
						}
					}
					
					//Identifying the object on a tile
					switch(nDiceObject)
					{
						case 1: printf(">A Doggo is on tile %d! Roll a pair of D10 dice and follow the doggo. \t(Enter any key to continue)", nTile);
								scanf("%c", &cResponse); 
								nCountDoggos++;// Counter for Doggos
								
								if(cResponse)
								{
									if(nRow%2 != 0) 
									{
										nTile		= ((nRow*10) - (10-nColumn));
										nPosition	= nTile;
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
									else if(nRow%2==0)
									{
										nTile		= (( (nRow*10) +1) - nColumn);
										nPosition	= nTile;
									
										if(nPosition==100)
										{
											printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
											printf("\n\nYou reached the goal! YOU WIN!");
											printf("\nDoggo appeared %d times.", nCountDoggos);
											printf("\nYou climbed ladders %d times.", nCountLadders);
											printf("\nYou rode slides %d times.", nCountSlides);
											printf("\nYou took U-turns %d time.", nCountUTurns);
											/*The ladder took you to the farthest tile.
											printf("\nThe winning move was when you followed the doggo.");*/
											printf("\nCONGRATULATIONS!");
										}
										else
										{
											printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										}
									}		
								}
								break;
						case 2: printf(">A Ladder is on tile %d! Roll a pair of D10 dice and climb in the ladder. \t(Enter any key to continue)", nTile);
								scanf("%c", &cResponse); //scanf("%c%c", &ch, &cResponse);
								nCountLadders++;// Counter for Ladders
								
								if(cResponse)
								{
									tempRow = getDieMovement( );
									
									if(tempRow < *ptrRow)
									{
										while(tempRow < *ptrRow)
										{
											tempRow = getDieMovement( );
										}	
									}
									else if(tempRow > *ptrRow)
									{
										nRow = tempRow;
										if(nRow%2 != 0)
										{
											nTile		= ((nRow*10) - (10-nColumn));
											nPosition	= nTile;
											printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										}
										else if(nRow%2 == 0)
										{
											nTile		= (( (nRow*10) + 1) - nColumn);
											nPosition	= nTile;
											
											if(nPosition==100)
											{
												printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
												printf("\n\nYou reached the goal! YOU WIN!");
												printf("\nDoggo appeared %d times.", nCountDoggos);
												printf("\nYou climbed ladders %d times.", nCountLadders);
												printf("\nYou rode slides %d times.", nCountSlides);
												printf("\nYou took U-turns %d time.", nCountUTurns);
												/*The ladder took you to the farthest tile.
												printf("\nThe winning move was when you followed the doggo.");*/
												printf("\nCONGRATULATIONS!");
											}
											else
											{
												printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
											}
										}
									}
								}//if(cResponse)
								break;
						case 3:	printf(">A Slide is on tile %d! Roll a pair of D10 dice and slide in the ladder. \t(Enter any key to continue)", nTile);
								scanf("%c", &cResponse); //scanf("%c%c", &ch, &cResponse);
								nCountSlides++; //Counter for slides
								
								if(cResponse)
								{
									tempRow = getDieMovement( );
									
									if(tempRow > *ptrRow)
									{
										while(tempRow > *ptrRow)
										{
											tempRow = getDieMovement( );
										}	
									}
									else if(tempRow < *ptrRow)
									{
										nRow = tempRow;
										if(nRow%2 != 0) 
										{
											nTile		= ((nRow*10) - (10-nColumn));
											nPosition	= nTile;
											printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										}
										else if(nRow%2 == 0)
										{
											nTile		= (( (nRow*10) + 1) - nColumn);
											nPosition	= nTile;
											
											printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										}
									}	
								}//if(cResponse)
								break;
						case 4: printf(">A U-turn is on tile %d! Sorry, please go back to your previous position.", nTile);
								nPosition = tempUTurn;
								nCountUTurns++;
								break;
						default:printf(">There is no doggo, ladder, slide nor U-turn on tile %d.", nTile);
								break;
					}//end of switch
				}//(nPosition>=1 && nPosition<=89)
			}//if(nPosition>=1 && nPosition<=89)
		
			//for objects in tiles 90 to 99
			if(cResponse && nPosition>=90 && nPosition<=99)
			{
				nDiceObject	= getDieMovement( );
				nRow 		= getDieMovement( );
				nColumn		= getDieMovement( );
				
				while(nDiceObject == 2) //To make ssure no ladder will appear on nRow==10
				{
					nDiceObject	= getDieMovement( );
				}
				
				//Identifying the object on a tile
				switch(nDiceObject) 
				{
					case 1: printf(">A Doggo is on tile %d! Roll a pair of D10 dice and follow the doggo. \t(Enter any key to continue)", nTile);
							scanf("%c", &cResponse); 
							nCountDoggos++;// Counter for Doggos
								
							if(cResponse)
							{
								if(nRow%2 != 0) 
								{
									nTile		= ((nRow*10) - (10-nColumn));
									nPosition	= nTile;
									printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
								}
								else if(nRow%2==0)
								{
									nTile		= (( (nRow*10) +1) - nColumn);
									nPosition	= nTile;
									
									if(nPosition==100)
									{
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										printf("\n\nYou reached the goal! YOU WIN!");
										printf("\nDoggo appeared %d times.", nCountDoggos);
										printf("\nYou climbed ladders %d times.", nCountLadders);
										printf("\nYou rode slides %d times.", nCountSlides);
										printf("\nYou took U-turns %d time.", nCountUTurns);
										/*The ladder took you to the farthest tile.
										printf("\nThe winning move was when you followed the doggo.");*/
										printf("\nCONGRATULATIONS!");
									}
									else
									{
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
								}		
							}
							break;
					case 3:	printf(">A Slide is on tile %d! Roll a pair of D10 dice and slide in the ladder. \t(Enter any key to continue)", nTile);
							scanf("%c", &cResponse); 
							nCountSlides++; //Counter for slides
								
							if(cResponse)
							{
								tempRow = getDieMovement( );
									
								if(tempRow > *ptrRow)
								{
									while(tempRow > *ptrRow)
									{
										tempRow = getDieMovement( );
									}	
								}
								else if(tempRow < *ptrRow)
								{
									nRow = tempRow;
									if(nRow%2 != 0) 
									{
										nTile		= ((nRow*10) - (10-nColumn));
										nPosition	= nTile;
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
									else if(nRow%2 == 0)
									{
										nTile		= (( (nRow*10) + 1) - nColumn);
										nPosition	= nTile;
											
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
								}	
							}//if(cResponse)
							break;
					case 4: printf(">A U-turn is on tile %d! Sorry, please go back to your previous position.", nTile);
							nPosition = tempUTurn;
							nCountUTurns++;
							break;
					default:printf("\n>There is no doggo, ladder, slide nor U-turn on tile %d.", nTile);
							break;
				}//end of switch
			}//if(cResponse && nPosition>=90 && nPosition<=99)
			return nPosition;
		}//if(nPosition>=0 && nPosition<=89)
		
		
		//for 90 to 100
		if(nPosition>=90 && nPosition<=99)
		{
			//for U-Turn
			tempUTurn = *ptrCurrentPosition;
			
			//Start
			printf("\n\nNow playing: Player %d", nCurrentPlayer);
			printf("\nCurrent Position: [%d] \t(Enter any key to roll a die)", nPosition);
			scanf("%c", &cResponse);		
			
			printf("\n>Generating a die of D10 dice... (%d)", nColumn);
			
			//for movement in row 10
			if(nRow==5 && nColumn==5) //Can't move
			{
				printf("\nYou rolled %d and %d. You missed your turn, don't move!", nRow, nColumn);
				return nPosition; //Will not proceed to objects & go back to main
			}
			if(nRow==3 && nColumn==3)
			{
				nTile		= 99;
				nPosition	= nTile;
				nRow 		= 10;
				nColumn		= 2;
				printf("\nYou rolled 3 and 3. Please proceed to tile %d (row: %d, col: %d).", nTile, nRow, nColumn);
			} 
			if(!(nRow==3 && nColumn==3) && !(nRow==5 && nColumn==5))
			{
				nTile = (nPosition + nColumn);
				if(nTile == 100)
				{
					nTile		= 100;
					nPosition	= nTile;
					printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
					printf("\nYou reached the goal! YOU WIN!");
					printf("\nDoggo appeared %d times.", nCountDoggos);
					printf("\nYou climbed ladders %d times.", nCountLadders);
					printf("\nYou rode slides %d times.", nCountSlides);
					printf("\nYou took U-turns %d time.", nCountUTurns);
					/*The ladder took you to the farthest tile.
					The winning move was when you followed the doggo.*/
					printf("\nCONGRATULATIONS!");
					return nPosition; //Will not proceed to objects & back to main
				}
				if(nTile >= 101)
				{
					tempPos		= 100 - nTile;
					nPosition	= 100 + tempPos;
					printf("\nYou rolled %d. Please proceed to tile %d. ", nColumn, nTile);	
				}
				if(nTile>=90 && nTile<=99)
				{
					nPosition = nTile;
					printf("\nYou rolled %d. Please proceed to tile %d. ", nColumn, nTile);
				}
			}
			
			//for objects in tile 90 to 99
			if(nPosition>=90 && nPosition<=99)
			{
				printf("\n>Determining if there's an object in the tile... \t(Enter any key to roll a die)");
				scanf("%c", &cResponse);
				
				nDiceObject	= getDieMovement( );
				nRow 		= getDieMovement( );
				nColumn		= getDieMovement( );
				
				while(nDiceObject == 2) //To make ssure no ladder will appear on nRow==10
				{
					nDiceObject	= getDieMovement( );
				}
				
				//Identifying the object on a tile
				switch(nDiceObject) 
				{
					case 1: printf("\n>A Doggo is on tile %d! Roll a pair of D10 dice and follow the doggo. \t(Enter any key to continue)", nTile);
							scanf("%c", &cResponse);
							nCountDoggos++;// Counter for Doggos
								
							if(cResponse)
							{
								if(nRow%2 != 0) 
								{
									nTile		= ((nRow*10) - (10-nColumn));
									nPosition	= nTile;
									printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
								}
								else if(nRow%2==0)
								{
									nTile		= (( (nRow*10) +1) - nColumn);
									nPosition	= nTile;
									
									if(nPosition==100)
									{
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
										printf("\n\nYou reached the goal! YOU WIN!");
										printf("\nDoggo appeared %d times.", nCountDoggos);
										printf("\nYou climbed ladders %d times.", nCountLadders);
										printf("\nYou rode slides %d times.", nCountSlides);
										printf("\nYou took U-turns %d time.", nCountUTurns);
										/*The ladder took you to the farthest tile.
										printf("\nThe winning move was when you followed the doggo.");*/
										printf("\nCONGRATULATIONS!");
									}
									else
									{
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
								}		
							}
							break;
					case 3:	printf("\n>A Slide is on tile %d! Roll a pair of D10 dice and slide in the ladder. \t(Enter any key to continue)", nTile);
							scanf("%c", &cResponse); 
							nCountSlides++; //Counter for slides
								
							if(cResponse)
							{
								tempRow = getDieMovement( );
									
								if(tempRow > *ptrRow)
								{
									while(tempRow > *ptrRow)
									{
										tempRow = getDieMovement( );
									}	
								}
								else if(tempRow < *ptrRow)
								{
									nRow = tempRow;
									if(nRow%2 != 0) 
									{
										nTile		= ((nRow*10) - (10-nColumn));
										nPosition	= nTile;
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
									else if(nRow%2 == 0)
									{
										nTile		= (( (nRow*10) + 1) - nColumn);
										nPosition	= nTile;
											
										printf(">You rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
									}
								}	
							}//if(cResponse)
							break;
					case 4: printf("\n>A U-turn is on tile %d! Sorry, please go back to your previous position.", nTile);
							nPosition = tempUTurn;
							nCountUTurns++;
							break;
					default:printf("\n>There is no doggo, ladder, slide nor U-turn on tile %d.", nTile);
							break;
				}//end of switch
				return nPosition;
			}//(nPosition>=90 && nPosition<=99)
		}//if(nPosition>=90 && nPosition<=99)
		
		//for tile 100
		if(nPosition == 100)
		{
			nTile		= 100;
			nPosition	= nTile;
			printf("\nYou rolled %d and %d. Please proceed to tile %d (row: %d, col: %d).", nRow, nColumn, nTile, nRow, nColumn);
			printf("\nYou reached the goal! YOU WIN!");
			printf("\nDoggo appeared %d times.", nCountDoggos);
			printf("\nYou climbed ladders %d times.", nCountLadders);
			printf("\nYou rode slides %d times.", nCountSlides);
			printf("\nYou took U-turns %d time.", nCountUTurns);
			/*The ladder took you to the farthest tile.
			The winning move was when you followed the doggo.*/
			printf("\nCONGRATULATIONS!");
			return nPosition; //Will not proceed to objects & back to main
		}//(nPosition == 100)
	}//while(nPosition!=100)
	
	return 0;
}

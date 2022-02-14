#include <stdio.h>
#include <conio.h>
#define MIN 3 	//board minimum
#define MAX 9 	//board maximum
#define PLMIN 2	//number of players minimun
#define PLMAX 9	//number of players maximun

//Dynamic TIC-TAC-TOE
//CODED by: RAUL COMEROS JR.
//INSTRUCTOR: Sir John Lehmar Cabrillos

//STATUS: DONE!
/*
	1. Allows more than 2 players
	2. Can implement basic game rules
	3. Can verify invalid inputs
	4. Allows more than 3x3 standard playing field
		4.1 Playable up to 36x36 in standard 20 font-size cmd (fullscreen). [Please change the "MAX" definition]
*/

int field[MAX][MAX]; 
int inputPlayer (char, int);
int checkPosition (int, int, int);
int checkWinner (int, int);
int checkDraw (int);
void drawGrid (int);
void fieldInit (char, int);
void init (int);
void winDisp (int);
void drawGuide (int);
char convertSym (char);

main ()
{
	char game = 'Y';
	int playerSym[MAX];
	
	
	
	while (game=='Y' || game =='y')
	{
		int count = 0;
		int check = 0;
		int N = 8;
		int P = 0;
		int oneSym = 0;
		int twoSym = 0;
		int turn = 0;
		int choice = 0;
		int result = 0;	
		drawGrid(N);
		printf ("%c%c%c%c%c%c%c%c%c%c%c  PRESS ANY KEY TO CONTINUE %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );	
		getch();
		
		system ("@cls");
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  Input Size of Field (Integer Only) %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		while (!(N>=MIN && N<=MAX))
		{
			fflush(stdin); //to fix any char input
			printf ("\nInput size of the field(%d-%d): ", MIN, MAX);
			scanf ("%d", &N);
			if (N<MIN || N>MAX)
			{
				printf ("\tInvalid input. Please try again.");
			}
		}
		
		while (!(P>=PLMIN && P<=PLMAX))
		{
			fflush(stdin); //to fix any char input
			printf ("\nInput players (%d-%d): ", PLMIN, PLMAX);
			scanf ("%d", &P);
			if (N<MIN || N>MAX)
			{
				printf ("\tInvalid input. Please try again.");
			}
			
			if (P==1)
			{
				printf ("\tAre you that lonely to play alone? Please get a friend.");
			}
		}
		
		init (N);
		
		for (count=0; count<P; count++)
		{
			playerSym[count] = 32;
		}
		
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  Input Player Symbols (Letter Only) %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		for (count=0, check=0; count<P; count++, check=0)
		{
			while (check!=1)
			{
				fflush(stdin);
				printf ("\nInput symbol for player %d: ", count+1);
				scanf ("%c", &playerSym[count]);
				if (count==0)
				{
						check = inputPlayer (playerSym[count], 0);
				}
				else if (count!=0)
				{
					check = inputPlayer (playerSym[count], playerSym[count-1]);
				}
			}
		}
		
		for (count=0; count<P; count++)		//will convert lowercase symbol to uppercase
		{
			playerSym [count] = convertSym(playerSym[count]);
		}
		
		drawGuide (N);
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  PLAYING TIME! %c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		while (1) 	//loops until 1 player wins and/or all cells are occupied
		{
			printf ("\n\n");
			drawGrid (N);
			
			turn++;
			printf ("ROUND %d\n", turn);
			
			for (count=0; count<P; count++, result=0)
			{
				while (result!=1)
				{
					printf ("Player %d turn (1-%d): ", count+1, N*N);
					fflush(stdin);
					scanf ("%d", &choice);
					result = checkPosition (choice, playerSym[count], N);
				}
				if (checkDraw (N)==1)
				{
					break;
				}
				else if (checkWinner(playerSym[count], N)==1)
				{
						break;
				}
					
				printf ("\n\n");
				drawGrid (N);
			}
			
			if (checkDraw (N)==1)
			{
				break;
			}
			else if (checkWinner(playerSym[count], N)==1)
			{
				break;
			}		
		}
		for (count=0; count<P; count++)
			{
				if (checkWinner(playerSym[count], N)==1)
				{
					drawGrid (N);
					winDisp (count);
					break;
				}
				else if (checkDraw (N)==1)
				{
					drawGrid (N);
					printf ("\n\n%c%c%c%c%c DRAW! %c%c%c%c%c", 219, 219, 178, 177, 176,  176, 177, 178, 219, 219);
					break;
				}
			}
		
		printf ("\n\nDo you still want to play? (If yes press Y): ");
		fflush(stdin);
		scanf ("%c", &game);
		if (game!='Y' && game!='y') 	//to terminate the loop if the user inputs any letter other than 'Y' / 'y'
		{
			break;
		}
	}
	system ("cls");
	printf ("\n\n\tTHANK YOU FOR PLAYING!!!\n\tCODED by RAUL COMEROS JR.\n");
	getch();
}


void init (int N)	//initialization of cells (32 = space)
{
	int count, count1 = 0;
	
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			field[count][count1] = 32;
		}
	}
	
}

int inputPlayer (char symbol, int playerSym)  //verification of player symbols
{
	int value = 0;
	value = symbol;
	
	if (symbol==playerSym)
	{
		printf ("\tSymbol already taken. Please try again.\n");
		return 0;
	}
	else if ((value>=65 && value<=90) || (value>=97 && value<=122))
	{
		return 1;
	}	
	printf ("\tInvalid symbol! Please try again.");
	return 0;
	
}


char convertSym (char symbol) //convert lowercase to uppercase letters
{
	int value = 0;
	char result;
	value = symbol;

	if (value>=97 && value<=122)
	{
		return value-32;
	}
	else if (value>=65 && value<=90)
	{
		return symbol;
	}
}


void drawGrid (int N)	//function for the adisplay of playing field 
{
	int count = 0;
	int count1 = 0;
	
	printf ("   ");
	for (count1=0; count1<N; count1++)
		{
			printf ("%4d", count1+1);
		}
		printf ("\n ");     
	
	for (count=0; count<N; count++)
	{
		printf ("%3d ", count+1);
			for (count1=0; count1<N; count1++)
			{
				if (count1==(N-1))
				{
					printf (" %c", field[count][count1]);
				}
				else if (count1!=N)
				{
					printf (" %c %c", field[count][count1], 186);
				}              
				else if (count1==N)
				{
					printf ("%c", field[count][count1]);
				}
				
			}
			printf ("\n     ");
			for (count1=0; count1<N-1; count1++)
			{
				if (count!=N-1)
				{
					printf ("%c%c%c%c",205, 205, 205, 206);
				}
				
				if (count1==(N-2) && count!=(N-1))
				{
					printf ("%c%c%c", 205, 205, 205);
				}
			}
			printf ("\n ");
	}
}

int checkDraw (int N)	//yeilding draw if all empty cells are occupied
{
	int count, count1 = 0;
	int filled = 0;
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			if (field[count][count1] != 32)
			{
				filled++;
			}
		}
	}
	
	if (filled==(N*N))
	{
		return 1;
	}
	else if (filled!=(N*N))
	{
		return 0;
	}
}



int checkPosition (int choice, int symbol, int N)	//checks if chosen cell is empty/occupied
{
	int count, count1 = 0;
	int step = 0;
	
	if (choice>(N*N))
	{
		printf ("\tEntered position is over the maximum (%d)! Please try again.\n", N*N);
		return 0;
	}
	

	for (count=0, step=0; count<(N*N); count++)
	{
		for (count1=0; count1<N; count1++)
		{
			step++;
			if (step==choice)
			{
				if (field[count][count1] == 32)
				{
					field[count][count1] = symbol;
					return 1;
				}
				else if (field[count][count1] != 32)
				{
					printf ("\tChosen position already taken! Please try again.\n");
					return 0;
				}	
			} 
		}
	}
}

int checkWinner (int symbol, int N)		//checks if the last turn yields a winner
{
	int c, r = 0;
	int vertical = 0;
	int horizontal = 0;
	int diagDown = 0;
	int diagUp = 0;
	
	//vertical
	for (c=0; c<N; c++, vertical=0)
	{
		for (r=0; r<N; r++)
		{
			if (field[c][r] == symbol)
			{
				vertical++;
			}
		}
		
		if (vertical==N)
		{
			return 1;
		}
	}
	
	//horizontal
	for (r=0; r<N; r++, horizontal=0)
	{
		for (c=0; c<N; c++)
		{
			if (field[c][r] == symbol)
			{
				horizontal++;
			}
		}
		
		if (horizontal==N)
		{
			return 1;
		}
	}
	
	//diagDown loop
	for (c=0; c<N; c++)
	{
		if (field[c][c] == symbol)
		{
			diagDown++;
		}
	
	}
	
	if (diagDown==N)
		{
			return 1;
		}
		
		
	//diagUp loop
	for (c=(N-1), r=0; r<N; c--, r++)
	{
		if (field[c][r] == symbol)
		{
			diagUp++;
		}
	}
	
	if (diagUp==N)
		{
			return 1;
		}		
		return  0;
}


void winDisp (int player)		//display the player number of the winner
{
	int count = 0;
	for (count=0; count<10; count++)
	{
		printf ("%c", 205);
	}
	
	printf ("%c%c%c%c%c PLAYER %d WINNER! %c%c%c%c%c", 219, 219, 178, 177, 176, player+1, 176, 177, 178, 219, 219);
	
	for (count=0; count<10; count++)
	{
		printf ("%c", 205);
	}
}


void drawGuide (int N)		//displays the guide for proper positioning
{
	int count, count1 = 0;
	int step = 0;
	
	printf ("\n%c%c%c%c%c%c%c%c%c%c%c  BOARD POSITION GUIDE  %c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
	printf ("   ");
	for (count=0, step=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++, step++)
		{
			printf ("%3d ", step+1);
		}
		printf ("\n\n   ");
	}
	printf ("\nPress any key to continue.");
	getch ();
	
}

//Made with <3
//Thank you sir!!!~

#include <stdio.h>
#include <conio.h>
#define MIN 3
#define MAX 9

//Dynamic TIC-TAC-TOE
//CODED by: RAUL COMEROS JR.

//OK! CHANGE THE CONSTANT FOR FIELD ARRAY INTO INTEGER-BASED
//OK!LEFT: TRANSFER checkWinner and checkPosition from GridTEst.c file
//TIME SLEPT 1:19AM

//EST TIME DONE: 9: 30PM
//OK! ErrorMSG for checkPosition
//OK! While loop for next game
//OK! Clearscreen function for every game-iterate

int field[MAX][MAX];
int inputPlayer (char, int);
int checkPosition (int, int, int);
int checkWinner (int, int);
int checkDraw (int);
void drawGrid (int);
void fieldInit (char, int);
void init (int);
void winDisp (int);
char convertSym (char);

main ()
{
	char game = 'Y';
	
	while (game=='Y' || game =='y')
	{
		
		int count = 0;
		int check = 0;
		int N = 0;
		int oneSym = 0;
		int twoSym = 0;
		int turn = 0;
		int choice = 0;
		int result = 0;
		char game = 'Y';	
		
		printf ("%c%c%c%c%c%c%c%c%c%c%c  PRESS ANY KEY TO CONTINUE %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );	
		getch();
		
		system ("@cls");
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  Input Size of Field (Integer Only) %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		while (!(N>=MIN && N<=MAX))
		{
			fflush(stdin); //to fix any char input
			printf ("\nInput size of the field(3-9): ");
			scanf ("%d", &N);
			if (N<MIN || N>MAX)
			{
				printf ("\tInvalid input. Please try again.");
			}
		}
		
		init (N);
		
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  Input Player Symbols (Letter Only) %c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		while (check!=1)
		{
			fflush(stdin);
			printf ("\nInput symbol for player 1: ");
			scanf ("%c", &oneSym);
			check = inputPlayer (oneSym, 0);
		}
	//	oneSym = convertSym(oneSym);
		check = 0;
		
		while (check!=1)
		{
			fflush(stdin);
			printf ("Input symbol for player 2: ");
			scanf ("%c", &twoSym);
			check = inputPlayer (twoSym, oneSym);
		}
		oneSym = convertSym(oneSym);
		twoSym = convertSym(twoSym);
		
		printf ("\n%c%c%c%c%c%c%c%c%c%c%c  PLAYING TIME! %c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 );
		
		
		while (1)
		{
			printf ("\n\n");
			drawGrid (N);
			
			turn = 1;	
			while (result!=1)
			{
				printf ("Player %d turn (1-%d): ", turn, N*N);
				fflush(stdin);
				scanf ("%d", &choice);
				result = checkPosition (choice, oneSym, N);
				/*
				if (result!=1)
				{
					printf ("\tChosen position already taken! Please try again.\n");
				}*/
			}
			result = 0;
			
			if (checkWinner(oneSym, N)==1)
			{
				break;
			}
			if (checkDraw (N)==1)
			{
				break;
			}
			
			printf ("\n\n");
			drawGrid (N);
				
			turn = 2;
			
			while (result!=1)
			{
				printf ("Player %d turn (1-%d): ", turn, N*N);
				fflush(stdin);
				scanf ("%d", &choice);
				result = checkPosition (choice, twoSym, N);
				/*
				if (result!=1)
				{
					printf ("\tChosen position already taken! Please try again.\n");
				}*/
			}
			
			result = 0;
			
			
			if (checkWinner(twoSym, N)==1)
			{
				break;
			}
			
			if (checkDraw (N)==1)
			{
				break;
			}
			
		}
		
		
		if (checkWinner(oneSym, N)==1)
		{
			drawGrid (N);
			winDisp (1);
		}
		else if (checkWinner(twoSym, N)==1)
		{
			drawGrid (N);
			winDisp (2);
		}
		else if (checkDraw (N)==1)
			{
				printf ("\n\n%c%c%c%c%c DRAW! %c%c%c%c%c", 219, 219, 178, 177, 176,  176, 177, 178, 219, 219);
			}
		
		printf ("\n\nDo you still want to play? (If yes press Y): ");
		fflush(stdin);
		scanf ("%c", &game);
//		getch ();
	}
	printf ("\n\n%c%c%c%c%c THANKS FOR PLAYING! %c%c%c%c%c", 219, 219, 178, 177, 176,  176, 177, 178, 219, 219);
}

//initialization of cell (32 = space)
void init (int N)
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

int inputPlayer (char symbol, int oneSym) 
{
	int value = 0;
	value = symbol;
	
	if (symbol==oneSym)
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

//covert lowercase to uppercase
char convertSym (char symbol)
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


void drawGrid (int N)
{
	int count = 0;
	int count1 = 0;
	
	printf ("    ");
	for (count1=0; count1<N; count1++)
		{
			printf ("%d   ", count1+1);
		}
		printf ("\n ");     
	
	for (count=0; count<N; count++)
	{
		printf ("%d ", count+1);
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
			printf ("\n   ");
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

int checkDraw (int N)
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


//checks if chosen cell is empty
int checkPosition (int choice, int symbol, int N)
{
	int count, count1 = 0;
	int step = 0;
	
	if (choice>(N*N))
	{
		printf ("\tEntered position is over the maximum (%d)! Please try again.\n", N*N);
		return 0;
	}
	
	if (choice)
	
	
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

int checkWinner (int symbol, int N)
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

//display winner
void winDisp (int player)
{
	int count = 0;
	for (count=0; count<10; count++)
	{
		printf ("%c", 205);
	}
	
	printf ("%c%c%c%c%c PLAYER %d WINNER! %c%c%c%c%c", 219, 219, 178, 177, 176, player, 176, 177, 178, 219, 219);
	
	for (count=0; count<10; count++)
	{
		printf ("%c", 205);
	}
}




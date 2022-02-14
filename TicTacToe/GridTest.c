#include <stdio.h>
#include <conio.h>
#define MIN 3
#define MAX 9
//#define N 5


//left: trouble in placing proper symbol to chosen cell
int field[MAX][MAX];	
int checkWinner (int, int);

int checkPosition (int choice, int symbol, int N)
{
	int count, count1 = 0;
	int step = 0;
	
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
	//				printf ("\tChosen position already taken! Please try again.\n");
					return 2;
				}	
			} 
		}
	}
}



//return 1 win, 0 otherwise
int checkWinner (int symbol, int N)
{
	int c, r = 0;
	int vertical = 0;
	int horizontal = 0;
	int diagDown = 0;
	int diagUp = 0;
	
	
//	printf ("\n\tSymbol received: %d", symbol);
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
			printf ("\n\tWIN VERTICAL!");
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
			printf ("\n\tWIN HORIZONTAL!");
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
			printf ("\n\tWIN DIAGDOWN!");
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
			printf ("\n\tWIN DIAGUP!");
			return 1;
		}
		
		return  0;
	/*
	printf ("\n\tVerticals: %d", vertical);
	printf ("\n\tHori: %d", horizontal);
	printf ("\n\tDown: %d", diagDown);
	printf ("\n\tUp: %d", diagUp);
	printf ("\n\tN value: %d", N);
	*/

	
	
}




int verifyPlayer (int N)
{
	if ((checkWinner (1, N))==1)
	{
		printf ("Player 1 Winner!");
	}
	
	if ((checkWinner (2, N))==1)
	{
		printf ("Player 2 Winner!");
	}
}

main ()
{
	//for victory checking
	//the parameter is the symbol of A plyr then iterate for the other plyr
	
	
	//int checkWinner (int symbol)
	//return 1 if win, return 0 for none
	int N, c, r = 0;
	int count, count1 = 0;
	int oneSym = 65;
	int twoSym = 90;

	
	printf ("Enter N: ");
	scanf("%d", &N);
	
	printf ("\n");
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			field[count][count1] = 32;
		}
	}


/*
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			scanf ("%d", &field[count][count1]);
			checkWinner (1, N);
		}
	}
*/	
	int player = 0;
	int choice = 0;
	int turn = 1;
	int result = 0;
	
	while (1)
	{
		printf ("\n\n");
		//[insert] drawGrid
		for (count=0; count<N; count++)
			{
				for (count1=0; count1<N; count1++)
				{
					printf ("%c ", field[count][count1]);
				}
				printf ("\n");
			}
		turn = 1;	
		while (checkPosition (choice, oneSym, N)!=1)
		{
		
			printf ("Player %d turn (1-%d): ", turn, N*N);
			scanf ("%d", &choice);
		}
		
		if (checkWinner(oneSym, N)==1)
		{
			break;
		}
		
		//drawGrid
		printf ("\n\n");
		for (count=0; count<N; count++)
			{
				for (count1=0; count1<N; count1++)
				{
					printf ("%c ", field[count][count1]);
				}
				printf ("\n");
			}
			
		turn = 2;
		player = twoSym;
		
		while (checkPosition (choice, twoSym, N)!=1)
		{
			printf ("Player %d turn (1-%d): ", turn, N*N);
			scanf ("%d", &choice);
		}
		
		
		if (checkWinner(twoSym, N)==1)
		{
			break;
		}
		
	//	printf ("\n\n\t----- ROUND FINISHED! -----");
	//(checkWinner(oneSym, N)!=1) && (checkWinner(twoSym, N)!=1)	
	}
	
	printf ("\n\tSTATUS1: %d", checkWinner(oneSym, N));
	printf ("\n\tSTATUS2: %d", checkWinner(twoSym, N));
	
	printf ("\n\n------------- PRESS ANY KEY TO END --------------");
	getch ();
}

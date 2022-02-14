#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


/* TODO (#1#): Work on placement of pieces
               - currently on PIECES function for 
               definition of selected piece */


//create a fucntion of pieces' names

typedef struct player
{
	char name[20];
	int number;
	char color[5];
} PLAYER;


typedef struct position
{
	char row;
	int column;
} POSITION;


typedef struct piece
{
	char name[20];		
	PLAYER plOwner;		
	POSITION pcPos;		
} PIECE;


typedef struct tile
{
	int check;		//1 for unoccupied || 2 if occupied
	char color[6];	//either yellow or green color ---- [init'ed]
	PIECE pcType;	//updates every placement
	POSITION pcPos;	// [init'ed]
} TILE;


typedef struct playerInfo
{
	PLAYER plInfo;
	PIECE plPieces[16];
} PLINFO;

typedef struct chessboard
{
	TILE tile[8][8];
} CHESSBOARD;




CHESSBOARD boardInit (CHESSBOARD board)
{
	int count, count1;
	
	
	for (count=0; count<8; count++)
	{
		for (count1=0; count1<8; count1++)
		{
			//init for occupied
			board.tile[count][count1].check = 1;
			
			//init for position
			switch (count)
			{
				case 0:
					board.tile[count][count1].pcPos.row = 'A';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 1:
					board.tile[count][count1].pcPos.row = 'B';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 2:
					board.tile[count][count1].pcPos.row = 'C';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 3:
					board.tile[count][count1].pcPos.row = 'D';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 4:
					board.tile[count][count1].pcPos.row = 'E';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 5:
					board.tile[count][count1].pcPos.row = 'F';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 6:
					board.tile[count][count1].pcPos.row = 'G';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
				case 7:
					board.tile[count][count1].pcPos.row = 'H';
					board.tile[count][count1].pcPos.column = count1+1;
					break;
			}
			
			//init for color
			if (((board.tile[count][count1].pcPos.column)%2==0 && (board.tile[count][count1].pcPos.row)%2==0) || ((board.tile[count][count1].pcPos.column)%2!=0 && (board.tile[count][count1].pcPos.row)%2!=0))
			{
				strcpy (board.tile[count][count1].color, "yellow");
			}
			else if (((board.tile[count][count1].pcPos.column)%2==0 && (board.tile[count][count1].pcPos.row)%2!=0) || ((board.tile[count][count1].pcPos.column)%2!=0 && (board.tile[count][count1].pcPos.row)%2==0))
			{
				strcpy (board.tile[count][count1].color, "green");
			}
		}
	}
	return board;
}


void displayBoard (CHESSBOARD board)
{
	int count, count1;
	
	printf ("\nCHESSBOARD stats:\n");
	printf ("YELLOW AND GREEN test:\n");
	for (count=0; count<8; count++)
	{
		for (count1=0; count1<8; count1++)
		{
			//	printf ("%c ", board.tile.pcType.name);
			//	printf ("%s ", board.tile[count][count1].color);
//			puts (board.tile[count][count1].color);
			if ((board.tile[count][count1].color[0])=='y')
			{
				printf ("Y ");
			}
			else if (((board.tile[count][count1].color[0])=='g'))
			{
				printf ("G ");
			}
		}
		printf ("\n");
	}
	
	printf ("\nOccupied test:\n");
	for (count=0; count<8; count++)
	{
		for (count1=0; count1<8; count1++)
		{
			printf ("%d ", board.tile[count][count1].check);
		}
		printf ("\n");
	}
	
	printf ("\nPosition test:\n");
	for (count=0; count<8; count++)
	{
		for (count1=0; count1<8; count1++)
		{
			printf ("(%c, %d) ", board.tile[count][count1].pcPos.row, board.tile[count][count1].pcPos.column);
		}
		printf ("\n");
	}
}

PIECE selectPiece (char choice)
{
	switch (choice)
	{
		
	}
}

void displayPieces ()
{
	int count = 0;
	printf ("PIECES [case-sensitive]:\n");
	printf ("Pawns\t-\tP\nRooks\t-\tR\nKnights\t-\tK\nBishops\t-\tB\nQueen\t-\tQ\nKing\t-\tK\n");
}



main ()
{
	PLAYER player[2];
	CHESSBOARD board;
	int count, count1 = 0;
	int choice = 0;
	char row = 0;
	int column = 0;
	
	displayPieces();
	//initialization

	
	//Inputting player names
	player[0].number = 1;
	printf ("Enter Player %d name: ", player[0].number);
	gets(player[0].name);
	printf ("Enter color \n\t[1] WHITE or [2] BLACK: ");
	fflush (stdin);
	scanf ("%d", &choice);
	
	if (choice!=1 || choice!=2)
	{
		while (choice!=1 && choice!=2)
		{
			printf ("Invalid input. Please try again.");
			printf ("\n\nEnter color \n\t[1] WHITE or [2] BLACK: ");
			fflush (stdin);
			scanf ("%d", &choice);
		
		}
	}
	
	if (choice==1)
	{
		strcpy (player[0].color, "white");
		strcpy (player[1].color, "black");
	}
	else if (choice==2)
	{
		strcpy (player[0].color, "black");
		strcpy (player[1].color, "white");
	}
	
	player[1].number = 2;
	printf ("Enter Player %d name: ", player[1].number);
	fflush(stdin);
	gets(player[1].name);
	
	system ("@cls");
	printf ("\nPLAYERS SUMMARY:");
	printf ("\nPlayer name:\t");
	puts (player[0].name);
	printf ("Player number:\t%d", player[0].number);
	printf ("\nPlayer color:\t");
	puts (player[0].color);
	
	printf ("\nPlayer name:\t");
	puts (player[1].name);
	printf ("Player number:\t%d", player[1].number);
	printf ("\nPlayer color:\t");
	puts (player[1].color);
	
	//PLACEMENT OF PIECES
	for (count=0; count<32; count++)
	{
		if (count%2==0)
		{
			printf ("\n\nPlayer 1 turn.\n");
			printf ("Player name: ");
			puts (player[0].name);
			
			displayPieces();
			printf ("\nEnter piece to place: ");
			scanf ("%c");
			
			printf ("Enter row letter [A-H]: ");
			fflush (stdin);
			scanf ("%c", &row);
			
			while (row<65 || row>72)
			{
				printf ("\tInvalid input. Please try again.");
				printf ("\n\tEnter row letter [A-H]: ");
				fflush (stdin);
				scanf ("%c", &row);
			}
			
			printf ("Enter column number: ");
			fflush (stdin);
			scanf ("%d", &column);
			while (column<1 || column>7)
			{
				printf ("\tInvalid input. Please try again.");
				printf ("\n\tEnter column number [1-8]: ");
				fflush (stdin);
				scanf ("%d", &column);
			}
		}
		else if (count%2!=0)
		{
			printf ("\n\nPlayer 2 turn.\n");
			printf ("Player name: ");
			puts (player[1].name);
			
			printf ("Enter row letter [A-H]: ");
			fflush (stdin);
			scanf ("%c", &row);
			
			while (row<65 || row>72)
			{
				printf ("\tInvalid input. Please try again.");
				printf ("\n\tEnter row letter [A-H]: ");
				fflush (stdin);
				scanf ("%c", &row);
			}
			
			printf ("Enter column number: ");
			fflush (stdin);
			scanf ("%d", &column);
			while (column<1 || column>7)
			{
				printf ("\tInvalid input. Please try again.");
				printf ("\n\tEnter column number [1-8]: ");
				fflush (stdin);
				scanf ("%d", &column);
			}
		}
		board.tile[row-65][column-1].pcPos.row = (int)row - 65;
		board.tile[row-65][column-1].pcPos.row = (int)column - 65;
	}
	
	board = boardInit (board);

//	puts (board.tile[0][8].color);
	displayBoard (board);
	
	getch ();
}











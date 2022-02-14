#include <stdio.h>
#include <conio.h>
#include <string.h>

/* TODO (#1#): To fix:
               
               ** PROCESS
               - Problem with verifying piece owner in displayBoard
               - Problem with syncing if-else conditions in the displayBoard "for-loop"
               - Futher testing for validation whenever repeating pieces is selected i.e King or Queen
               
               
               ** FORMATTING
			   - Reformat Please try again and place "\t" to indicate error
			   - Realign "clearscreen" function
			   - Fix starting display: too much board are displayed
			   - Fix display of name: use %s instead of puts()
               
               -Available pieces: info
               Player name:
               Remaining pieces
               Number of remaining pieces
               
               
               #2: Whenever facing complex and seemingly dramatic task, 
			   remember that no task is BIG with step-by-step confrontation.
               
               #1: In abyss, there's something you can find, valuable, very valuable.
*/


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
	int check; 		//occupy indicator
	char color[6];	
	PIECE pcType;
	POSITION pcPos;
} TILE;

typedef struct playerInfo
{
	PLAYER plInfo;
	PIECE plPieces[16];
	int available;
} PLINFO;

typedef struct chessboard
{
	TILE tile[8][8];
} CHESSBOARD;


CHESSBOARD boardInit (CHESSBOARD board)
{
	int count, count1;
	
	for (count=0;count<8;count++)
	{
		for (count1=0;count1<8; count1++)
		{
			board.tile[count][count1].check = 1;
			
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
			
			if (((board.tile[count][count1].pcPos.column)%2==0 && (board.tile[count][count1].pcPos.row)%2==0) ||  ((board.tile[count][count1].pcPos.column)%2!=0 && (board.tile[count][count1].pcPos.row)%2!=0))
			{
				strcpy (board.tile[count][count1].color, "yellow");
				strcpy (board.tile[count][count1].pcType.name, " ");
			}
			else if (((board.tile[count][count1].pcPos.column)%2==0 && (board.tile[count][count1].pcPos.row)%2!=0) ||  ((board.tile[count][count1].pcPos.column)%2!=0 && (board.tile[count][count1].pcPos.row)%2==0))
			{
				strcpy (board.tile[count][count1].color, "green");
				strcpy (board.tile[count][count1].pcType.name, " ");
			}
		}
	}
	return board;	
}

PLINFO infoInit (PLINFO info, PLAYER player)
{
	info.plInfo = player;
	info.available = 16;
	PIECE piece;

	//initialization for pieces' name (16)
	int count = 0;
	for (count=0; count<16; count++)
	{ 
		if (count<8)
		{
//			piece.plOwner = player;
//			playerInfo.plPieces[count].name = piece;
			strcpy (info.plPieces[count].name, "Pawn");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
		else if (count>=8 && count<=9)
		{
			strcpy (info.plPieces[count].name, "Rook");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
		else if (count>=10 && count<=11)
		{
			strcpy (info.plPieces[count].name, "Knight");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
		else if (count>=12 && count<=13)
		{
			strcpy (info.plPieces[count].name, "Bishop");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
		else if (count==14)
		{
			strcpy (info.plPieces[count].name, "Queen");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
		else if (count==15)
		{
			strcpy (info.plPieces[count].name, "King");
			info.plPieces[count].plOwner = player;
			info.plPieces[count].pcPos.column = ' ';
			info.plPieces[count].pcPos.row = 0;
		}
	}
	return info;
}

//function to fill up the piece's name depending on the inputted character
PIECE checkPieceType (char piece, char row, int column, PLAYER player)
{
	PIECE pieceName;
	pieceName.pcPos.row = row;
	pieceName.pcPos.column = column;
	pieceName.plOwner = player;
	
	switch (piece)
			{
				case 'P':
					strcpy (pieceName.name, "Pawn");
					return pieceName;
				
				case 'R':
					strcpy (pieceName.name, "Rook");
					return pieceName;
					
				case 'H':
					strcpy (pieceName.name, "Knight");
					return pieceName;
					
				case 'B':
					strcpy (pieceName.name, "Bishops");
					return pieceName;
				
				case 'Q':
					strcpy (pieceName.name, "Queen");
					return pieceName;
					
				case 'K':
					strcpy (pieceName.name, "King");
					return pieceName;
			}
}

int verifyPieceValue (PLINFO playerInfo, char piece)
{
	int count = 0;
	switch (piece)
			{
				case 'P':
					for (count=0; count<8; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Pawns. Please select another piece and try again.\n");
					break;
				
				case 'R':
					for (count=8; count<10; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Rooks. Please select another piece and try again.\n");
					break;	
					
				case 'H':
					for (count=10; count<12; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Knights. Please select another piece and try again.\n");
					break;	
					
				case 'B':
					for (count=12; count<14; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("There's no available Bishops. Please select another piece and try again.");
					break;
					
				case 'Q':
					count = 14;
					if (playerInfo.plPieces[count].pcPos.column ==' ')
					{
						return count;
					}
					else
					{
						printf ("Queen is already placed. Please select another piece and try again.");
					}
					break;
					
				case 'K':
					count = 15;
					if (playerInfo.plPieces[count].pcPos.column ==' ')
					{
					
						return count;
					}
					else
					{
						printf ("\tKing is already placed. Please select another piece and try again.\n");
					}
					break;
				default:
					return 69;
			}
}


//DISPLAY FUNCTIONS BELOW
void displayPlayerInfo (PLINFO playerInfo)
{
	int count = 0;
	/*
	printf ("\nPLAYER NAME: %s\n", playerInfo.plInfo.name);
	printf ("PLAYER NUMBER: %d\n", playerInfo.plInfo.number);
	printf ("PLAYER COLOR: %s\n", playerInfo.plInfo.color);
	
	
	for (count=0; count<8; count++)
	{
		printf ("%c ", playerInfo.plPieces[count].name[0]);
//		printf ("#%d: %s\n", count, playerInfo.plPieces[count].name);
//		printf ("%s\n", playerInfo.plPieces[count].plOwner.name);
	}
	printf ("\n");
		for (count=7; count<16; count++)
	{
		printf ("%c ", playerInfo.plPieces[count].name[0]);
//		printf ("#%d: %s\n", count, playerInfo.plPieces[count].name);
//		printf ("%s\n", playerInfo.plPieces[count].plOwner.name);
	}*/
	
	printf ("\nPLAYER NAME: %s\n", playerInfo.plInfo.name);
	printf ("PLAYER COLOR: %s\n", playerInfo.plInfo.color);
	printf ("PIECES POSITION:\n");
	for (count=0; count<16; count++)
	{
		if (count<8)
		{
			printf ("Pawn [%d]: (%c, %d)\n", count+1, playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
		else if (count>=8 && count<=9)
		{
			printf ("Rook [%d]: (%c, %d)\n", count+1, playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
		else if (count>=10 && count<=11)
		{
			printf ("Knight [%d]: (%c, %d)\n", count+1, playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
		else if (count>=12 && count<=13)
		{
			printf ("Bishop [%d]: (%c, %d)\n", count+1, playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
		else if (count==14)
		{
			printf ("Queen: (%c, %d)\n", playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
		else if (count==15)
		{
			printf ("King: (%c, %d)\n", playerInfo.plPieces[count].pcPos.row, playerInfo.plPieces[count].pcPos.column);
		}
	}

}

void displayBoard (CHESSBOARD board, PLAYER player)
{
//	int count, count1;
	char check;
	
	int count = 0;
	int count1 = 0;
	int N = 8;
//	char board[N][N];
	char letter = 65;
	char display;

	printf ("   ");
	for (count=0, letter=65; count<N; count++, letter++)
	{
		//letter A-H
		if (count==0)
		{
			for (count1=0; count1<N; count1++)
			{
				printf ("%4d", count1+1);
			}
		}
		
		//1st count=0 corner of the board
		if (count<1)
		{
			printf ("\n    ");
		}
	
		for (count1=0; count1<N && count==0; count1++)
		{
			if (count1==0)
			{
				printf ("%c%c%c%c%c", 201, 205, 205, 205, 203);
			}
			else if (count1==N-1)
			{
				printf ("%c%c%c%c", 205, 205, 205, 187);
			}
			else
			{
				printf ("%c%c%c%c", 205, 205, 205, 203);
			}
		}
		
		//inner board ascii including column numbers
		printf ("\n");
		printf ("%3c ", letter);
		for (count1=0; count1<N; count1++)
		{
			if (count1==N-1)
			{
//				printf ("PL#: %d", board.tile[count][count1].pcType.plOwner.number);
				printf ("%c ", 186);
//				printf ("%c", board.tile[count][count1].pcType.name[0]);
				if (board.tile[count][count1].pcType.name[1]=='n')
				{
					if (board.tile[count][count1].pcType.plOwner.number==1)
					{
						printf ("H");
					}
					else if (board.tile[count][count1].pcType.plOwner.number==2)
					{
						printf ("h");
					}
				}
				else
				{
					if (board.tile[count][count1].pcType.plOwner.number==1)
					{
						printf ("%c", board.tile[count][count1].pcType.name[0]);
					}
					else if (board.tile[count][count1].pcType.plOwner.number==2)
					{
						if (board.tile[count][count1].pcType.name[0]!=' ')
						{
							printf ("%c", board.tile[count][count1].pcType.name[0] + 32);
						}
						else
						{
							printf ("%c", board.tile[count][count1].pcType.name[0]);
						}
					}
					else
					{
						printf ("%c", board.tile[count][count1].pcType.name[0]);
					}
				}
				printf (" %c", 186);
			}
			else
			{
				printf ("%c ", 186);
//				printf ("%c", board.tile[count][count1].pcType.name[0]);
				if (board.tile[count][count1].pcType.name[1]=='n')
				{
					if (board.tile[count][count1].pcType.plOwner.number==1)
					{
						printf ("H");
					}
					else if (board.tile[count][count1].pcType.plOwner.number==2)
					{
						printf ("h");
					}
				}
				else
				{
					if (board.tile[count][count1].pcType.plOwner.number==1)
					{
						printf ("%c", board.tile[count][count1].pcType.name[0]);
					}
					else if (board.tile[count][count1].pcType.plOwner.number==2)
					{
						if (board.tile[count][count1].pcType.name[0]!=' ')
						{
							printf ("%c", board.tile[count][count1].pcType.name[0] + 32);
						}
						else
						{
							printf ("%c", board.tile[count][count1].pcType.name[0]);
						}
					}
					else
					{
							printf ("%c", board.tile[count][count1].pcType.name[0]);
					}
				}
				printf (" ");
			}
		}
		
		printf("\n    ");
		
		if (count<N-1)
		{
			for (count1=0; count1<N; count1++)
			{
				if (count1==N-1)
				{
					printf ("%c%c%c%c%c", 206, 205, 205, 205, 185);
				}
				else if (count1==0)
				{
					printf ("%c%c%c%c", 204, 205, 205, 205);
				}
				else
				{
					printf ("%c%c%c%c", 206, 205, 205, 205);
				}
			}
			
		}
//		printf ("|");
		if (count==N-1)
		{
//			printf ("\n");
//			printf ("    ");
			for (count1=0; count1<N && count==N-1; count1++, letter++)
			{
				if (count1==0)
				{
					printf ("%c%c%c%c%c", 200, 205, 205, 205, 202);
				}
				else if (count1==N-1)
				{
					printf ("%c%c%c%c", 205, 205, 205, 188);
				}
				else
				{
					printf ("%c%c%c%c", 205, 205, 205, 202);
				}
			}
		}
	}
/*
	printf ("   ");
	for (count=0, letter=65; count<N; count++, letter++)
	{
		if (count==0)
		{
			for (count1=0; count1<N; count1++)
			{
				printf ("%4d", count1+1);
			}
		}
	
		
		//1st count=0 corner of the board
		if (count<1)
		{
			printf ("\n    ");
		}
	
		for (count1=0; count1<N && count==0; count1++)
		{
			if (count1==0)
			{
				printf ("%c%c%c%c%c", 201, 205, 205, 205, 203);
			}
			else if (count1==N-1)
			{
				printf ("%c%c%c%c", 205, 205, 205, 187);
			}
			else
			{
				printf ("%c%c%c%c", 205, 205, 205, 203);
			}
		}
		
		//inner board ascii including column numbers
		printf ("\n");
		printf ("%3c ", letter);
		for (count1=0; count1<N; count1++)
		{
			if (count==N-1)
			{
				printf ("%c", board.tile[count][count1].pcType.name[0]);
				printf ("  %c", 186);
			}
				
			else
			{
				printf ("%c ", 186);	
			}
		}
	
		printf("\n    ");
		
		if (count<N-1)
		{
			for (count1=0; count1<N; count1++)
			{
				if (count1==N-1)
				{
					printf ("%c%c%c%c%c", 206, 205, 205, 205, 185);
				}
				else if (count1==0)
				{
					printf ("%c%c%c%c", 204, 205, 205, 205);
				}
				else
				{
					printf ("%c%c%c%c", 206, 205, 205, 205);
				}
			}
			
		}
		
		if (count==N-1)
		{
//			printf ("\n");
//			printf ("    ");
			for (count1=0; count1<N && count==N-1; count1++)
			{
				if (count1==0)
				{
					printf ("%c%c%c%c%c", 200, 205, 205, 205, 202);
				}
				else if (count1==N-1)
				{
					printf ("%c%c%c%c", 205, 205, 205, 188);
				}
				else
				{
					printf ("%c%c%c%c", 205, 205, 205, 202);
				}
			}
		}
	}
	*/
	printf ("\n");
	
	
	
	/*
	printf ("\nOCCUPIED TEST:\n");
	for (count=0; count<8;count++)
	{
		for (count1=0; count1<8; count1++)
		{
			printf ("%d ",  board.tile[count][count1].check);
		}
		printf ("\n");
	}
	
	
	printf ("\nPOSITION TEST:\n");
	for (count=0; count<8;count++)
	{
		for (count1=0; count1<8; count1++)
		{
			printf ("(%c, %d) ",  board.tile[count][count1].pcPos.row, board.tile[count][count1].pcPos.column);
		}
		printf ("\n");
	}
	*/
	
}

void displayPieces (PLINFO playerInfo)
{
	int count, count1 = 0;

	printf ("PIECES [case-sensitive]");
	
	printf ("\nPawns\t-\tP\nRooks\t-\tR\nKnights\t-\tH\nBishops\t-\tB\nQueens\t-\tQ\nKing\t-\tK\n");
		printf ("Number of Remaining Pieces: %d\n", playerInfo.available);
		for (count=0; count<16; count++)
		{
			if (playerInfo.plPieces[count].pcPos.column==32)
			{
				if (playerInfo.plPieces[count].name[1]=='n')
				{
					printf ("H ");
				}
				else
				{
					printf ("%c ", playerInfo.plPieces[count].name[0]);
				}
			}
		}
		printf ("\n\n");
}


main ()
{
	
	PLAYER player[2];
	CHESSBOARD board;
	PLINFO plinfo[2];
	int count,count1 = 0;
	int choice = 0;
	char row;
	int column = 0;
	char piece;
	char pieceName[20];
	int valid;
	int position;
	/*
	player[0].number = 1;
	player[1].number = 2;
	player
	displayPlayerInfo(plinfo[0]);
	displayPlayerInfo(plinfo[0]);
	board = boardInit(board);
	displayBoard(board, player[0]);
	displayBoard(board, player[1]);
	*/
	player[0].number = 1;
	printf ("Enter Player %d name: ", player[0].number);
	gets(player[0].name);


	printf ("Enter color \n\t[1] - white or [2] - black: ");
	fflush (stdin);
	scanf ("%d", &choice);
	
		while (choice!=1 && choice!=2)
		{
			printf ("Invalid input. Please try again.\n");
			printf ("Enter color \n\t[1] - white or [2] - black: ");
			fflush (stdin);
			scanf ("%d", &choice);
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
	
	
	plinfo[0] = infoInit(plinfo[0], player[0]);


	player[1].number = 2;
	printf ("Enter Player %d name: ", player[1].number);
	fflush (stdin);
	gets(player[1].name);
	
	plinfo[1] = infoInit(plinfo[1], player[1]);

	
	
	system("@cls");
	printf ("\nPLAYERS SUMMARY:");
	printf ("\nPlayer Name:\t");
	puts (player[0].name);
	printf ("Player Number: %d", player[0].number);
	printf ("\nPlayer Color: ");
	puts (player[0].color);
//	displayPlayerInfo (plinfo[0]);	
	
	printf ("\nPlayer Name:\t");
	puts (player[1].name);
	printf ("Player Number: %d", player[1].number);
	printf ("\nPlayer Color: ");
	puts (player[1].color);
//	displayPlayerInfo (plinfo[1]);
	
	board = boardInit(board);
	displayBoard(board, player[0]);
	displayBoard(board, player[1]);
	
	//placing the pieces
	for (count=0; count<32; count++, valid=0)
	{
			if (count%2==0)
			{
				printf ("\n\nPlayer 1 turn.\n");
				printf ("Player name: ");
				puts (player[0].name);
				while (valid!=1 && plinfo[0].available>0)
				{
					displayPieces(plinfo[0]);
					printf ("Enter piece to place: ");
					fflush(stdin);
					scanf ("%c",&piece);
					
					while (piece!='P' && piece!='R' && piece!='H' && piece!='B' && piece!='Q' && piece!='K')
					{
						printf ("Invalid piece type. Please try again.\n");
						printf ("Enter piece to place: ");
						fflush(stdin);
						scanf ("%c",&piece);
					}
					position = verifyPieceValue(plinfo[0], piece);
					while (position<0 || position>15)
					{
						printf ("Enter piece to place: ");
						fflush(stdin);
						scanf ("%c",&piece);
						position = verifyPieceValue(plinfo[0], piece);
					}
					
					printf ("Enter row letter [A-H]: ");
					fflush(stdin);
					scanf ("%c", &row);
					
					while(row<65 || row>72)
					{
						printf ("Invalid row input. Please try again.\n");
						printf ("Enter row letter [A-H]: ");
						fflush(stdin);
						scanf ("%c", &row);
					}
					
					printf ("Enter column number [1-8]: ");
					fflush(stdin);
					scanf ("%d", &column);
					
					while(column<1 || column>8)
					{
						printf ("Invalid column input. Please try again.\n");
						printf ("Enter column number [1-8]: ");
						fflush(stdin);
						scanf ("%d", &column);
					}
					
					//checks if occupied
					if (board.tile[row-65][column-1].check==1)
					{
						board.tile[row-65][column-1].pcType = checkPieceType(piece, row, column, player[0]);
						board.tile[row-65][column-1].check = 2;
						
						
						plinfo[0].plPieces[position] = board.tile[row-65][column-1].pcType;	
						plinfo[0].available-=1;
						//printf ("TEST: %s", board.tile[row-65][column-1].pcType.name);
						valid = 1;
					}
					else if (board.tile[row-65][column-1].check==2)
					{
						printf ("Invalid position input. Please try again.\n");
						valid = 0;
					}
				}
			displayBoard(board, player[0]);
//			displayPlayerInfo(plinfo[0]);
			printf ("%c%c%c%c%cPress any key to continue. %c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
			getch();
			system("@cls");
			}
			else if (count%2!=0)
			{
				printf ("\n\nPlayer 2 turn.\n");
				printf ("Player name: ");
				puts (player[1].name);
				while (valid!=1 && plinfo[1].available>0)
				{
					displayPieces(plinfo[1]);
					printf ("Enter piece to place: ");
					fflush(stdin);
					scanf ("%c",&piece);
					
					while (piece!='P' && piece!='R' && piece!='H' && piece!='B' && piece!='Q' && piece!='K')
					{
						printf ("Invalid piece type. Please try again.\n");
						printf ("Enter piece to place: ");
						fflush(stdin);
						scanf ("%c",&piece);
					}
					position = verifyPieceValue(plinfo[1], piece);
					while (position<0 || position>15)
					{
						printf ("Enter piece to place: ");
						fflush(stdin);
						scanf ("%c",&piece);
						position = verifyPieceValue(plinfo[1], piece);
					}
					
					printf ("Enter row letter [A-H]: ");
					fflush(stdin);
					scanf ("%c", &row);
					
					while(row<65 || row>72)
					{
						printf ("Invalid row input. Please try again.\n");
						printf ("Enter row letter [A-H]: ");
						fflush(stdin);
						scanf ("%c", &row);
					}
					
					printf ("Enter column number [1-8]: ");
					fflush(stdin);
					scanf ("%d", &column);
					
					while(column<1 || column>8)
					{
						printf ("Invalid column input. Please try again.\n");
						printf ("Enter column number [1-8]: ");
						fflush(stdin);
						scanf ("%d", &column);
					}
					
					//checks if occupied
					if (board.tile[row-65][column-1].check==1)
					{
						board.tile[row-65][column-1].pcType = checkPieceType(piece, row, column, player[1]);
						board.tile[row-65][column-1].check = 2;
						position = verifyPieceValue(plinfo[1], piece);
						
						plinfo[1].plPieces[position] = board.tile[row-65][column-1].pcType;	
						plinfo[1].available-=1;
						//printf ("TEST: %s", board.tile[row-65][column-1].pcType.name);
						valid = 1;
					}
					else if (board.tile[row-65][column-1].check==2)
					{
						printf ("Invalid position input. Please try again.\n");
						valid = 0;
					}
				}
			displayBoard(board, player[1]);
//			displayPlayerInfo(plinfo[1]);
			printf ("%c%c%c%c%cPress any key to continue. %c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
			getch();
			system("@cls");
			}
	}
		
		/*
		board.tile[][].pcType.plOwner
		board.tile[row-65][column-1].pcTy
		board.tile[row-65][column-1].
		board.tile[row-65][column-1].pcPos.row = column;*
		board = boardInit(board);
		*/
	
	printf ("\n");
	displayBoard(board, player[0]);
	displayPlayerInfo(plinfo[0]);
	displayPlayerInfo(plinfo[1]);
	getch ();
}



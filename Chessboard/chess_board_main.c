#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "chess_board_structs.h"
#include "chess_board_functions.h"

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
//	plinfo.plPieces.
	
	
	player[0].number = 1;
	printf ("Enter Player %d name: ", player[0].number);
	gets(player[0].name);


	printf ("Enter color \n\t[1] - white or [2] - black: ");
	fflush (stdin);
	scanf ("%d", &choice);
	
		while (choice!=1 && choice!=2)
		{
			printf ("\tInvalid input. Please try again.\n");
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
	printf ("\n");
	board = boardInit(board);
	displayBoard(board, player[0]);	

	
	printf ("\nPLAYERS SUMMARY:");
	printf ("\nPlayer Name:\t");
	puts (player[0].name);
	printf ("Player Number: %d", player[0].number);
	printf ("\nPlayer Color: ");
	puts (player[0].color);
	
	
	printf ("\nPlayer Name:\t");
	puts (player[1].name);
	printf ("Player Number: %d", player[1].number);
	printf ("\nPlayer Color: ");
	puts (player[1].color);
	
	printf ("\n %c%c%c%c%cPress any key to continue. %c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	getch();
	system("@cls");
	
	//placing the pieces
	for (count=0; count<32; count++, valid=0, position=69)
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
						printf ("\tInvalid piece type. Please try again.\n");
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
						printf ("\tInvalid row input. Please try again.\n");
						printf ("Enter row letter [A-H]: ");
						fflush(stdin);
						scanf ("%c", &row);
					}
					
					printf ("Enter column number [1-8]: ");
					fflush(stdin);
					scanf ("%d", &column);
					
					while(column<1 || column>8)
					{
						printf ("\tInvalid column input. Please try again.\n");
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
						valid = 1;
					}
					else if (board.tile[row-65][column-1].check==2)
					{
						printf ("\tInvalid position input. Please try again.\n");
						valid = 0;
					}
				}
			displayBoard(board, player[0]);
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
						printf ("\tInvalid piece type. Please try again.\n");
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
						valid = 1;
					}
					else if (board.tile[row-65][column-1].check==2)
					{
						printf ("Invalid position input. Please try again.\n");
						valid = 0;
					}
				}
			displayBoard(board, player[1]);
			printf ("%c%c%c%c%cPress any key to continue. %c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
			getch();
			system("@cls");
			}
	}
	printf ("\n");
	displayBoard(board, player[0]);
	displayPlayerInfo(plinfo[0]);
	displayPlayerInfo(plinfo[1]);
	getch ();
}


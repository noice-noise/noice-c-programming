

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
					return 69;
				
				case 'R':
					for (count=8; count<10; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Rooks. Please select another piece and try again.\n");
					return 69;	
					
				case 'H':
					for (count=10; count<12; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Knights. Please select another piece and try again.\n");
					return 69;
					
				case 'B':
					for (count=12; count<14; count++)
					{
						if (playerInfo.plPieces[count].pcPos.column ==' ')
						{
							return count;
						}
					}
					printf ("\tThere's no available Bishops. Please select another piece and try again.\n");
					return 69;
					
				case 'Q':
					count = 14;
					if (playerInfo.plPieces[count].pcPos.column ==' ')
					{
						return count;
					}
					else
					{
						printf ("\nQueen is already placed. Please select another piece and try again.\t");
					}
					return 69;

					
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
					return 69;
				default:
					return 69;
			}
}


//DISPLAY FUNCTIONS BELOW
void displayPlayerInfo (PLINFO playerInfo)
{
	int count = 0;
	
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
	char check;
	int count = 0;
	int count1 = 0;
	int N = 8;
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
				printf ("%c ", 186);
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
		if (count==N-1)
		{
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
	printf ("\n");
}

void displayPieces (PLINFO playerInfo)
{
	int count, count1 = 0;

	printf ("PIECES [case-sensitive]");
	
	printf ("\nPawns\t-\tP\nRooks\t-\tR\nKnights\t-\tH\nBishops\t-\tB\nQueens\t-\tQ\nKing\t-\tK\n");
		printf ("Available Pieces: %d\n", playerInfo.available);
		printf ("Remaining Pieces: \n");
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


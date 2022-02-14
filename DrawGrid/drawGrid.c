#include <stdio.h>





main ()
{
	int count = 0;
	int count1 = 0;
	int N = 12;
	char board[N][N];
	char letter = 65;
	
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			board[count][count1] = 254;
		}
	}
	printf ("   ");
	for (count=0; count<N; count++)
	{
		//letter A-H
		for (count1=0; count1<N && letter<90-(N*2)+N; count1++, letter++)
		{
			printf ("%4c", letter);
		}
		
		//1st count=0 corner of the board
		if (count<1)
		{
			printf ("\n    ");
		}
	
		for (count1=0; count1<N && count==0; count1++, letter++)
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
		printf ("%3d ", count+1);
		for (count1=0; count1<N; count1++)
		{
			if (count1==N-1)
			{
				printf ("%c %c %c", 186, board[count][count1], 186);
			}
			else
			{
				printf ("%c %c ", 186, board[count][count1]);
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
	int N = 8;
	char field[N][N];
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
					printf ("%c %c %c", 186, field[count][count1], 186);
				}
				else if (count1!=N)
				{
					printf ("%c %c ", 186, field[count][count1]);
				}              
			}
			printf ("\n     ");
			for (count1=0; count1<N-1; count1++)
			{
				if (count1==0 && count<N-1)
				{
					printf ("%c%c%c%c%c",204, 205, 205, 205, 206);
				}
				else if (count!=N-1)
				{
					printf ("%c%c%c%c",205,205, 205, 206);
				}
				if (count1==(N-2) && count!=(N-1))
				{
					printf ("%c%c%c%c", 205, 205, 205, 185);
				}
			}
			printf ("\n ");
	}
	
	
	*/
	
	
	
	
}

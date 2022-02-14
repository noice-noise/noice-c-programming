#include <stdio.h>
#include <conio.h>

/*
This program will
	Boost your pointer understanding: 			+5
	Boost your pointer to array like a pro 		+64
									TOTAL	=	 69		oy HAHAHAHAHAHA


	Also contains 2 challenges
*/
void convertToNxN (int *array1, int *array2, int rowSize, int colSize);

main ()
{
	//Try experiment, ilisdi ang mga values
	int row = 0;
	int col = 0;
	int count, count1 = 0;
	
	char choice;
	int M = 3;		//variables paras LIMITS, capslock para dali ma-identify 
	int N = 4;
	int O = 3;
	int P = 3;
	
	int array1[M][N];
	int array2[O][P];	
	printf ("A Program to Convert %dx%d array into %dx%d using pointers", M, N, O, P);
	
	printf ("\n\nEnter contents:\n");
	for (row=0; row<M; row++)
	{
		for (col=0; col<N; col++)
		{
			fflush(stdin);
			printf ("array1[%d][%d]: ", row, col);
			scanf ("%d", &array1[row][col]);
		}
	}
	convertToNxN (&array1[0][0], &array2[0][0], O, P);	//letter P = 3, so convert 4 x 3 into 3 x 3 array
	
	//--- Challenge#1: Pagcreate laing function niya sulayi ug print ang contents gamit pointers 
	printf ("\nArray1 contents:\n");
	for (row=0; row<M; row++)		//array1 disp
	{
		for (col=0; col<N; col++)
		{
			printf ("%d ", array1[row][col]);
		}
		printf ("\n");
	}
	
	printf ("\nArray2 contents:\n");
	for (row=0; row<O; row++)		//array2 disp
	{
		for (col=0; col<P; col++)
		{
			printf ("%d ", array2[row][col]);
		}
		printf ("\n");
	}
	//---
	
	getch ();
	printf ("\n\nMAGWIIIK!");
}


void convertToNxN (int *array1, int *array2, int rowSize, int colSize)
{
	
	int row, col = 0;
	
	for (row=0; row<rowSize; row++)
	{
		for (col=0; col<colSize; col++)
		{
			
			*array2 = *array1;	//assign values
			array1++;			//so nig human ug transfer, proceed dayun sa sunod na cell
			array2++;			//increment sad ni para butngan
		}
		array1++;	//kinahanglanon para dili ma traverse ang last column | try gayi remove unsay resulta hihi :P
	}
}


/*void diplayShits (int *array1, int ---kaw na bahala bruh char)	//challenge #1
{

}
*/


/*
	BOSS CHALLENGE:
	
	MASTER THE CONCEPT OF THIS PROGRAM, AS IN M A S T E R.
	THEN, RECREATE THIS PROGRAM FROM  S C R A T C H USING YOUR OWN LOGIC, OWN VARIABLES, AND CLEAN output, of course kay hugaw biya nako pagkahimo HAHAHAHAH
	God bless MWAAT!
	~ moemoekyunkyun
*/


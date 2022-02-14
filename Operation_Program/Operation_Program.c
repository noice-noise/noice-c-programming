#include <stdio.h>
#include <conio.h>
#include "matrixOps.h"



main ()
{
	
	int r, c, i =0;
	int matrixSizes[4];
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	
	int operationChoice = 0;
	int check = 0;
	
	printf ("Enter matrix1 row: ");
	scanf ("%d", &matrixSizes[0]);
	m = matrixSizes[0];
	
	printf ("Enter matrix1 col: ");
	scanf ("%d", &matrixSizes[1]);
	n = matrixSizes[1];
	
	printf ("Enter matrix2 row: ");
	scanf ("%d", &matrixSizes[2]);
	o = matrixSizes[2];
	
	printf ("Enter matrix2 col: ");
	scanf ("%d", &matrixSizes[3]);
	p = matrixSizes[3];
	
	int matrix1[m][n];
	int matrix2[o][p];
	int result[m][p];
	
	for (r=0; r<m; r++)
	{
		for (c=0; c<n; c++)
		{
			printf ("Matrix1[%d][%d]: ", r, c);
			scanf ("%d", &matrix1[r][c]);
		}
	}
	
	for (r=0; r<o; r++)
	{
		for (c=0; c<p; c++)
		{
			printf ("Matrix2[%d][%d]: ", r, c);
			scanf ("%d", &matrix2[r][c]);
		}
	}
	
	printf ("\nEnter operation choice: ");
	scanf ("%d", &operationChoice);
	
	matrixOperation(operationChoice, &matrixSizes[0], &result[0][0], &matrix1[0][0], &matrix2[0][0]);
	
	/*
	if (operationChoice==1 || operationChoice==2)
	{
		check = matrixAddSub (&matrix1[0][0], &matrix2[0][0], &result[0][0], &matrixSizes[0], operationChoice);
		if (check==0)
		{
			printf ("Cannot perform operation. The matrices are of not the same size.");
		}
	}
	else if (operationChoice==3)
	{
		check = matrixMultiplication (&matrix1[0][0], &matrix2[0][0], &result[0][0], &matrixSizes[0]);
		if (check==0)
		{
			printf ("Cannot perform operation. The matrices are of not the same size.");
		}
	}
	else if (operationChoice==4)
	{
		matrixTranspose (&matrix1[0][0], m, n);
	}
	*/
	
//	sample (&matrix1[0][0], &matrix2[0][0], &result[0][0], &matrixSizes[0]);
	
	printf ("\nMatrix Sizes:\n");
	for (r=0; r<4; r++)
	{
			printf ("%3d ", matrixSizes[r]);
	}
	
	printf ("\nMatrix1:\n");
	for (r=0; r<m; r++)
	{
		for (c=0; c<n; c++)
		{
			printf ("%3d ", matrix1[r][c]);
		}
		printf ("\n");
	}

	printf ("\nMatrix2:\n");
	for (r=0; r<o; r++)
	{
		for (c=0; c<p; c++)
		{
			printf ("%3d ", matrix2[r][c]);
		}
		printf ("\n");
	}
	
	printf ("\nResult:\n");
	for (r=0; r<m; r++)
	{
		for (c=0; c<p; c++)
		{
			printf ("%3d ", result[r][c]);
		}
		printf ("\n");
	}
	
	getch ();
}

/*

int matrixAddSub (int *matrix1, int *matrix2, int *result, int *matrixSizes, int choice)
{
	int r, c = 0;
	
	if ((*(matrixSizes)==*(matrixSizes + 2))&&(*(matrixSizes + 1)==*(matrixSizes + 3)))
	{
		if (choice==1)
		{
				for (r=0; r<((*(matrixSizes + 1))*(*(matrixSizes + 2))); r++)
			{
				*result = *matrix1 + *matrix2;
				matrix1++;
				matrix2++;
				result++;
			}
			return 1;
		}
		else if (choice==2)
		{
			for (r=0; r<((*(matrixSizes + 1))*(*(matrixSizes + 2))); r++)
			{
				*result = *matrix1 - *matrix2;
				matrix1++;
				matrix2++;
				result++;
			}
			return 1;
		}
	}
	else
	{
		return 0;
	}
}



int matrixMultiplication (int *matrix1, int *matrix2, int *result, int *matrixSizes)
{
	int r, c, i = 0;
	int sum = 0;

	
	if (*(matrixSizes + 1)==*(matrixSizes + 2))
	{
		for (r=0; r<*(matrixSizes); r++)
		{
			for (c=0; c<*(matrixSizes+3); c++, sum = 0)
			{
				for (i=0; i<*(matrixSizes+2); i++)
				{
					sum += *(matrix1 + r * *(matrixSizes+1) + i) * *(matrix2 + i * *(matrixSizes + 3) + c);
				}
				*result = sum;
				result++;
			}
		}
	}
	else
	{
		return 0;
	}
}

int matrixTranspose (int *matrix, int m, int n)
{
	int r, c = 0;
	
	for (r=0; r<m; r++)
	{
		for (c=0; c<n; c++)
		{
			*matrix *= -1;
			matrix++;
		}
	}

}
*/


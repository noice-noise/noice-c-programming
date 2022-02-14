#include <stdio.h>
/*
int matrixAddSub(int, int, int, int, int);
int matrixMultiplication(int, int, int, int);
int matrixTranspose(int, int, int);
int matrixAddSub (int *matrix1, int *matrix2, int *result, int *matrixSizes, int choice);
int matrixMultiplication (int *matrix1, int *matrix2, int *result, int *matrixSizes);
int matrixTranspose (int *matrix, int m, int n);*/


int matrixOperation (int choice, int *matrixSizes, int *result, int *matrix1, int *matrix2)
{
	int check = 0;
	if (choice==1 || choice==2)
	{
		check = matrixAddSub (matrix1, matrix2, result, matrixSizes, choice);
		if (check==0)
		{
			printf ("Cannot perform operation. The matrices are of not the same size.");
		}
	}
	else if (choice==3)
	{
		check = matrixMultiplication (matrix1, matrix2, result, matrixSizes);
		if (check==0)
		{
			printf ("Cannot perform operation. The n and o sizes are of not the same size.");
		}
	}
	else if (choice==4)
	{
		matrixTranspose (matrix1, *(matrixSizes), *(matrixSizes+1));
	}
	
	
}


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
				*result = *matrix1 + (*matrix2 * -1);
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

#include<stdio.h>


int calculator (int num1, int num2, float *result, char operation)
{
	float numf1 = num1;
	float numf2 = num2;
	
	float quotient = 0;	
	if (operation=='+')
	{
		*result = (num1 + num2);
		return 1;
	}
	else if (operation=='-')
	{
		*result = (num1 - num2);
		return 1;
	}
	else if (operation=='/')
	{
		
		quotient = (numf1 / numf2);
		*result = quotient;
//		printf ("%f", quotient);
		return 1;
	}
	else if (operation=='*')
	{
		*result = (num1 * num2);
	}
	else if (operation=='%')
	{
		if (num1>=0 && num2>=0)
		{
			*result = (num1%num2);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
	
	
	
	
	
}

int textToFloat (char *string, float *number)
{
	
	float result = 0;
	int r = 0;
	
	while (*(string+r)!='\0')
	{
		if (*(string+r)<48 || *(string+r)>57)
		{
			printf ("INVALID.");
			return 0;
		}
	}
	
	while (*(string+r)!='\0')
	{
		result += *(string+r) - '0';
		result *= 10;
		r++;
	}
	*number = result;
	return 1;
	
}

/*

result = 0;
		printf ("\n%c\n", *(string+r));
		result += *(string+r);
		printf ("RESULTCURR: %f", result);
		result *= 10;
		printf ("RESULTCURR: %f", result);
		r++;
int floatToText (float number, char *string, int decimal)
{
	float temp = number;
	char string1[50];
	string1[count] = temp%10;
	
	
	
	
}*/







int matrixMultiplciation (float *matrix1, float *matrix2, float *result, int *matrixSizes)
{
	int r, c, i = 0;
	
	if (*(matrixSizes+1)==*(matrixSizes+2))
	{
		for (r=0; r<*(matrixSizes); r++)
		{
			for (c=0; c<*(matrixSizes+3); c++)
			{
				for (i=0; i<*(matrixSizes+1); i++)
				{
					*result = *(matrix1 + r * *(matrixSizes+1) + i) * *(matrix2 + c * *(matrixSizes+2) + i);
					result++;
				}
			}
		}
	}
	else
	{
		return 0;
	}
	
	
	
	
}

main ()
{
	/*
	int num1, num2 = 0;
	float result = 0;
	char operation;
	printf ("num1: ");
	scanf ("%d", &num1);
	
	printf ("num2: ");
	scanf ("%d", &num2);
	
	printf ("Operation: ");
	fflush (stdin);
	scanf ("%c", &operation);
	calculator (num1, num2, &result, operation);
	
	
	printf ("NUM1: %d\n", num1);
	printf ("NUM2: %d\n", num2);
	printf ("RESULT: %f\n", result);
	printf ("RESULT: %f\n", result);
	
	/*
	int r, c = 0;
	float matrix1[2][3] = {{1, 0, -3},{-2, 4, 1}};
	float matrix2[3][4] = {{1, 0, 4, 1},{-2, 3, -1, 5},{0, -1, 2, 1}};
	float result[2][4];
	int matrixSizes[4] = {2, 3, 3, 4};
	
	for (r=0; r<2; r++)
	{
		for (c=0; c<3; c++)
		{
			printf ("%d ", matrix1[r][c]);
		}
		printf ("\n");
	}
	*/
	
	float resultFloat;
	char name[50];
	gets(name);
	
//	printf ("%s", name);
	textToFloat(&name[0], &resultFloat);
	printf ("%f", resultFloat);
	
}

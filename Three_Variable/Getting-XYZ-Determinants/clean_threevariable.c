#include <stdio.h>
#define EQ 3
#define VAR 4
#define MIN 2


void convertTo3x3 (int *inputsArray, int *convertedArray);
int getMinorDeterminant (int row, int *minorD);
void minorDeterminant (int row, int *minorD, int *converterdArray);
int solveDeterminant (int *convertedArray, int *minorD, int size);
void coefficientSwitch (int choice, int *inputsArray, int *convertedArray, int *temp, int col);


main ()
{
	
	int inputsArray[EQ][VAR];
	int convertedArray[EQ][EQ];
	int minorD[MIN][MIN];
	int temp[EQ];
	int result = 0;
	int d = 0;
	int dx = 0;
	int dy = 0;
	int dz = 0;
	int x, y ,z = 0;
	
	int count, count1, count2, count3 = 0;
	int sum = 0;
		
	printf ("EQUATIONS ARE IN GENERAL FORM:\n");
	printf ("(ax + by + c = d)\n\n");
	
	for (count=0; count<EQ; count++)
	{
		fflush (stdin);
		printf ("Enter coefficients of equation #%d: ", count+1);
		scanf ("%d %d %d %d", &inputsArray[count][0], &inputsArray[count][1], &inputsArray[count][2], &inputsArray[count][3]);
	}

	convertTo3x3 (&inputsArray[0][0], &convertedArray[0][0]);



	
	
	d = solveDeterminant (&convertedArray[0][0], &minorD[0][0], EQ);
	
	for (count=0; count<EQ; count++, result=0)
	{
		coefficientSwitch (1, &inputsArray[0][0], &convertedArray[0][0], &temp[0], count);
		result = solveDeterminant (&convertedArray[0][0], &minorD[0][0], EQ);
		coefficientSwitch (2, &inputsArray[0][0], &convertedArray[0][0], &temp[0], count);
		printf ("\n");
		
			
		if (count==0)
		{
			dx = result;
		}
		else if (count==1)
		{
			dy = result;
		}
		else if (count==2)
		{
			dz = result;
		}
	}
	
	x = dx / d;
	y = dy / d;
	z = dz / d;

	printf ("Determinants:\n");
	printf ("\tD: %d\n", d);
	printf ("\tDx: %d\n", dx);
	printf ("\tDy: %d\n", dy);
	printf ("\tDz: %d\n", dz);
	printf ("Value of variables:\n");
	printf ("\tx: %d\n", x);
	printf ("\ty: %d\n", y);
	printf ("\tz: %d\n", z);
}

void convertTo3x3 (int *inputsArray, int *convertedArray)
{
	int count, count1 = 0;
	
	for (count=0; count<EQ; count++)
	{
		for (count1=0; count1<EQ; count1++)
		{
			*convertedArray = *inputsArray;
			convertedArray++;
			inputsArray++;	
		}
		inputsArray++;
	}
	
	
}


int getMinorDeterminant (int row, int *minorD)
{
	int result = 0;
	
	result = row * (((*(minorD + 0 * MIN + 0)) * (*(minorD + 1 * MIN + 1))) - ((*(minorD + 1 * MIN + 0)) * (*(minorD + 0 * MIN + 1))));
	
	return result; 
}
	
	
void minorDeterminant (int row, int *minorD, int *convertedArray)
{
	if (row==0)
	{
			*minorD = *(convertedArray + 1 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 1 * EQ +2);
			minorD++;
			*minorD = *(convertedArray + 2 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 2 * EQ +2);
	}
	else if (row==1)
	{
			*minorD = *(convertedArray + 0 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 0 * EQ +2);
			minorD++;
			*minorD = *(convertedArray + 2 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 2 * EQ +2);
	}
	else if (row==2)
	{
			*minorD = *(convertedArray + 0 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 0 * EQ +2);
			minorD++;
			*minorD = *(convertedArray + 1 * EQ +1);
			minorD++;
			*minorD = *(convertedArray + 1 * EQ +2);
	}
}

int solveDeterminant (int *convertedArray, int *minorD, int size)
{
	int count, count1, sum = 0;
	for (count=0, sum=0; count<size; count++)
	{
		minorDeterminant (count, minorD, convertedArray);
		if (count==1)
		{
			sum -= getMinorDeterminant (*(convertedArray + count * size + 0), minorD);	
		}
		else
		{
			sum += getMinorDeterminant (*(convertedArray + count * size + 0), minorD);
		}	
	}
	return sum;
}



void coefficientSwitch (int choice, int *inputsArray, int *convertedArray, int *temp, int col)
{
	int count = 0;
	
	
	if (choice==1)		//choice 1==switch & temp
	{
		for (count=0; count<EQ; count++)
		{
			*temp = *(convertedArray + count * EQ + col);
			temp++;	
		}
		
		for (count=0; count<EQ; count++)
		{
			*(convertedArray + count * EQ + col) = *(inputsArray + count * VAR + (VAR-1));
		}
	}
	else if (choice==2)	//choice 2==restore coefficients
	{
		for (count=0; count<EQ; count++)
		{
			*(convertedArray + count * EQ + col) = *temp;
			temp++;
		}

	}
	
}









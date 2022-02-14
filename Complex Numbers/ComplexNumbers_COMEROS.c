#include <stdio.h>


struct complex_num
{

	float real;
	float imaginary;
};

struct answers_num
{
	struct complex_num addResult;
	struct complex_num subResult;
	struct complex_num prodResult;
	struct complex_num quoResult;
};

struct answers_num addSubComplex (struct complex_num comNum1, struct complex_num comNum2, struct answers_num answers1, char operation)
{
		
	if (operation=='+')
	{
		answers1.addResult.real = comNum1.real + comNum2.real;
		answers1.addResult.imaginary = comNum1.imaginary + comNum2.imaginary;
		return answers1;
	}
	else if (operation=='-')
	{
		answers1.subResult.real = comNum1.real - comNum2.real;
		answers1.subResult.imaginary = comNum1.imaginary - comNum2.imaginary;
		return answers1;
	}
	
	
}


struct answers_num multiplyComplex (struct complex_num comNum1, struct complex_num comNum2, struct answers_num answers1)
{
	answers1.prodResult.real = (comNum1.real * comNum2.real) - (comNum1.imaginary * comNum2.imaginary);
	answers1.prodResult.imaginary = (comNum1.real * comNum2.imaginary) + (comNum1.imaginary * comNum2.real);
	return answers1;
}

struct answers_num divideComplex (struct complex_num comNum1, struct complex_num comNum2, struct answers_num answers1)
{
	float denominator;
	answers1.quoResult.real = (comNum1.real * comNum2.real) + (comNum1.imaginary * comNum2.imaginary);
	answers1.quoResult.imaginary = (comNum1.imaginary * comNum2.real) - (comNum1.real * comNum2.imaginary);
	denominator = (comNum2.real * comNum2.real) + (comNum2.imaginary * comNum2.imaginary);
//	printf ("DENOM: %f", denominator);
	answers1.quoResult.real /= denominator;
	answers1.quoResult.imaginary /= denominator;
	
	return answers1;
}

int compareComplex(struct complex_num comNum1, struct complex_num comNum2)
{

	if ((comNum1.real==comNum2.real) && (comNum1.imaginary==comNum2.imaginary))
	{
		return 0;
	}
	else if (comNum1.real>comNum2.real)
	{
		return 1;
	}
	else if (comNum1.real<comNum2.real)
	{
		return 2;
	}
	else if (comNum1.real==comNum2.real)
	{
		if (comNum1.imaginary>comNum2.imaginary)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

}

void displayComplex (struct answers_num answers1)
{
	
	
	if (answers1.addResult.imaginary<0)
	{
		printf ("\nADDITION");
		printf ("\n%.2f - %.2fi", answers1.addResult.real, -1 * answers1.addResult.imaginary);
	}
	else
	{
		printf ("\nADDITION");
		printf ("\n%.2f + %.2fi", answers1.addResult.real, answers1.addResult.imaginary);
	}
	
	if (answers1.subResult.imaginary<0)
	{
		printf ("\n\nSUBTRACTION");
		printf ("\n%.2f - %.2fi", answers1.subResult.real, -1 * answers1.subResult.imaginary);
	}
	else
	{
		printf ("\n\nSUBTRACTION");
		printf ("\n%.2f + %.2fi", answers1.subResult.real, answers1.subResult.imaginary);
	}
	
	if (answers1.prodResult.imaginary<0)
	{
		printf ("\n\nMULTIPLICATION");
		printf ("\n%.2f - %.2fi", answers1.prodResult.real, -1 * answers1.prodResult.imaginary);
	}
	else
	{
		printf ("\n\nMULTIPLICATION");
		printf ("\n%.2f + %.2fi", answers1.prodResult.real, answers1.prodResult.imaginary);
	}
	
	if (answers1.quoResult.imaginary<0)
	{
		printf ("\n\nDIVISION");
		printf ("\n%.2f - %.2fi", answers1.quoResult.real, -1 * answers1.quoResult.imaginary);
	}
	else
	{
		printf ("\n\nDIVISION");
		printf ("\n%.2f + %.2fi", answers1.quoResult.real, answers1.quoResult.imaginary);
	}
	
	
}




main()
{
	
	struct complex_num comNum1, comNum2;
	struct answers_num answers1;
	char operation;
	int compare = 0;
	
	printf ("\n\nFirst complex number:\n");
	
	printf ("Enter real part: ");
	scanf ("%f", &comNum1.real);

	printf ("Enter imaginary part: ");
	scanf ("%f", &comNum1.imaginary);
	
	
	printf ("\nSecond complex number:\n");
	
	printf ("Enter real part: ");
	scanf ("%f", &comNum2.real);
	
	printf ("Enter imaginary part: ");
	scanf ("%f", &comNum2.imaginary);
	
//	printf ("comNum1: %.2f %.2f", comNum1.real, comNum1.imaginary);
//	printf ("comNum2: %.2f %.2f", comNum2.real, comNum2.imaginary);
	
/*
	comNum1.real = 2;
	comNum1.imaginary = 7;
	comNum2.real = 3;
	comNum2.imaginary = -4;
*/

	answers1 = addSubComplex(comNum1, comNum2, answers1, '+');
/*
	comNum1.real = 9;
	comNum1.imaginary = 5;
	comNum2.real = 4;
	comNum2.imaginary = 7;
*/	
	answers1 = addSubComplex(comNum1, comNum2, answers1, '-');
/*	
	comNum1.real = 3;
	comNum1.imaginary = 2;
	comNum2.real = 5;
	comNum2.imaginary = 6;
*/	

	answers1 = multiplyComplex(comNum1, comNum2, answers1);
/*	
	comNum1.real = 3;
	comNum1.imaginary = 2;
	comNum2.real = 4;
	comNum2.imaginary = -5;
*/	
	answers1 = divideComplex(comNum1, comNum2, answers1);
	
	displayComplex(answers1);
	
	
	printf ("\n\nLARGEST: ");
	compare = compareComplex(comNum1, comNum2);
	if (compare==0)
	{
		printf ("The two complex numbers are equal.");
	}
	else if (compare==1)
	{
		printf ("The first complex number is larger than the second.");
	}
	else if (compare==2)
	{
		printf ("The second complex number is larger than the first.");
	}
	
}








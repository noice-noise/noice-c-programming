#include <stdio.h>

#include <math.h>


//atoi -- string to int
//atof -- string to float


//itoa -- int to string
//ftoa -- float to string


//atoi
int myAtoi (char *string, int length)
{
	int count = 0;
	int result = 0;
	for (count=0; count<length; count++)
	{
		result = result * 10 + (*(string+count) - '0');
//		printf ("RESULT: %d", result);
//		printf ("\nC: %d ", *(string + count)-'0');
	}
	return result;
}

int getLengthString (char *string)
{
	int count = 0;
	while (*(string+count)!='\0')
	{
		count++;
	}
	printf ("String Length: %d\n", count);
	return count;
}

int getLengthDigits (int number)
{
	int count = 0;
	
	while (number>0)
	{
		number/=10;
		count++;
	}
	return count;
}

float myAtof (char *string, int length, int baseLimit)
{
	int count, count1, count2 = 0;
	int point = 0;
	int resultInteger = 0;
	float resultDecimal = 0;
	
	while (*(string+point)!='.')
	{
		point++;
	}
	
	
	
	for (count=0; count<point+1; count++)
	{
			resultInteger = resultInteger * 10 + *(string+count) - '0';
			
	}
		printf ("RESULTINT: %d\n", resultInteger);

	 printf ("POINT: %d", point);
	for (count=point; count<length; count++, point++)
	{
		resultDecimal = resultDecimal * 10 + *(string+point) - '0';
	}	
		printf ("RESULTDEC: %f\n", resultDecimal);
		
	resultDecimal / pow (10, baseLimit);	
		
	printf ("\nRESULTEST: %f", (float)resultInteger+resultDecimal);
	return (float)resultInteger + resultDecimal;	
	
}
	
	
	


char myItoa (int number, char *string, int length)
{
	int count = 0;
	int temp = number;
	for (count=length-1; count>=0; count--)
	{
		printf ("C: %d\n", count);
		*(string + count) = temp%10 + '0';
		temp/=10;
		printf ("String: %d", *(string+count));
	}
	
	
}

char  myFtoa (float number, char *string, int base)
{
	int count = 0;
	
	
	
}


main ()
{
	int count, count1 = 0;
	char string[30];
	int result;
	float resultf = 0;
	int choice = 3;
	int length = 0;
	int number;
//	printf ("Select operation: [1] - atoi; [2] - atof; [3] - itoa; [4] - ftoa");
//	scanf ("%d", &choice);
	
	if (choice==1)
	{
		printf ("Enter a number: ");
		scanf ("%s", &string);
		length = getLengthString(&string[0]);
	//	printf ("LEngth: %d", length);
		result = myAtoi(&string[0], length);
		printf ("REsult: %d", result);	
	}
	else if (choice==2)
	{
		printf ("Enter int number: ");
		scanf ("%d", &number);
		length = getLengthDigits(number);
		myItoa (number, &string[0], length);  
	}
	else if (choice==3)
	{
		printf ("Enter int number: ");
		scanf ("%s", &string);
		length = getLengthString(&string[0]);
		resultf = myAtof(&string[0], length, 5);
		printf ("MAINRESULT: %f", resultf);
	}
	printf ("YO:\n");
	/*
	for (count=0; count<length; count++)
	{
		printf ("%c ", string[count]);
	}*/
}










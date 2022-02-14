#include <stdio.h>


main ()
{
	int length = 0;
	char input[100];
	int count = 0;
	
	printf ("Enter palidrome: ");
	gets (input);
	
	while (input[count]!='\0')
	{
		
		printf ("%c", input[count]);
		count++;
	}
	
	length = getLength (&input[0], &input[0]);
	char reverseContents[length];
	
	printf ("LENGTH: %d", length);
	checkPalidrome(length, &input[0]);
	
	
	
	
}


int getLength (int *array, int *mark)
{
	int count = 0;
	
	
	while (*array!='\0')
	{
		printf ("%d\n", count);
		printf ("%c\n", *array);
		count++;
		array++;
		
	}
	printf ("\nCOUNT: %d", count);
	printf ("MARKARRAY: %d", array - mark);
	return array - mark;
	
}




int checkPalidrome (int length, int *array)
{
	int r, c, valid = 0;
	for (r=0, c=length; r<length; r++, c--)
	{
		if (*(array+r) = *(array+c))
		{
			printf ("OK!");
			valid++;
		}
	}
	
	printf ("VALID: %d", valid);
	
	
}

#include <stdio.h>

main ()
{
	//functype: int
	//return 1 if okay, else 0 for false/error
	char symbol;
	int value = 0;
	
	
	scanf ("%c", &symbol);
	value = symbol;
	
	printf ("value: %d", value);
	
	if ((value>=65 && value<=90) || (value>=97 && value<=122))
	{
		return 1;
	}
	
	printf ("\tInvalid symbol! Please try again.");
	//return 0
	
}

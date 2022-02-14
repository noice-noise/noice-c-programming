#include <stdio.h>
#include <conio.h>
#define MIN 3
#define MAX 9


main ()
{
	
	int count = 0;
	int count1 = 0;
	int N = 0;
	
	scanf ("%d", &N);
	
	
	for (count=0; count<N; count++)
	{
			for (count1=0; count1<N-1; count1++)
			{
				if (count1!=N)
				{
					//the space before char is the player symbol
					printf (" %c", 186);
				}
			}
			printf ("\n");
			for (count1=0; count1<N-1; count1++)
			{
				if (count!=N-1)
				{
					printf ("%c%c", 205, 206);
				}
				
				if (count1==(N-2) && count!=(N-1))
				{
					printf ("%c", 205);
				}
			}
			printf ("\n");
	}
	
}





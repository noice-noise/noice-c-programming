#include <stdio.h>
#define MAX 5

int array [MAX][MAX];
int matrix [MAX];
void fieldInit (int);

main ()
{
	int N = 0;
	int count, count1 = 0;
	scanf ("%d", &N);

	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			array[count][count1] = 32;
			fieldInit (array[count][count1]);
		}
		printf ("\n");
	}
	
	
	for (count=0; count<N; count++)
	{
		for (count1=0; count1<N; count1++)
		{
			fieldInit (array[count][count1]);
		}
		printf ("\n");
	}
}


void fieldInit (int n)
{
	printf ("%c ", n);	
}




#include <stdio.h>
#include <stdlib.h>

main ()
{
	int elements, count, mark = 0;
	int *ptr = 0;
	
	printf ("Enter number of elements: ");
	scanf ("%d", &elements);
	
	ptr = (int*) malloc (elements * sizeof (int));
	
	for (count=0; count<elements; count++)
	{
		printf ("Enter elements #%d[%d]: ", count, ptr+count);
		scanf ("%d", ptr+count);
	}
	
	for (count=0; count<elements; count++)
	{
		if (*(ptr+mark)<*(ptr+count))
		{
			mark = count;
		}
	}
	
	printf ("The largest number is %d", *(ptr + mark));
}

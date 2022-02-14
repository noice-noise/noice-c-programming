#include <stdio.h>

main ()
{
	
	
	int count = 0;
	
	for (count=0; count<256; count++)
	{
		printf ("#%d: %c\n", count, count);
	}
	
	getche();
}

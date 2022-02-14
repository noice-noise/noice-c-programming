#include <stdio.h>
#include <conio.h>



main ()
{
	
	int colLimit = 0;
	int rowLimit = 0;
	int n = 0;
	int k = 0;
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int nf = 1;
	int kf = 1;
	int nkf = 1;
	int cell = 0;
	int pascal [colLimit][rowLimit];
	

	printf ("Enter size: ");
	scanf ("%d", &colLimit);
	rowLimit = colLimit;
	
	//n-k control
	for (count=0; count<colLimit; count++)
	{
		for (count1=0; count1<rowLimit; count1++, nf=1, kf=1, nkf=1)
		{
			//factorial loop
			for (count2=count; count2>0; count2--)
			{
				nf *= count2;
			}
			
			for (count2=count1; count2>0; count2--)
			{
				kf *= count2;
			}
			
			for (count2=(count-count1); count2>0; count2--)
			{
				nkf *= count2;
			}
			pascal[count][count1] = (nf)/(kf * nkf);
			printf ("Pascal[%d][%d]: %d\n", count, count1, pascal[count][count1]);
		}
	}
	 
	 printf ("Pascal: %d", pascal[5][5]);
	 
	 /*
	for (count=0; count<colLimit; count++)
	{
		for (count1=0; count1<rowLimit; count1++)
		{
			printf ("%d ", pascal[count][count1]);
		}
		printf ("\n");
	}
	*/
	
	
	
	/*
	for (count=0; count<colLimit; count++)
	{
		for (count1=0; count1<count+1; count1++)
		{
			if (pascal[count][count1]>=1)
			{
//				printf (" | %d %d | ", count, count1);
//				printf ("%d ", pascal[count][count1]);
				printf ("Array: [%d][%d]: %d\n", count, count1, pascal[count][count1]);
			}
			
		}
		//printf ("\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	for (count2=n; count2>0; count2--)
	{
		nf *= count2;
	}
	
	for (count2=k; count2>0; count2--)
	{
		kf *= count2;
	}
	
	for (count2=(n-k); count2>0; count2--)
	{
		nkf *= count2;
	}
	
	cell = (nf)/(kf * nkf);
	printf ("%d", cell);
	
	
	printf ("Enter Pascal Triangle's size: ");
	scanf ("%d", &colLimit);
	row = colLimit + 1;
	
	for (count; count<colLimit; count++)
	{
		for (count1=0; count1<rowLimit; count++)
		{
			
			pascal[count][count1] = ()
		}
	 } 
	
	*/
	
	
}

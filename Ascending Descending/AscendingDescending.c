#include <stdio.h>

main () {
	
	int count, count1;
	int num[10];
	int num1, num2;
	int temp=0;
	/*
	scanf ("%d %d", &num1, &num2);
	printf ("%d %d", num1, num2);
	temp = num1;
	num1 = num2;
	num2 = temp;
	printf ("%d %d", num1, num2);
	*/
	
	
	for (count=0; count<10; count++) {
		printf ("Enter num[%d]: ", count);
		scanf ("%d", &num[count]);
	}
	
	for (count=0; count<10; count++) {
		printf ("%d ", num [count]);
	}
	
	
	
	printf ("\n");
	
	for (count=0; count<10; count++) {
		
		for (count1=count+1; count1<10; count1++, temp=0) {
			
			if (num[count]<num[count1]) {
				//reverse
//				printf ("\n%d %d", num[count], num[count1]);
				temp = num[count];
				num[count] = num[count1];
				num[count1] = temp;
//				printf ("\n%d %d", num[count], num[count1]);
				
			}
			
			
			
		}
		
		
	}
	
	printf ("\n");
	for (count=0; count<10; count++) {
		printf ("%d ", num [count]);
	}
	
	
	
}

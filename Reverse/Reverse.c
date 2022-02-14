#include <stdio.h>

main (){
	
	
	int count=0;
	char input[50];
	int length;
	
	printf ("Enter a string: ");
	gets(input);
	
//	puts(input);
	
	for (count=0; count<50;count++) {
		
//		printf ("%c\n", input[count]);
		if (input[count]=='\0') {
//			printf ("BAWAL ANG BOBO.");
			length = count;
//			printf ("%c\n", input[count]);
//			printf ("%d", length);
			break;
		}
	}
	
	for (count=length; count>=0; count--) {
		printf ("%c", input[count]);
		
	}
	
}

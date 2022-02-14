


#include <stdio.h>
#include <conio.h>


int main (){
	
	int N=0;
	int i=0;
	int j=0;
	int largestDiff = 0;
	int temp=0;
	
	printf("Enter size of array: ");
	scanf ("%d", &N);

	int numbers[N];
	
	for (i=0; i<N; i++){
		printf("Enter #%d integer: ", i+1);
		scanf ("%d", &numbers[i]);
	}
	
	for (i=0; i<N; i++){
		printf("Integer: %d\n", numbers[i]);
	}
	
	
	for (temp=0, i=0; i<N; i++){
		for (j=0; j<N; j++, temp=0){
			
			temp = numbers[i] - numbers[j];

			if (largestDiff<temp){
				largestDiff = temp;
				printf ("LD: %d\n", largestDiff);
			}

		}
	}
	printf ("LDFINAL: %d\n", largestDiff);
	
	getch();
	
	return 0;
}

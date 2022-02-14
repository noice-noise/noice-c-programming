#include <stdio.h>
#include <conio.h>

void basic (int input, int input1);

void special (int current, int next);

main (){
	
	long long int amount=0;

	int count, count1=0;
	int temp=0;
	int length=0;
	char place[10];
	
	printf ("Enter amount: ");
	scanf ("%d", &amount);
	printf ("Amount: %d", amount);
	temp=amount;
	for (count=0; count<10; count++)
	{
		temp/=10;
		if (temp<=0) {
			length = count+1;
			break;
		}
	}
	
	int input[length];
	int input1[length];
	
	
	temp = amount;
	printf ("Temp: %d\n", temp);
	for (count=0, count1=length; count<length && count1>0; count++, count1--) {
		
		input[count] = temp%10;
		temp/=10;
		printf ("Input: %d\n", input[count]);
		printf ("Temp: %d\n", temp);
		
		
	}
		
	//store the numbers in input1 in reverse to reappropriate shits
	printf ("\n");
	for (count=0, count1=length-1; count<length && count1>=0; count++, count1--) {
		
		//printf ("%d ", input[count]);
		input1[count]=input[count1];
		printf ("%d ", input1[count]);
	}
	printf ("\nLENGTH: %d\n", length);//
	
	
	for (count=0; count<length; count++) {
		
		switch (count) {
			
		case 0:
			basic (input1[count], input1[count+1]);
			printf ("billion ");
			break;
		case 1:
			basic (input1[count], input1[count+1]);
			printf ("hundred ");
			break;
		case 2:
			special (input1[count], input1[count+1]);
//			printf ("hundred ");
			
			break;	
		default:
			printf ("DEFAULT");
			break;
		
		
	} 
		
		
	}
	
	
}



void basic (int input, int input1)
{
//		printf ("INPUT: %d", input);

		if (input==1)
		printf ("one ");
	else if (input==2)
		printf ("two ");
	else if (input==3)
		printf ("three ");
	else if (input==4)
		printf ("four ");
	else if (input==5)
		printf ("five ");
	else if (input==6)
		printf ("six ");
	else if (input==7)
		printf ("seven ");
	else if (input==8)
		printf ("eight ");
	else if (input==9)
		printf ("nine ");	
}



void special (int current, int next) {
	
	//if greater than 20
	
	//if less than 20
	if (current==1) {
		if (next==0) {
			printf ("ten ");
		}
	}
	else if (current==1) {
		if (next==1) {
			printf ("eleven ");
		}
	}
	else if (current==1) {
		if (next==2) {
			printf ("twelve ");
		}
	}
	else if (current==1) {
		if (next==3) {
			printf ("thirteen ");
		}
	}
	else if (current==1) {
		if (next==4) {
			printf ("fourteen ");
		}
	}
	
			
	
	
	
}

#include <stdio.h>


int main ()
{
	
	int nationality, year, sex, invalid = 0;
	int fee = 200;
	
	printf ("ENTER NATIONALITY\nFilipino [1] or Foreigner [2]:\n");
	scanf ("%d", &nationality);
	
	if (nationality!=1 && nationality!=2)
	{
		printf ("Invalid input. Please only input 1 or 2\n");
		invalid = 1;
	}
	else if (nationality==2)
	{
		fee = fee + 200; //add 200 if foreigner
	}
	
	printf ("\nENTER SEX\nMale [1] or Female[2]: ");
	scanf ("%d", &sex);
	
	
	if (sex!=1 && sex!=2)
	{
		printf ("Invalid input. Please only input 1 or 2\n");
		invalid = 1;
	}
	else if (sex==1)
	{
		fee = fee + 100;	//add 100 of male
	}
	else if (fee==2)
	{
		fee = fee + 25;		//otherwise, add 25 if female
	}
	
	printf ("\nENTER YEAR LEVEL (1-4): ");
	scanf ("%d", &year);
	if (year<1 || year>4)
	{
		printf ("Invalid input. Please only input 1 or 2\n");
		invalid = 1;
	}
	else if (year==1)
	{
		fee = fee + 25;		//add 25 if year 1
	}
	
	if (invalid==1)
	{
		printf ("\nCan't display miscellaneous. \nPlease try again and enter proper inputs."); //will display nothing if one input is invalid.
	}
	else
	{
		printf ("\n\nTOTAL MISCELLANEOUS: %d", fee);
	}
	
	
	
	//coded with <3
}

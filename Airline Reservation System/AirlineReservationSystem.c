#include <stdio.h>
#include <conio.h>

main ()
{
	
	//Airplane reservation system
	//tmb~
	
	int LIMIT = 5;
	int firstClass[LIMIT];
	int economyClass[LIMIT];
	int count = 0;
	int choice = 0;
	int fc = 0;
	int es = 0;
	
	for (count=0; count<LIMIT; count++)
		{
			firstClass[count]=0;
			economyClass[count]=0;
		}
		
	while (fc != LIMIT || es!=LIMIT)
	{
		
		printf ("Welcome to SiRaulo Airlines!\n\n");
		
		printf ("First Class Section: \t");
		for (count=0; count<LIMIT; count++)
		{
			printf ("[%d] ", firstClass[count]);
		}
		printf("\n");
		printf ("Economy Section: \t");
		for (count=0; count<LIMIT; count++)
	{
		printf ("[%d] ", economyClass[count]);
		
	}
		printf ("\n\n");
		printf ("Please type [1] First Class or [2] Economy Class: ");
		scanf ("%d", &choice);
		
			while (choice!=1  && choice!=2)
			{
				printf ("Please only select [1] First Class or [2] Economy Class: ");
				scanf ("%d", &choice);
			}
		
		if (choice==1)
		{
			if (fc==5)
			{
				printf ("First Class Section is full.\nWould you like to book in the Economy Section instead? \n\tYes [Y] or No [N]");
				fflush(stdin);
				scanf ("%c", &choice);
				if (choice=='Y' || choice=='y')
				{
					for (count=0; count<LIMIT; count++)
					{
						if (economyClass[count]==0)
						{
							economyClass[count] = 1;
							es++;
							break;
						}
				
					}
				}
				else if (choice=='N' || choice=='n')
				{
					printf ("Next flight will be leaving in 3 hours.");
				}
				
			}
			
			for (count=0; count<LIMIT; count++)
			{
				if (firstClass[count]==0)
				{
					firstClass[count] = 1;
					fc++;
					break;
				}
				
			}
			
		}
		else if (choice==2){
			if (es==5)
			{
				printf ("Economy Section is full.\nWould you like to book in the First Class Section instead? \n\tYes [Y] or No [N]");
				fflush(stdin);
				scanf ("%c", &choice);
				if (choice=='Y' || choice=='y')
				{
					for (count=0; count<LIMIT; count++)
					{
						if (firstClass[count]==0)
						{
							firstClass[count] = 1;
							fc++;
							break;
						}
				
					}
				}
				else if (choice=='N' || choice=='n')
				{
					printf ("Next flight will be leaving in 3 hours.");
				}
				
			}
			
			for (count=0; count<LIMIT; count++)
			{
				if (economyClass[count]==0)
				{
					economyClass[count] = 1;
					es++;
					break;
				}
				
			}
			
		}
	}
	
		printf ("\n\n\nWelcome to SiRaulo Airlines!\n\n");
		
		printf ("First Class Section: \t");
		for (count=0; count<LIMIT; count++)
		{
			printf ("[%d] ", firstClass[count]);
		}
		printf("\n");
		printf ("Economy Section: \t");
		for (count=0; count<LIMIT; count++)
	{
		printf ("[%d] ", economyClass[count]);
		
	}
		printf ("\n\n");
		
	

	
	getch ();
	
	
	
	
	
	
}




#include <stdio.h>
/*	::PROGRAM INFO::
               
    This program asks a date within the 
    year 2019 from the user and displays 
    what day of week it is.
               
        Restrictions:
        Used only if-else functions 
        
    Formula used are only devised with a struggling student's powers. There's no magic
    of indians or such. By knowing the first day of the month, patterns can be spotted.
    This is only one of the countless ways to implement this program. Happwekwoding.
*/




main ()
{
	int year, month, day, positionofOne, positionofDay;
	
	printf ("Enter month: ");
	scanf ("%d", &month);
	
	printf ("Enter day: ");
	scanf ("%d", &day);
	

	if (month==1 && day==30)
	{
		positionofOne = 2;	//Number of days occupied in a week, before the 1st day of the month
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==2 && day==28)
	{
		positionofOne = 5;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}	
	else if (month==3 && day==31)
	{
		positionofOne = 5;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==4 && day==30)
	{
		positionofOne = 1;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}	
	else if (month==5 && day==31)
	{
		positionofOne = 3;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==6 && day==30)
	{
		positionofOne = 6;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==7 && day==31)
	{
		positionofOne = 1;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==8 && day==30)
	{
		positionofOne = 4;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==9 && day==31)
	{
		positionofOne = 0;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==10 && day==31)
	{
		positionofOne = 2;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==11 && day==30)
	{
		positionofOne = 5;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else if (month==12 && day==31)
	{
		positionofOne = 0;	
		positionofDay = (day%7) + positionofOne;
		if (positionofDay>7)
		{
			positionofDay -= 7;
		}
	}
	else
	{
		printf ("Invalid input. Please try again.");
	}
	printf ("\n\n");
	
	//conditions for display
	if (positionofDay==1)
	{
		printf ("Position of %d: Monday", day);
	}
	else if (positionofDay==2)
	{
		printf ("Position of %d: Tuesday", day);
	}
	else if (positionofDay==3)
	{
		printf ("Position of %d: Wednesday", day);
	}
	else if (positionofDay==4)
	{
		printf ("Position of %d: Thursday", day);
	}
	else if (positionofDay==5)
	{
		printf ("Position of %d: Friday", day);
	}			
	else if (positionofDay==6)
	{
		printf ("Position of %d: Saturday", day);
	}
	else if (positionofDay==7)
	{
		printf ("Position of %d: Sunday", day);
	}
	
	printf ("\n\n\n\n\n\n=)");
	
	
}
//coded with <3

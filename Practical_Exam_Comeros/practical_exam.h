


int calculator (int num1, int num2, float *result, char operation)
{
	float numf1 = num1;
	float numf2 = num2;
	
	float quotient = 0;	
	if (operation=='+')
	{
		*result = (num1 + num2);
		return 1;
	}
	else if (operation=='-')
	{
		*result = (num1 - num2);
		return 1;
	}
	else if (operation=='/')
	{
		
		quotient = (numf1 / numf2);
		*result = quotient;
		return 1;
	}
	else if (operation=='*')
	{
		*result = (num1 * num2);
	}
	else if (operation=='%')
	{
		if (num1>=0 && num2>=0)
		{
			*result = (num1%num2);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
	
}

int textToFloat (char *string, float *number)
{
	
	float result = 0;
	int r = 0;
	
	
	while (*(string+r)!='\0')
	{
		result += *(string+r) - '0';
		result *= 10;
		r++;
	}
	*number = result;
	return 1;
	
}


int matrixMultiplciation (float *matrix1, float *matrix2, float *result, int *matrixSizes)
{
	int r, c, i = 0;
	
	if (*(matrixSizes+1)==*(matrixSizes+2))
	{
		for (r=0; r<*(matrixSizes); r++)
		{
			for (c=0; c<*(matrixSizes+3); c++)
			{
				for (i=0; i<*(matrixSizes+1); i++)
				{
					*result = *(matrix1 + r * *(matrixSizes+1) + i) * *(matrix2 + c * *(matrixSizes+2) + i);
					result++;
				}
			}
		}
	}
	else
	{
		return 0;
	}
}
	
	

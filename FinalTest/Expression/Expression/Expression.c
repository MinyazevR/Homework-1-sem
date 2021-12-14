#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isTheStringAGroup(char* string)
{
	const int stringLength = strlen(string);
	int state = 0;
	for (int i = 0; i < stringLength + 1; i++)
	{
		switch (state)
		{
			case 0:
			{
				if (isDigit(string[i]))
				{
					state = 1;
					break;
				}
				return false;
			}
			case 1:
			{
				if (isDigit(string[i]))
				{
					state = 2;
					break;
				}
				return false;
			}
			case 2:
			{
				if (string[i] == '.')
				{
					state = 3;
					break;
				}
				return false;
			}
			case 3:
			{
				if (string[i] == 'B' || string[i] == 'M' || string[i] == 'S')
				{
					state = 4;
					break;
				}
				return false;
			}
			case 4:
			{
				if (isDigit(string[i]))
				{
					state = 5;
					break;
				}
				return false;
			}
			case 5:
			{
				if (isDigit(string[i]))
				{
					state = 6;
					break;
				}
				return false;
			}
			case 6:
			{
				if (string[i] == '-')
				{
					state = 7;
					break;
				}
				return false;
			}
			case 7:
			{
				if (string[i] == 'm')
				{
					state = 8;
					break;
				}
				return false;
			}
			case 8:
			{
				if (string[i] == 'm')
				{
					state = 9;
					break;
				}
				return false;
			}
			case 9:
			{
				if (string[i] == '\0')
				{
					return true;
				}
				return false;
			}
		}
	}
	return false;
}
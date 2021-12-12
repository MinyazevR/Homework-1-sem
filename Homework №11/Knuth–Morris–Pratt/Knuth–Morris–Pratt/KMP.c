#include "KMP.h"
#include <malloc.h>
#include <string.h>

int* findPrefix(char* substring, int* error)
{
	int* prefix = calloc(strlen(substring) + 1, sizeof(int));
	if (prefix == NULL)
	{
		*error = 1;
		return NULL;
	}
	prefix[0] = 0;
	int i = 1;
	int j = 0;
	while (substring[i] != '\0')
	{
		if (substring[j] == substring[i])
		{
			prefix[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			prefix[i] = 0;
			i++;
		}
		else
		{
			j = prefix[j - 1];
		}
	}
	return prefix;
}

int algorithmKMP(char* string, char* substring, int* prefix)
{
	int counterForString = 0;
	int CounterForSubstring = 0;
	while (string[counterForString] != '\0')
	{
		if (string[counterForString] == substring[CounterForSubstring])
		{
			counterForString++;
			CounterForSubstring++;
			if (CounterForSubstring == strlen(substring))
			{
				return counterForString - strlen(substring) + 1;
			}
		}
		else if (CounterForSubstring == 0)
		{
			counterForString++;
			if (counterForString == strlen(string))
			{
				return -1;
			}
		}
		else
		{
			CounterForSubstring = prefix[CounterForSubstring - 1];
		}
	}
	return -1;
}
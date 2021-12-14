#include "Expression.h"
#include "Test.h"
#include <stdio.h>

int main()
{
	if (!testIsTheStringAGroup())
	{
		printf("test failed");
		return -1;
	}
	char string[1000] = { '\0' };
	printf("enter the line:\n");
	scanf_s("%s", string, (unsigned)sizeof(string));
	if (!isTheStringAGroup(string))
	{
		printf("the string is not a valid group number on the mathmech");
		return -1;
	}
	printf("the string is the correct group number on the matmech");
}
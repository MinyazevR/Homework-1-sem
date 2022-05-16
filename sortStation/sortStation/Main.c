#include "../../Stack/Stack/Stack.h"
#include "SortStantion.h"
#include "SortStantionTest.h"
#include <stdio.h>

int main()
{
    if (!translationIntoPostfixFormAreTestPassing())
    {
        printf("Test failed");
        return -1;
    }
    char array[1000] = { '\0' };
    printf("enter the expression in the infix form\n");
    scanf_s("%[^\n]s", array, (unsigned)sizeof(array));
    int errorCode = 0;
    const char* const arrayToOutput = translationIntoPostfixForm(array, &errorCode);
    if (errorCode == 1)
    {
        printf("Incorrectly entered expression");
        return -1;
    }
    if (errorCode == 2)
    {
        printf("Memory not allocated");
        return -1;
    }
    if (errorCode == 3)
    {
        printf("A parenthesis is missing or an invalid character is entered");
        return -1;
    }
    printf("%s\n", arrayToOutput);
}
#include "../../Stack/Stack/Stack.h"
#include "SortStantion.h"
#include "SortStantionTest.h"
#include <stdio.h>
#include <errno.h>

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
    errno = 0;
    char* arrayToOutput = translationIntoPostfixForm(array);
    if (errno == 1)
    {
        printf("Stack is empty(Incorrect expression input)");
        return -1;
    }
    if (errno == 2)
    {
        printf("Memory not allocated");
        return -1;
    }
    if (errno == 3)
    {
        printf("The parenthesis is missing in the expression");
        return -1;
    }
    int counter = 0;
    while (arrayToOutput[counter] != '\0')
    {
        printf("%c ", arrayToOutput[counter]);
        counter++;
    }
}
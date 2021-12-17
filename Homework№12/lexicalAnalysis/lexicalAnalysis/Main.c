#include "TestLexicalAnalysis.h"
#include <stdio.h>
#include "ReadString.h"
#include "LexicalAnalysis.h"
#include <stdlib.h>

int main()
{
    if (!testCheckTestExpression())
    {
        printf("Test failed");
        return -1;
    }
    printf("enter the string\n");
    int error = 0;
    char* string = readString(&error);
    if (error == 1)
    {
        printf("failed to enter string\n");
        return -1;
    }
    bool result = checkExpression(string);
    free(string);
    if (!result)
    {
        printf("the entered string is not a real number\n");
        return -1;
    }
    printf("the entered string is a real number\n");
}
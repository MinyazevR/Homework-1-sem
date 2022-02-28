#include "../../Stack/Stack/Stack.h"
#include "Postfix.h"
#include "PostfixFormTest.h"
#include <stdio.h>

int main()
{
    if (!areTestPassingPostfixForm())
    {
        printf("Test failed");
        return -1;
    }
    char postfixEntry[250] = { '\0' };
    printf("enter the expression in postfix form\n");
    scanf_s("%[^\n]s", postfixEntry, (unsigned)sizeof(postfixEntry));
    int errorCode = 0;
    const float answer = countTheExpression(postfixEntry, &errorCode);
    if (errorCode == 1)
    {
        printf("Incorrect input of an expression in postfix form");
        return -1;
    }
    if (errorCode == 2)
    {
        printf("invalid character in the expression entry");
        return -1;
    }
    if (errorCode == 3)
    {
        printf("it is impossible to divide by 0");
        return -1;
    }
    printf("%f", answer);
}
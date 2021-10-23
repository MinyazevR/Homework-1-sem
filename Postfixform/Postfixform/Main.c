#include "../../Stack/Stack/Stack.h"
#include  "Postfix.h"
#include "postfixFormTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
    errno = 0;
    const float answer = countTheExpression(postfixEntry);
    if (errno == 1)
    {
        printf("Stack is empty");
        return -1;
    }
    if (errno == 2)
    {
        printf("invalid character in the expression entry");
        return -1;
    }
    if (errno == 3)
    {
        printf("Incorrect input of an expression in postfix form");
        return -1;
    }
    printf("%f", answer);
}
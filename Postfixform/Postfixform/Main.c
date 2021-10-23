#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include  "Postfix.h"
#include "postfixFormTest.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest() || !postfixFormTest())
    {
        printf("Test failed");
        return -1;
    }
    char postfixEntry[250] = { '\0' };
    printf("enter the expression in postfix form\n");
    scanf_s("%[^\n]s", postfixEntry, (unsigned)sizeof(postfixEntry));
    bool check = true;
    const int answer = countTheExpression(postfixEntry, &check);
    if (!check)
    {
        printf("Incorrect input");
        return 0;
    }
    printf("%d", answer);
}
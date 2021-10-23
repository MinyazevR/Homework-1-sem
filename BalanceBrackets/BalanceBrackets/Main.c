#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include "BalanceBracketsTest.h"
#include <stdio.h>

int main()
{
    if (!balanceBracketsTest() || !popTest() || !pushTest() || !deleteStackTest())
    {
        printf("Test failed");
        return -1;
    }
    char expressionFromParentheses[250] = { '\0' };
    printf("enter the expression in postfix form\n");
    scanf_s("%[^\n]s", expressionFromParentheses, (unsigned)sizeof(expressionFromParentheses));
    if (!checkCorrectOrderBrackets(expressionFromParentheses))
    {
        printf("incorrect");
        return 0;
    }
    printf("correct");
}
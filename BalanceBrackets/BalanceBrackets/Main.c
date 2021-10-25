#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
#include "BalanceBracketsTest.h"
#include <stdio.h>

int main()
{
    if (!balanceBracketsTest())
    {
        printf("Test failed");
        return -1;
    }
    char expressionFromParentheses[250] = { '\0' };
    printf("enter the expression that you want to check for the correct placement of brackets\n");
    scanf_s("%[^\n]s", expressionFromParentheses, (unsigned)sizeof(expressionFromParentheses));
    if (!checkCorrectOrderBrackets(expressionFromParentheses))
    {
        printf("The balance of the brackets is incorrect");
        return 0;
    }
    printf("The balance of the brackets is correct");
}
#include "BalanceBrackets.h"
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
    int errorCode = 0;
    bool result = checkCorrectOrderBrackets(expressionFromParentheses, &errorCode);
    if (errorCode == 1)
    {
        printf("The balance of the brackets is incorrect");
        return 0;
    }
    if (errorCode == 2)
    {
        printf("Insufficient memory");
        return -1;
    }
    if(!result)
    {
        printf("The balance of the brackets is incorrect");
        return 0;
    }
    printf("The balance of the brackets is correct");
}
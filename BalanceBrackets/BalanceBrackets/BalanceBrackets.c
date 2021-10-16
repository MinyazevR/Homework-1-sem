#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include "BalanceBracketsTest.h"
#include <stdio.h>
#include <stdlib.h>

bool checkCorrectOrderBrackets(char* expressionFromParentheses)
{
    Stack* head = NULL;
    int counter = 0;
    while (expressionFromParentheses[counter] != '\0')
    {
        if (expressionFromParentheses[counter] == '(' || expressionFromParentheses[counter] == '{'
            || expressionFromParentheses[counter] == '[')
        {
            push(&head, expressionFromParentheses[counter]);
        }
        else if (expressionFromParentheses[counter] == ')' || expressionFromParentheses[counter] == '}'
                 || expressionFromParentheses[counter] == ']')
        {
            if(isEmpty(head))
            {
                return false;
            }
            char k = pop(&head);
            if ((k == '(' && expressionFromParentheses[counter] != ')')
                || (k == '{' && expressionFromParentheses[counter] != '}')
                || (k == '[' && expressionFromParentheses[counter] != ']'))
            {
                return false;
            }
        }
        counter++;
    }
    if (isEmpty(head))
    {
        deleteStack(&head);
        return true;
    }
    deleteStack(&head);
    return false;
}
int main()
{
    if (!balanceBracketsTest() || !popTest() || !pushTest() || !deleteStackTest())
    {
        printf("Test failed");
        return -1;
    }
    char expressionFromParentheses[250] = { '\0' };
    printf("enter the expression in postfix form\n");
    scanf_s("%s", expressionFromParentheses, (unsigned)_countof(expressionFromParentheses));
    if (!checkCorrectOrderBrackets(expressionFromParentheses))
    {
        printf("incorrect");
        return 0;
    }
    printf("correct");
}
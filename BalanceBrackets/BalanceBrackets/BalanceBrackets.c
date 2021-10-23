#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
#include <stdlib.h>
#include <errno.h>

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
            char topOfTheStack = pop(&head);
            {
                if (errno == 1)
                {
                    return false;
                }
            }
            if ((topOfTheStack == '(' && expressionFromParentheses[counter] != ')')
                || (topOfTheStack == '{' && expressionFromParentheses[counter] != '}')
                || (topOfTheStack == '[' && expressionFromParentheses[counter] != ']'))
            {
                return false;
            }
        }
        counter++;
    }
    if (isEmpty(head))
    {
        return true;
    }
    deleteStack(&head);
    return false;
}
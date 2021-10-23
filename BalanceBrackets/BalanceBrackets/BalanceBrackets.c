#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <stdlib.h>

bool checkCorrectOrderBrackets(char* expressionFromParentheses)
{
    bool check = true;
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
            char k = pop(&head, &check);
            {
                if (!check)
                {
                    return false;
                }
            }
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
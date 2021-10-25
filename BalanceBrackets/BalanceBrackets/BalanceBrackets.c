#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"
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
            int error = 0;
            char topOfTheStack = pop(&head, &error);
            {
                if (error == 1)
                {
                    return false;
                }
            }
            if ((topOfTheStack != '(' && expressionFromParentheses[counter] == ')')
                || (topOfTheStack != '{' && expressionFromParentheses[counter] == '}')
                || (topOfTheStack != '[' && expressionFromParentheses[counter] == ']'))
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
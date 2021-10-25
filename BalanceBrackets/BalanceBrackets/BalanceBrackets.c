#include "BalanceBrackets.h"
#include "../../Stack/Stack/Stack.h"

bool isOpeningBracket(char parentheses)
{
    return parentheses == '(' || parentheses == '{' || parentheses == '[';
}

bool isClosingBracket(char paretheses)
{
    return paretheses == ')' || paretheses == '}' || paretheses == ']';
}

bool openingAndClosingOfTheSameType(char openingParetheses, char closingParetheses)
{
    return openingParetheses != '(' && closingParetheses == ')'
        || openingParetheses != '{' && closingParetheses == '}'
        || openingParetheses != '[' && closingParetheses == ']';
}

bool checkCorrectOrderBrackets(const char* expressionFromParentheses, int* errorCode)
{
    Stack* head = createStack();
    int counter = 0;
    while (expressionFromParentheses[counter] != '\0')
    {
        if (isOpeningBracket(expressionFromParentheses[counter]))
        {
            int error = 0;
            push(&head, expressionFromParentheses[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
                deleteStack(&head);
                return false;
            }
        }
        else if (isClosingBracket(expressionFromParentheses[counter]))
        {
            int error = 0;
            char topOfTheStack = (char)pop(&head, &error);
            if (error == 1)
            {
                *errorCode = 1;
                deleteStack(&head);
                return false;
            }
            if (openingAndClosingOfTheSameType(topOfTheStack, expressionFromParentheses[counter]))
            {
                *errorCode = 1;
                deleteStack(&head);
                return false;
            }
        }
        counter++;
    }
    if (isEmpty(head))
    {
        *errorCode = 0;
        deleteStack(&head);
        return true;
    }
    *errorCode = 1;
    deleteStack(&head);
    return false;
}
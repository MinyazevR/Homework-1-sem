#include "../../Stack/Stack/Stack.h"
#include "Postfix.h"
#include <stdlib.h>
#include <errno.h>

float countTheExpression(char* postfixEntry)
{
    Stack* head = NULL;
    int counter = 0; 
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= '0' && postfixEntry[counter] <= '9')
        {
            push(&head, (float)postfixEntry[counter] - '0');
            counter++;
            continue;
        }
        else if (postfixEntry[counter] == ' ')
        {
            counter++;
            continue;
        }
        float secondNumber = pop(&head);
        if (errno == 1)
        {
            return 0;
        }
        float firstNumber = pop(&head);
        if (errno == 1)
        {
            return 0; 
        }
        if (postfixEntry[counter] == '-')
        {
            push(&head, (firstNumber - secondNumber));
        }
        else if (postfixEntry[counter] == '+')
        {
            push(&head, firstNumber + secondNumber);
        }
        else if (postfixEntry[counter] == '*')
        {
            push(&head, firstNumber * secondNumber);
        }
        else if (postfixEntry[counter] == '/') 
        {
            push(&head, firstNumber / secondNumber);
        }
        else
        {
            deleteStack(&head);
            errno = 2;
            return 0;
        }     
        counter++;
    }
    const float answer = pop(&head);
    if (errno == 1)
    {
        return 0;
    }
    if (!isEmpty(head))
    {
        deleteStack(&head);
        errno = 3;
        return 0;
    }
    return answer;
}
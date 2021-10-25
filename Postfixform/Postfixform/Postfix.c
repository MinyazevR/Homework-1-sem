#include "../../Stack/Stack/Stack.h"
#include "Postfix.h"
#include <stdlib.h>

float countTheExpression(char* postfixEntry, int* errorCode)
{
    Stack* head = NULL;
    int counter = 0; 
    int error = 0;
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
        float secondNumber = pop(&head, &error);
        if (error == 1)
        {
            *errorCode = error;
            return 0;
        }
        float firstNumber = pop(&head, &error);
        if (error == 1)
        {
            *errorCode = error;
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
            if (secondNumber == 0)
            {
                *errorCode = 3;
                return 0;
            }
            push(&head, firstNumber / secondNumber);
        }
        else
        {
            deleteStack(&head);
            *errorCode = 2;
            return 0;
        }     
        counter++;
    }
    const float answer = pop(&head, &error);
    if (error == 1)
    {
        *errorCode = error;
        return 0;
    }
    if (!isEmpty(head))
    {
        deleteStack(&head);
        *errorCode = 1;
        return 0;
    }
    return answer;
}
#include "../../Stack/Stack/Stack.h"
#include "Postfix.h"
#include <stdlib.h>

int countTheExpression(char* postfixEntry)
{
    Stack* head = NULL;
    int counter = 0; 
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= '0' && postfixEntry[counter] <= '9')
        {
            push(&head, postfixEntry[counter] - '0');
            counter++;
            continue;
        }
        else if (postfixEntry[counter] == ' ')
        {
            counter++;
            continue;
        }
        int secondNumber = pop(&head);
        if (errno == 1)
        {
            return 0;
        }
        int firstNumber = pop(&head);
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
    const int answer = pop(&head);
    if (errno == 1)
    {
        return 0;
    }
    if (!isEmpty(head))
    {
        errno = 3;
        return 0;
    }
    deleteStack(&head);
    return answer;
}
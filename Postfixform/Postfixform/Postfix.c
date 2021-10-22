#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include "Postfix.h"
#include <stdlib.h>
#include <stdbool.h>

int countTheExpression(char* postfixEntry, bool* check)
{
    bool copy = *check;
    Stack* head = NULL;
    int counter = 0; 
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= '0' && postfixEntry[counter] <= '9')
        {
            push(&head, (postfixEntry[counter] - '0'));
            counter++;
            continue;
        }
        else if (postfixEntry[counter] == ' ')
        {
            counter++;
            continue;
        }
        int secondNumber = 0;
        int firstNumber = 0;
        secondNumber = pop(&head, &copy);
        if (copy == false)
        {
            *check = false;
            return 0;
        }
        firstNumber = pop(&head, &copy);
        if (copy == false)
        {
            *check = false;
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
            *check = false;
            return 0;
        }     
        counter++;
    }
    const int answer = pop(&head, &copy);
    if (!isEmpty(head))
    {
        *check = false;
        return 0;
    }
    deleteStack(&head);
    return answer;
}
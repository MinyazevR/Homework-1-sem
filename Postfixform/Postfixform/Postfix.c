#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

int asdasd(char* postfixEntry)
{
    Stack* head = NULL;
    int counter = 0;
    int firstNumber = 0;
    int secondNumber = 0;
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= '0' && postfixEntry[counter] <= '9')
        {
            push(&head, postfixEntry[counter]);
        }
        if (postfixEntry[counter] = '-')
        {
            secondNumber = pop(&head);
            firstNumber = pop(&head);
            push(&head, firstNumber - secondNumber);     
        }
        if (postfixEntry[counter] = '+')
        {
            secondNumber = pop(&head);
            firstNumber = pop(&head);
            push(&head, firstNumber + secondNumber);
        }
        if (postfixEntry[counter] = '*')
        {
            secondNumber = pop(&head);
            firstNumber = pop(&head);
            push(&head, firstNumber * secondNumber);
        }
        if (postfixEntry[counter] = '/')
        {
            secondNumber = pop(&head);
            firstNumber = pop(&head);
            push(&head, firstNumber / secondNumber);
        }
    }
    int answer = head -> value;
    return answer;
}

int main()
{
    char postfixEntry[250] = {'\0'};
    printf("enter the expression in postfix form");
    gets(postfixEntry);
    int answer = asdasd(postfixEntry);
    printf("%d", answer);
}
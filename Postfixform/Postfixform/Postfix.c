#include "Stack.h"
#include "StackTest.h"
#include "postfixFormTest.h"
#include <stdio.h>
#include <stdlib.h>

int convertFromThePostfixForm(char* postfixEntry)
{
    Stack* head = NULL;
    int counter = 0;
    int firstNumber = 0;
    int secondNumber = 0;
    
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= (int)('0') && postfixEntry[counter] <= (int)('9'))
        {
            push(&head, (postfixEntry[counter] - '0'));
        }
        else
        {
            if(!isEmpty(head))
            {
                secondNumber = pop(&head);
            }
            else 
            {
                return INT_MAX;
            }
            if (!isEmpty(head))
            {
                firstNumber = pop(&head);
            }
            else
            {
                return INT_MAX;
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
                return INT_MAX;
            }
        }
        counter++;
    }
    int answer = pop(&head);
    deleteStack(&head);
    return answer;
}

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest() || !postfixFormTest())
    {
        printf("Test failed");
        return -1;
    }
    char postfixEntry[250] = {'\0'};
    printf("enter the expression in postfix form\n");
    scanf_s("%s", postfixEntry, (unsigned)_countof(postfixEntry));
    int answer = convertFromThePostfixForm(postfixEntry);
    if (answer == INT_MAX)
    {
        printf("Incorrect input");
        return 0;
    }
    printf("%d", answer);
}
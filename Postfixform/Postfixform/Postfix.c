#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include "postfixFormTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int convertFromThePostfixForm(char* postfixEntry, bool* check)
{
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
        if (!isEmpty(head))
        {
            secondNumber = pop(&head);
        }
        else 
        {
            *check = false;
            return 0;
        }
        if (!isEmpty(head))
        {
            firstNumber = pop(&head);
        }
        else
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
    const int answer = pop(&head);
    if (!isEmpty(head))
    {
        *check = false;
        return 0;
    }
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
    scanf_s("%[^\n]s", postfixEntry, (unsigned)_countof(postfixEntry));
    bool check = true;
    const int answer = convertFromThePostfixForm(postfixEntry, &check);
    if (!check)
    {
        printf("Incorrect input");
        return 0;
    }
    printf("%d", answer);
}
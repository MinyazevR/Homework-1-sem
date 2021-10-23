#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <errno.h>

char* translationIntoPostfixForm(char* array)
{
    Stack* head = NULL;
    int counterForTheOutputArray = 0;
    int counter = 0;
    char* arrayToOutput = (char*)malloc(1000 * sizeof(char));
    if (arrayToOutput == NULL)
    {
        errno = 2;
        return NULL;
    }
    while (array[counter] != '\0')
    {
        if (array[counter] >= '0' && array[counter] <= '9')
        {
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
        }
        else if (array[counter] == ' ')
        {
            counter++;
            continue;
        }
        else if (array[counter] == '-' || array[counter] == '+'
                 || array[counter] == '/' || array[counter] == '*')
        {
            while (!isEmpty(head) && top(&head) == '*' || top(&head) == '/')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head);
                if (errno == 1)
                {
                    return NULL;
                }
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }
        else if (array[counter] == '(')
        {
            push(&head, array[counter]);
        }
        else if (array[counter] == ')')
        {
            while (top(&head) != '(')
            {
                if(!isEmpty(head))
                {
                    arrayToOutput[counterForTheOutputArray] = pop(&head);
                    if (errno == 1)
                    {
                        return NULL;
                    }
                    counterForTheOutputArray++;
                }
                if (isEmpty(head))
                {
                    errno = 3;
                    return 0;
                }
            }
            if ((!isEmpty(head)) && top(&head) == '(')
            {
                pop(&head);
                if (errno == 1)
                {
                    return NULL;
                }
            }
        }
        else
        {
            errno = 3;
            return NULL;
        }
        counter++;
    }
    while (!isEmpty(head))
    {
        if (top(&head) == '(')
        {
            errno = 3;
            return NULL;
        }
        arrayToOutput[counterForTheOutputArray] = pop(&head);
        if (errno == 1)
        {
            return NULL;
        }
        counterForTheOutputArray++;
    }
    arrayToOutput[counterForTheOutputArray] = '\0';
    return arrayToOutput;
}
#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <errno.h>

char* translationIntoPostfixForm(const char* array, int* errorCode)
{
    Stack* head = NULL;
    int counterForTheOutputArray = 0;
    int counter = 0;
    int error = 0 ;
    char* arrayToOutput = (char*)malloc(1000 * sizeof(char));
    if (arrayToOutput == NULL)
    {
        *errorCode = 2;
        return NULL;
    }
    while (array[counter] != '\0')
    {
        if (array[counter] == ' ')
        {
            if (array[counter - 1] == ' ')
            {
                deleteStack(&head);
                *errorCode = 4;
                return NULL;
            }
            if (arrayToOutput[counterForTheOutputArray - 1] == ' ')
            {
                counter++;
                continue;
            }
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
            counter++;
            continue;
        }
        if (array[counter] >= '0' && array[counter] <= '9')
        {
            if (array[counter + 1] == '*' || array[counter + 1] == '/' || array[counter + 1] == '(' || array[counter + 1] == '+' || array[counter + 1] == '-')
            {
                deleteStack(&head);
                *errorCode = 4;
                return NULL;
            }
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
            counter++;
            continue;
        }
        else if (array[counter] == '-' || array[counter] == '+' || array[counter] == '/' || array[counter] == '*')
        {
            if (array[counter + 1] != ' ')
            {
                deleteStack(&head);
                *errorCode = 4;
                return NULL;
            }
            while (!isEmpty(head) && top(&head, &error) == '*' || top(&head, &error) == '/')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
                if (error == 1)
                {
                    *errorCode = 1;
                    return NULL;
                }
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }
        else if (array[counter] == '(')
        {
            if (array[counter + 1] == ' ')
            {
                deleteStack(&head);
                *errorCode = 4;
                return NULL;
            }
            push(&head, array[counter]);
        }
        else if (array[counter] == ')')
        {
            if (array[counter - 1] == ' ')
            {
                deleteStack(&head);
                *errorCode = 4;
                return NULL;
            }
            while (top(&head, &error) != '(')
            {
                if(!isEmpty(head))
                {
                    arrayToOutput[counterForTheOutputArray] = ' ';
                    counterForTheOutputArray++;
                    arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
                    if (error == 1)
                    {
                        *errorCode = 1;
                        return NULL;
                    }
                    counterForTheOutputArray++;
                }
                if (isEmpty(head))
                {
                    *errorCode = 3;
                    return 0;
                }
            }
            if ((!isEmpty(head)) && top(&head, &error) == '(')
            {
                pop(&head, &error);
                if (error == 1)
                {
                    *errorCode = 1;
                    return NULL;
                }
            }
        }
        else
        {
            deleteStack(&head);
            *errorCode = 3;
            return NULL;
        }
        counter++;
    }
    while (!isEmpty(head))
    {
        if (top(&head, &error) == '(')
        {
            deleteStack(&head);
            *errorCode = 3;
            return NULL;
        }
        arrayToOutput[counterForTheOutputArray] = ' ';
        counterForTheOutputArray++;
        arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
        if (error == 1)
        {
            *errorCode = 1;
            return NULL;
        }
        counterForTheOutputArray++;
    }
    arrayToOutput[counterForTheOutputArray] = '\0';
    return arrayToOutput;
}
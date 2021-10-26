#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <errno.h>

bool isRepeatTheOperation(char operation)
{
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}

bool isPriorityForDivisionandMultiplication(char operation)
{
    return operation == '*' || operation == '/';
}

bool isPriorityForMinusAndPlus(char operation)
{
    return isPriorityForDivisionandMultiplication(operation) || operation == '-' || operation == '+';
}

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
        if (array[counter] >= '0' && array[counter] <= '9')
        {
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
            arrayToOutput[counterForTheOutputArray] = ' ';
            counterForTheOutputArray++;
            counter++;
            continue;
        }
        else if (array[counter] == '-' || array[counter] == '+')
        {
            if (isRepeatTheOperation(array[counter + 1]) || isRepeatTheOperation(array[counter + 2]))
            {
                *errorCode = 1;
                return NULL;
            }
            while (!isEmpty(head) && isPriorityForMinusAndPlus((char)top(&head, &error)))
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
                if (error == 1)
                {
                    *errorCode = 1;
                    return NULL;
                }
                counterForTheOutputArray++;
                arrayToOutput[counterForTheOutputArray] = ' ';
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }
        else if (array[counter] == '/' || array[counter] == '*')
        {
            if (isRepeatTheOperation(array[counter + 1]) || isRepeatTheOperation(array[counter + 2]))
            {
                *errorCode = 1;
                return NULL;
            }

            while (!isEmpty(head) && isPriorityForDivisionandMultiplication((char)top(&head, &error)))
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
                if (error == 1)
                {
                    *errorCode = 1;
                    return NULL;
                }
                counterForTheOutputArray++;
                arrayToOutput[counterForTheOutputArray] = ' ';
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
            while (top(&head, &error) != '(')
            {
                if(!isEmpty(head))
                {   
                    arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
                    if (error == 1)
                    {
                        *errorCode = 1;
                        return NULL;
                    }
                    counterForTheOutputArray++;
                    arrayToOutput[counterForTheOutputArray] = ' ';
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
        else if (array[counter] == ' ')
        {
            counter++;
            continue;
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
        arrayToOutput[counterForTheOutputArray] = pop(&head, &error);
        if (error == 1)
        {
            *errorCode = 1;
            return NULL;
        }
        counterForTheOutputArray++;
        arrayToOutput[counterForTheOutputArray] = ' ';
        counterForTheOutputArray++;
    }
    arrayToOutput[counterForTheOutputArray - 1] = '\0';
    return arrayToOutput;
}
#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

bool isSecondOperationInRow(char operation)
{
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}

bool isDivisionAndMultiplication(char operation)
{
    return operation == '*' || operation == '/';
}

bool isPriorityForMinusAndPlus(char operation)
{
    return isDivisionAndMultiplication(operation) || operation == '-' || operation == '+';
}

void writeCharacterToArrayToOutput(char* arrayToOutput, char character, int* counterForTheOutputArray)
{
    arrayToOutput[*counterForTheOutputArray] = character;
    (*counterForTheOutputArray)++;
    arrayToOutput[*counterForTheOutputArray] = ' ';
    (*counterForTheOutputArray)++;
}

char* translationIntoPostfixForm(const char* array, int* errorCode)
{
    Stack* head = createStack();
    char* arrayToOutput = (char*)calloc((2 * strlen(array) + 1), sizeof(char));
    int counterForTheOutputArray = 0;
    int counter = 0;
    int error = 0;
    if (arrayToOutput == NULL)
    {
        *errorCode = 2;
        deleteStack(&head);
        return NULL;
    }
    while (array[counter] != '\0')
    {
        if (array[counter] >= '0' && array[counter] <= '9')
        {
            writeCharacterToArrayToOutput(arrayToOutput, array[counter], &counterForTheOutputArray);
            counter++;
            continue;
        }
        else if (array[counter] == '-' || array[counter] == '+')
        {
            if (isSecondOperationInRow(array[counter + 1]))
            {
                *errorCode = 1;
                free(arrayToOutput);
                deleteStack(&head);
                return NULL;
            }
            while (!isEmpty(head) && isPriorityForMinusAndPlus((char)top(&head, &error)))
            {
                writeCharacterToArrayToOutput(arrayToOutput, (char)pop(&head, &error), &counterForTheOutputArray);
                if (error == 1)
                {
                    free(arrayToOutput);
                    deleteStack(&head);
                    *errorCode = 1;
                    return NULL;
                }
            }
            push(&head, array[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
                free(arrayToOutput);
                deleteStack(&head);
                return NULL;
            }
        }
        else if (array[counter] == '/' || array[counter] == '*')
        {
            if (isSecondOperationInRow(array[counter + 1]))
            {
                deleteStack(&head);
                free(arrayToOutput);
                *errorCode = 1;
                return NULL;
            }
            while (!isEmpty(head) && isDivisionAndMultiplication((char)top(&head, &error)))
            {
                writeCharacterToArrayToOutput(arrayToOutput, (char)pop(&head, &error), &counterForTheOutputArray);
                if (error == 1)
                {
                    deleteStack(&head);
                    free(arrayToOutput);
                    *errorCode = 1;
                    return NULL;
                }
            }
            push(&head, array[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
                free(arrayToOutput);
                deleteStack(&head);
                return NULL;
            }
        }
        else if (array[counter] == '(')
        {
            push(&head, array[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
                free(arrayToOutput);
                deleteStack(&head);
                return NULL;
            }
        }
        else if (array[counter] == ')')
        {
            while (top(&head, &error) != '(')
            {
                if (!isEmpty(head))
                {   
                    writeCharacterToArrayToOutput(arrayToOutput, (char)pop(&head, &error), &counterForTheOutputArray);
                    if (error == 1)
                    {
                        deleteStack(&head);
                        free(arrayToOutput);
                        *errorCode = 1;
                        return NULL;
                    }
                }
                if (isEmpty(head))
                {
                    deleteStack(&head);
                    free(arrayToOutput);
                    *errorCode = 3;
                    return 0;
                }
            }
            if ((!isEmpty(head)) && top(&head, &error) == '(')
            {
                pop(&head, &error);
                if (error == 1)
                {
                    deleteStack(&head);
                    free(arrayToOutput);
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
            free(arrayToOutput);
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
            free(arrayToOutput);
            *errorCode = 3;
            return NULL;
        }
        writeCharacterToArrayToOutput(arrayToOutput, (char)pop(&head, &error), &counterForTheOutputArray);
        if (error == 1)
        {
            deleteStack(&head);
            free(arrayToOutput);
            *errorCode = 1;
            return NULL;
        }
    }
    arrayToOutput[counterForTheOutputArray - 1] = '\0';
    deleteStack(&head);
    return arrayToOutput;
}
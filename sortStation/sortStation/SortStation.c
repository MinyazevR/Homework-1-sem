#include "../../Stack/Stack/Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

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

void addSpace(char* symbol)
{
    *symbol = ' ';
}

char* translationIntoPostfixForm(const char* array, int* errorCode)
{
    Stack* head = createStack();
    int counterForTheOutputArray = 0;
    int counter = 0;
    int error = 0;
    char* arrayToOutput = (char*)calloc((2 * strlen(array) + 1), sizeof(char));
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
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
            addSpace(&arrayToOutput[counterForTheOutputArray++]);
            counter++;
            continue;
        }
        else if (array[counter] == '-' || array[counter] == '+')
        {
            if (isRepeatTheOperation(array[counter + 1]) || isRepeatTheOperation(array[counter + 2]))
            {
                *errorCode = 1;
                deleteStack(&head);
                return NULL;
            }
            while (!isEmpty(head) && isPriorityForMinusAndPlus((char)top(&head, &error)))
            {
                arrayToOutput[counterForTheOutputArray] = (char)pop(&head, &error);
                if (error == 1)
                {
                    deleteStack(&head);
                    *errorCode = 1;
                    return NULL;
                }
                counterForTheOutputArray++;
                addSpace(&arrayToOutput[counterForTheOutputArray++]);
            }
            push(&head, array[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
                deleteStack(&head);
                return NULL;
            }
        }
        else if (array[counter] == '/' || array[counter] == '*')
        {
            if (isRepeatTheOperation(array[counter + 1]) || isRepeatTheOperation(array[counter + 2]))
            {
                deleteStack(&head);
                *errorCode = 1;
                return NULL;
            }

            while (!isEmpty(head) && isPriorityForDivisionandMultiplication((char)top(&head, &error)))
            {
                arrayToOutput[counterForTheOutputArray] = (char)pop(&head, &error);
                if (error == 1)
                {
                    deleteStack(&head);
                    *errorCode = 1;
                    return NULL;
                }
                counterForTheOutputArray++;
                addSpace(&arrayToOutput[counterForTheOutputArray++]);
            }
            push(&head, array[counter], &error);
            if (error == 2)
            {
                *errorCode = 2;
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
                deleteStack(&head);
                return NULL;
            }
        }
        else if (array[counter] == ')')
        {
            while (top(&head, &error) != '(')
            {
                if(!isEmpty(head))
                {   
                    arrayToOutput[counterForTheOutputArray] = (char)pop(&head, &error);
                    if (error == 1)
                    {
                        deleteStack(&head);
                        *errorCode = 1;
                        return NULL;
                    }
                    counterForTheOutputArray++;
                    addSpace(&arrayToOutput[counterForTheOutputArray++]);
                }
                if (isEmpty(head))
                {
                    deleteStack(&head);
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
        arrayToOutput[counterForTheOutputArray] = (char)pop(&head, &error);
        if (error == 1)
        {
            deleteStack(&head);
            *errorCode = 1;
            return NULL;
        }
        counterForTheOutputArray++;
        addSpace(&arrayToOutput[counterForTheOutputArray++]);
    }
    arrayToOutput[counterForTheOutputArray - 1] = '\0';
    deleteStack(&head);
    return arrayToOutput;
}
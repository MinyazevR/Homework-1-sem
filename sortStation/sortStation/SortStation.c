#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include <stdio.h>
#include <malloc.h>

char* sortStation(char* array, bool* check)
{
    bool err = *check;
    Stack* head = NULL;
    int counterForTheOutputArray = 0;
    int counter = 0;
    char* arrayToOutput = (char*)malloc(1000 * sizeof(char));
    if (arrayToOutput == NULL)
    {
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
        else if (array[counter] == '-' || array[counter] == '+')
        {
            while (!isEmpty(head) && top(&head, &err) == '*' || top(&head, &err) == '/')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &err);
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }
        else if (array[counter] == '/' || array[counter] == '*')
        {
            while (!isEmpty(head) && top(&head, &err) == '*' || top(&head, &err) == '/')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &err);
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
            while ((!isEmpty(head)) && top(&head, &err) != '(')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &err);
                counterForTheOutputArray++;
                if (!err)
                {
                    *check = false;
                    return NULL;
                }
            }
            if ((!isEmpty(head)) && top(&head, &err) == '(')
            {
                pop(&head, &err);
            }
            else
            {
                *check = false;
                return NULL;
            }
        }
        else
        {
            *check = false;
            return NULL;
        }
        counter++;
    }
    while (!isEmpty(head))
    {
        if (top(&head, &err) == '(')
        {
            *check = false;
            return NULL;
        }
        arrayToOutput[counterForTheOutputArray] = pop(&head, &err);
        counterForTheOutputArray++;
    }
    arrayToOutput[counterForTheOutputArray] = '\0';
    return arrayToOutput;
}

int main()
{
    char array[1000] = {'\0'};
    printf("aa\n");
    bool check = true;
    scanf("%s", array);
    char* arrayToOutput = sortStation(array, &check);
    {
        if (!check)
        {
            return -1;
        }
    }
    int counter = 0;
    while (arrayToOutput[counter] != '\0')
    {
        printf("%c ", arrayToOutput[counter]);
        counter++;
    }
}
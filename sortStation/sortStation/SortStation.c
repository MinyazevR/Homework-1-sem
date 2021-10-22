#include "../../Stack/Stack/Stack.h"
#include "../../Stack/Stack/StackTest.h"
#include <stdio.h>
#include <malloc.h>

char* sortStation(char* array)
{
    Stack* head = NULL;
    bool check = true;
    int counterForTheOutputArray = 0;
    int counter = 0;
    char* arrayToOutput = (char*)malloc(1000*sizeof(char));
    while (array[counter] != '\0')
    {
        if (array[counter] >= '0' || array[counter] <= '9')
        {
            arrayToOutput[counterForTheOutputArray] = array[counter];
            counterForTheOutputArray++;
        }
        if (array[counter] == '-' || array[counter] == '+')
        {
            while (!isEmpty(head) && (top(&head, &check) != '*' || top(&head, &check) != '/'))
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &check);
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }      
        if (array[counter] == '(')
        {
            push(&head, array[counter]);
        }
        if (array[counter] == ')')
        {
            while ((!isEmpty) && top(&head, check) != ')')
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &check);
                counterForTheOutputArray;
                if (isEmpty(head))
                {
                    check = false;
                    return NULL;
                }
            }
            pop(&head, &check);
        }
    }
    while (!isEmpty(head))
    {
        if(top(&head, &check) == ')')
        {
            check = false;
            return NULL;
        }
        arrayToOutput[counterForTheOutputArray] = pop(&head, &check);
        counterForTheOutputArray++;
    }
}

int main()
{
    char array[1000] = {'\0'};
    printf("aa\n");
    scanf("%s", array);
    sortStation(array);

}
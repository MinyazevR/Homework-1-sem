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
            while (!isEmpty(head) && (array[counter] != '*' || array[counter] != '/'))
            {
                arrayToOutput[counterForTheOutputArray] = pop(&head, &check);
                counterForTheOutputArray++;
            }
            push(&head, array[counter]);
        }      
    }
    if (array[counter] == '(')
    {
        push(&head, array[counter])
    }
}

int main()
{
    char array[1000] = {'\0'};
    printf("aa\n");
    scanf("%s", array);
    sortStation(array);

}
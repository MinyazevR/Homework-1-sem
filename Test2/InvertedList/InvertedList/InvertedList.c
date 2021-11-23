#include "../../List/List/List.h"
#include <stdbool.h>
#include <malloc.h>

void flipNumbersArray(int numberOfElements, int* arrayOfNumbers)
{
    for (int i = 0; i < numberOfElements / 2; i++)
    {
        const int temporary = arrayOfNumbers[i];
        arrayOfNumbers[i] = arrayOfNumbers[numberOfElements - 1 - i];
        arrayOfNumbers[numberOfElements - 1 - i] = temporary;
    }
}

void invertList(List* list)
{
    List* newList = createList();
    Error error = NOT_ERROR;
    Position* firstPosition = first(list, &error);
    int* arrayOfElements = calloc(returnSize(list) + 1, sizeof(int));
    if (arrayOfElements == NULL)
    {
        return;
    }
    for (int i = 0; i < returnSize(list); i++)
    {
        arrayOfElements[i] = get(list, firstPosition, &error);
        next(firstPosition);
    }
    flipNumbersArray(returnSize(list), arrayOfElements);
    Position* secondPosition = first(list, &error);
    for (int i = 0; i < returnSize(list); i++)
    {
        const int value = arrayOfElements[i];
        replaceValue(secondPosition, value);
        next(secondPosition);
    }
    free(arrayOfElements);
    free(firstPosition);
    free(secondPosition);
}
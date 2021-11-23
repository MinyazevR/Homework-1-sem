#include "TestInvertedList.h"
#include "InvertedList.h"
#include <stdio.h>
#include <stdlib.h>

bool testInvertedList()
{
    FILE* file = fopen("InvertedList.txt", "r");
    if (file == NULL)
    {
        return -2;
    }
    Error error = NOT_ERROR;
    List* list = createList();
    while (!feof(file))
    {
        int temporary = 0;
        const int readBytes = fscanf(file, "%d", &temporary);
        if (readBytes < 0)
        {
            break;
        }
        add(list, temporary, &error);
    }
    fclose(file);
    invertList(list);
    const int array[5] = {10, 40 , 30 , 20};
    Position* secondPosition = first(list, &error);
    for (int i = 0; i < returnSize(list); i++)
    {
        if (array[i] != get(list, secondPosition, &error))
        {
            freePosition(secondPosition);
            free(list);
            return false;
        }
        next(secondPosition);
    }
    freePosition(secondPosition);
    free(list);
    return true;
}
#include "WorkWithFile.h"
#include <stdio.h>
#include "MergeList.h"

List* readFile(const char* filename, int a, int b, int* check)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }
    List* result = createList();
    List* secondList = createList();
    List* thirdList = createList();
    Error error = NOT_ERROR;
    while (!feof(file))
    {
        int temporary = 0;
        const int readBytes = fscanf(file, "%d", &temporary);
        if (readBytes < 0)
        {
            break;
        }
        if (temporary < a)
        {
            add(result, temporary, &error);
        }
        else if (temporary > b)
        {
            add(thirdList, temporary, &error);
        }
        else
        {
            add(secondList, temporary, &error);

        }
    }
    if (error != NOT_ERROR)
    {
        deleteList(result);
        deleteList(thirdList);
        deleteList(secondList);
        *check = 3; 
        return NULL;
    }
    fclose(file);
    result = merge(result, merge(secondList, thirdList, &error), &error);
    return result;
}

int writeFile(const char* fileToWrite, List* list)
{
    FILE* file = fopen(fileToWrite, "w");
    if (file == NULL)
    {
        return -2;
    }
    Error error = NOT_ERROR;
    Position* position = first(list, &error);
    for (int i = 0; i < numberOfElements(list); i++)
    {
        fprintf(file, "%d ", getValue(position));
        next(position);
    }
    deletePosition(position);
    fclose(file);
    return 0;
}
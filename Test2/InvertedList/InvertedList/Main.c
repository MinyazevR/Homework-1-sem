#include <stdio.h>
#include "../../List/List/List.h"
#include "InvertedList.h"
#include "TestInvertedList.h"

int readFile(const char* filename, List* list)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return -2;
    }
    Error error = NOT_ERROR;
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
    return 0;
}

int main()
{
    if (!testInvertedList())
    {
        return -1;
    }
    List* newList = createList();
    deleteList(newList);
    const int readFileResult = readFile("InvertedList.txt", newList);
    if (readFileResult == -2)
    {
        deleteList(newList);
        printf("File not found");
        return -1;
    }
    invertList(newList);
    deleteList(newList);  
}
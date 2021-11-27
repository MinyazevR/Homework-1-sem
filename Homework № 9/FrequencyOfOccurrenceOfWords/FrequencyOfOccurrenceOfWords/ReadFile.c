#include <stdio.h>
#include "ReadFile.h"

int readFile(HashTable* table, const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    while (!feof(file))
    {
        // words in the file are less than 100 characters in size
        char array[100] = { '\0' };
        Error error = NOT_ERROR;
        if (fscanf(file, "%s", array) != EOF);
        {
            addElement(array, table, &error);
            if (error == INSUFFICIENT_MEMORY)
            {
                return -2;
            }
        }
    }
    fclose(file);
    return 0;
}

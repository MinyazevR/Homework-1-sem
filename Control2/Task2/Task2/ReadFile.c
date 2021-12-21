#define _CRT_SECURE_NO_WARNINGS
#include "ReadFile.h"
#include <stdio.h>
#include <string.h>

int readFile(const char* filename, List* list)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return -2;
    }
    Error error = NOT_ERROR;
    char string[100] = { '\0' };
    while (!feof(file))
    {
        const int readBytes = fscanf(file, "%s", string);
        if (readBytes < 0)
        {
            break;
        }
        add(list, string, &error);
    }
    fclose(file);
    return 0;
}
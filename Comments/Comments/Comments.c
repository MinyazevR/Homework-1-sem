#include "Comments.h"
#include "testComments.h"
#include <stdio.h>
#include <malloc.h>

char* readBytes(const char* filename, int* error)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        *error = 1;
        return NULL;
    }
    int counter = 0;
    while (!feof(file))
    {
        char* buffer = (char*)calloc(1, sizeof(char));
        {
            if (buffer == NULL)
            {
                *error = 2;
                return NULL;
            }
        }
        const int readBytes = fscanf(file, "%c", buffer);
        if (readBytes < 0)
        {
            break;
        }
        counter++;
        free(buffer);
    }
    fclose(file);
    file = fopen(filename, "r");
    char* data = calloc(counter, sizeof(char));
    if (data == NULL)
    {
        *error = 2;
        return NULL;
    }
    int linesRead = 0;
    while (!feof(file))
    {
        char* buffer = (char*)calloc(1, sizeof(char));
        {
            if (buffer == NULL)
            {
                *error = 2;
                return NULL;
            }
        }
        const int readBytes = fscanf(file, "%c", buffer);
        if (readBytes < 0)
        {
            break;
        }
        if (*buffer == ';')
        {
            while (*buffer != '\n' && *buffer != '\0' && linesRead <= counter)
            {
                data[linesRead] = *buffer;
                ++linesRead;
                const int readBytes = fscanf(file, "%c", buffer);
                if (readBytes < 0)
                {
                    break;
                }
            }
        }
        free(buffer);
    }
    fclose(file);
    return data;
}
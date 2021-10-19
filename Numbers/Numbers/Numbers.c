#include "Numbers.h"
#include <stdio.h>
#include <malloc.h>

int readNumbersSmallerSelected(int* data, int numberToCompare, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return -2;
    }
    int counter = 0;
    while (!feof(file))
    {
        int* buffer = (int*)malloc(sizeof(int)*100);
        {
            if (buffer == NULL)
            {
                return -1;
            }
        }
        const int readBytes = fscanf(file, "%d", buffer);
        if (readBytes < 0) 
        {
            break;
        }
        if (*buffer < numberToCompare)
        {
            data[counter] = *buffer;
            counter++;
        }
    }
    fclose(file);
    return counter;
}

int outputOfNumbers(int* data, int counter, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("File not found");
        return -2;
    }
    int linesRead = 0;
    for (int i = 0; i < counter; i++)
    {
        fprintf(file, "%d  ", data[i]);
    }
    fclose(file);
    return 0;
}

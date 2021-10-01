#include "dataOutput.h"
#include <stdio.h>

int dataOutput(FILE* file, int* arrayOfNumber)
{
    errno_t err;
    err = fopen_s(&file, "qwerty.txt", "r");
    if (file == NULL || err == 1)
    {
        printf("file not found!");
        return -1;
    }
    int counter = 0;
    int buffer = 0;
    while (!feof(file)) 
    {
        const int readBytes = fscanf_s(file, "%d", &buffer);
        if (readBytes < 0) 
        {
            break;
        }
        arrayOfNumber[counter] = buffer;
        counter++;
    }
    fclose(file);
    return 0;
}
#include <stdio.h>
#include "dataInput.h"
#include <stdlib.h>

int dataInput(FILE* file)
{
    errno_t err;
    err = fopen_s(&file, "qwerty.txt", "w");
    if (file == NULL || err == 1)
    {
        printf("file not found!");
        return -1;
    }
    // "round() + 1" in case rand() returns 0
    const int numberOfElements = rand() + 1;
    for (int i = 0; i < numberOfElements; i++)
    {
        const int temporaryVariable = (rand() % 11);
        fprintf(file, "%d ", temporaryVariable);
    }
    fclose(file);
    return numberOfElements;
}
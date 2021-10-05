#include "test.h"
#include "repeatingElements.h"
#include <stdio.h>
#include <stdlib.h>

bool checkArray(char* array, int counter)
{
    for (int i = 0; i < counter - 1; i++)
    {
        if (array[i] == array[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool checkRepeatingElements()
{
    FILE* secondFile = NULL;
    errno_t err;
    err = fopen_s(&secondFile, "qwert.txt", "r");
    if (secondFile == NULL || err == 1)
    {
        printf("file not found!");
        return -1;
    }
    fileInput(secondFile);
    return true;  
}
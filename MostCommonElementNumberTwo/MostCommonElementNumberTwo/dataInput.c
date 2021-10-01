#include <stdio.h>
#include <stdlib.h>
#include "dataInput.h"

int dataInput(FILE *file)
{
    errno_t err;
    err = fopen_s(&file, "qwerty.txt", "w");
    if (file == NULL || err == 1) 
    {
        printf("file not found!");
        return -1;
    }
    for (int i = 0; i < 150000; i++)
    {
        int k = rand();
        fprintf(file, "%d ", k);
    }
    fclose(file);
    return 0;
}
#include <malloc.h>
#include <string.h>
#include <stdio.h>

char* readString(int* error)
{
    int index = 0;
    int size = 100;
    char* array = calloc(size, sizeof(char));
    if (array == NULL)
    {
        *error = 1;
        return NULL;
    }
    char symbol = getchar();
    while (symbol != '\n')
    {
        array[index] = symbol;
        if (strlen(array) == size)
        {
            size = size * 2;
            char* temporary = realloc(array, size * sizeof(char));
            if (temporary == NULL)
            {
                *error = 1;
                free(array);
                return NULL;
            }
            array = temporary;
        }
        symbol = getchar();
        index++;
    }
    array[index] = '\0';
    return array;
}
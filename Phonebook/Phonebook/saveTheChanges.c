#include <stdio.h>
#include "saveTheChanges.h"

int saveTheChanges(Phonebook* array, int numberOfRecords)
{
    FILE* file = fopen("qwerty.txt", "w");
    if (file == NULL)
    {
        return -1;
    }
    for (int i = 0; i <= numberOfRecords; i++)
    {
        if (i != 0)
        {
            fprintf(file, "\n");
        }
        fprintf(file, "%s %s", array[i].name, array[i].number);
    }
    fclose(file);
    return 0;
}
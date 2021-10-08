#include "outputAllEntries.h"
#include <stdio.h>

int outputAllEntries(Phonebook* array, int numberOfRecords)
{
    for (int i = 0; i <= numberOfRecords; i++)
    {
        printf("%s %s\n", array[i].name, array[i].number);
    }
    return 0;
}
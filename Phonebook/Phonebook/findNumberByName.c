#include "srtuct.h"
#include <stdio.h>
#include "findNumberByName.h"
#include <string.h>

char* findNumberByName(Phonebook* array, char* name, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (strcmp(array[i].name, name) == 0)
        {
            return array[i].number;
        }
    }
    printf("Такого имени нет");
    return NULL;
}
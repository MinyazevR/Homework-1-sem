#include "srtuct.h"
#include <stdio.h>
#include "findNameByNumber.h"
#include <string.h>

char* findNameByNumber(Phonebook* array, char* number, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (strcmp(array[i].number, number) == 0)
        {
            return array[i].name;
        }
    }
    printf("Такого номера нет");
    return NULL;
}
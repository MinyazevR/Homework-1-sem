#include "srtuct.h"
#include <stdio.h>
#include "readCounter.h"

int recordCounter(Phonebook* array)
{
    FILE* file = fopen("qwerty.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    int numberOfRecords = 0;
    while (!feof(file))
    {
        if (fscanf(file, "%s", array[numberOfRecords].name) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", &array[numberOfRecords].number);
            if (fscanfResult == 0)
            {
                break;
            }
            numberOfRecords++;
        }
    }
    fclose(file);
    return numberOfRecords;
}
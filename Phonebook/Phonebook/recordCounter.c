#include "srtuct.h"
#include <stdio.h>
#include "recordCounter.h"

int recordCounter(Phonebook* array, const char *fileName)
{
    FILE* file = fopen(fileName, "r");
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
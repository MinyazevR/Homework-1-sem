#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include "phoneBook.h"
#include <string.h>
#include <stdio.h>

bool testFunctionsWorkingWithFile()
{
    Phonebook arrayForTest[4] = {'\0'};
    FILE* file = fopen("test1.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    for (int i = 0; i < 4; i++)
    {
        if (fscanf(file, "%s", arrayForTest[i].name) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", &arrayForTest[i].number);
            if (fscanfResult == 0)
            {
                break;
            }
        }
    }
    fclose(file);

    return strcmp("Alex", findNameByNumber(arrayForTest, "5642345", 4)) == 0
        && strcmp("John", findNameByNumber(arrayForTest, "5432356", 4)) == 0
        && strcmp("James", findNameByNumber(arrayForTest, "90812345", 4)) == 0
        && strcmp("5642345", findNumberByName(arrayForTest, "Alex", 4)) == 0
        && strcmp("5432356", findNumberByName(arrayForTest, "John", 4)) == 0
        && strcmp("90812345", findNumberByName(arrayForTest, "James", 4)) == 0
        && readPhonebook(arrayForTest, "test1.txt") == 3;
}

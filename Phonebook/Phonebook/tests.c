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
    char firstName[5] = "Alex";
    char firstNumber[8] = "5642345";
    char secondName[5] = "John";
    char secondNumber[8] = "5432356";
    char thirdName[6] = "James";
    char thirdNumber[9] = "90812345";

    return strcmp(firstName, findNameByNumber(arrayForTest, firstNumber, 4)) == 0
        && strcmp(secondName, findNameByNumber(arrayForTest, secondNumber, 4)) == 0
        && strcmp(thirdName, findNameByNumber(arrayForTest, thirdNumber, 4)) == 0
        && strcmp(firstNumber, findNumberByName(arrayForTest, firstName, 4)) == 0
        && strcmp(secondNumber, findNumberByName(arrayForTest, secondName, 4)) == 0
        && strcmp(thirdNumber, findNumberByName(arrayForTest, thirdName, 4)) == 0
        // The return value is 3 since the count starts from 0 (actually there are 4 records)
        && recordsCounter(arrayForTest, "test1.txt") == 3;
}

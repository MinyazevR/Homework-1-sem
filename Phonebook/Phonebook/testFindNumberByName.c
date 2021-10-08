#include "testFindNumberbyName.h"
#include <stdio.h>
#include "findNumberByName.h"
#include "srtuct.h"
#include <string.h>

bool testFindNumberByName()
{
    Phonebook arrayForTestFindNameByNumber[4] = { '\0' };
    FILE* file = fopen("test1.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    for (int i = 0; i < 4; i++)
    {
        if (fscanf(file, "%s", &arrayForTestFindNameByNumber[i].name) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", &arrayForTestFindNameByNumber[i].number);
            if (fscanfResult == 0)
            {
                break;
            }
        }
    }
    fclose(file);
    char firstName[5] = "Alex";
    char firstNumber[8] = "5642345";
    char secondName[8] = "John";
    char secondNumber[8] = "5432356";
    char thirdName[6] = "James";
    char thirdNumber[9] = "90812345";
    return strcmp(firstNumber, findNumberByName(arrayForTestFindNameByNumber, firstName, 4)) == 0
        && strcmp(secondNumber, findNumberByName(arrayForTestFindNameByNumber, secondName, 4)) == 0
        && strcmp(thirdNumber, findNumberByName(arrayForTestFindNameByNumber, thirdName, 4)) == 0;
}
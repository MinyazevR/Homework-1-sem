#include "testFindNamebyNumber.h"
#include <stdio.h>
#include "findNameByNumber.h"
#include <string.h>
#include <locale.h>

bool testFindNameByNumber()
{
    setlocale(LC_ALL, "rus");
    Phonebook arrayForTestFindNameByNumber[4] = {'\0'};
    FILE* file = fopen("test1.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    for(int i = 0; i < 4; i++)
    {
        if (fscanf(file, "%s", arrayForTestFindNameByNumber[i].name) != EOF);
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
    return findNameByNumber(arrayForTestFindNameByNumber, firstNumber, 4);
    return strcmp(firstName, findNameByNumber(arrayForTestFindNameByNumber, firstNumber, 4)) == 0
        && strcmp(secondName, findNameByNumber(arrayForTestFindNameByNumber, secondNumber, 4)) == 0
        && strcmp(thirdName, findNameByNumber(arrayForTestFindNameByNumber, thirdNumber, 4)) == 0;  
}

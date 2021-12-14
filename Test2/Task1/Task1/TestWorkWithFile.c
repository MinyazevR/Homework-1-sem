#include "TestWorkWithFile.h"
#include "WorkWithFile.h"
#include "../../List/List/List.h"

bool testWorkWithFile()
{
    Error error = NOT_ERROR;
    int check = 0;
    List* list = readFile("Test.txt", 5, 569, &check);
    if (check != 0)
    {
        return false;
    }
    List* firstList = createList();
    add(firstList, 2, &error);
    add(firstList, 3, &error);
    add(firstList, 3, &error);
    add(firstList, -12, &error);
    add(firstList, 6, &error);
    add(firstList, 97, &error);
    add(firstList, 23, &error);
    add(firstList, 12, &error);
    add(firstList, 23, &error);
    add(firstList, 76, &error);
    add(firstList, 123, &error);
    add(firstList, 1143, &error);
    add(firstList, 908, &error);
    add(firstList, 570, &error);
    if (error != NOT_ERROR)
    {
        deleteList(firstList);
        deleteList(list);
        return false;
    }
    bool result = compareList(firstList, list);
    deleteList(firstList);
    deleteList(list);
    return result;
}
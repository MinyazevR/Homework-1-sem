#include "TestMergeSort.h"
#include "MergeSort.h"
#include "List.h"
#include <string.h>

bool testMergeSort()
{
    List* newFirstList = createList();
    int error = 0;
    add(newFirstList, "Pavel", "890345", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, "Alex", "765494", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, "Artem", "956469", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, "Ruslan", "2342424", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    List* newSecondList = createList();
    add(newSecondList, "Alex", "765494", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, "Artem", "956469", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, "Pavel", "890345", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, "Ruslan", "2342424", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    List* firstList = mergeSort(newFirstList, 1, &error);
    print(firstList);
    print(newSecondList);
    bool result = compareList(firstList, newSecondList);
    deleteList(newFirstList);
    deleteList(newSecondList);
    deleteList(firstList);
    return result;
}
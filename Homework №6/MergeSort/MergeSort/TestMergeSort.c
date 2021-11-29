#include "TestMergeSort.h"
#include "MergeSort.h"

bool testMergeSort()
{
    List* newFirstList = createList();
    Error error = NOT_ERROR;
    add(newFirstList, "Pavel", "890345", &error);
    add(newFirstList, "Alex", "765494", &error);
    add(newFirstList, "Artem", "956469", &error);
    add(newFirstList, "Ruslan", "2342424", &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newFirstList);
        return false;
    }
    List* newSecondList = createList();
    add(newSecondList, "Alex", "765494", &error);
    add(newSecondList, "Artem", "956469", &error);
    add(newSecondList, "Pavel", "890345", &error);
    add(newSecondList, "Ruslan", "2342424", &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newFirstList);
        deleteList(newSecondList);
        return false;
    }
    List* firstList = mergeSort(newFirstList, 1, &error);
    bool result = compareList(firstList, newSecondList);
    deleteList(newSecondList);
    deleteList(firstList);
    return result;
}
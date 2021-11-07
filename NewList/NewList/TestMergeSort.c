#include "TestMergeSort.h"
#include "MergeSort.h"
#include "List.h"
#include <string.h>

bool testMergeSort()
{
    List* newFirstList = createList();
    int error = 0;
    add(newFirstList, last(newFirstList, &error), "Pavel", "890345", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), "Alex", "765494", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), "Artem", "956469", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), "Ruslan", "2342424", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    List* newSecondList = createList();
    add(newSecondList, last(newSecondList, &error), "Pavel", "890345", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), "Alex", "765494", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), "Artem", "956469", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), "Ruslan", "2342424", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }

    List* firstList = mergeSort(newFirstList, 1, &error);

    Position* position = first(firstList, &error);
    const char* firstStringFirstValueFirstList = getFirstValue(position);
    const char* firstStringSecondValueFirstList = getSecondValue(position);
    next(position);
    const char* secondStringFirstValueFirstList = getFirstValue(position);
    const char* secondStringSecondValueFirstList = getSecondValue(position);
    next(position);
    const char* thirdStringFirstValueFirstList = getFirstValue(position);
    const char* thirdStringSecondValueFirstList = getSecondValue(position);
    next(position);
    const char* fourthStringFirstValueFirstList = getFirstValue(position);
    const char* fourthStringSecondValueFirstList = getSecondValue(position);
    
    deletePosition(position);

    List* secondList = mergeSort(newSecondList, 0, &error);

    Position* newPosition = first(secondList, &error);
    const char* firstStringFirstValueSecondList = getFirstValue(newPosition);
    const char* firstStringSecondValueSecondList = getSecondValue(newPosition);
    next(newPosition);
    const char* secondStringFirstValueSecondList = getFirstValue(newPosition);
    const char* secondStringSecondValueSecondList = getSecondValue(newPosition);
    next(newPosition);
    const char* thirdStringFirstValueSecondList = getFirstValue(newPosition);
    const char* thirdStringSecondValueSecondList = getSecondValue(newPosition);
    next(newPosition);
    const char* fourthStringFirstValueSecondList = getFirstValue(newPosition);
    const char* fourthStringSecondValueSecondList = getSecondValue(newPosition);
    
    bool result =  strcmp(firstStringFirstValueFirstList, "Alex") == 0 && strcmp(firstStringSecondValueFirstList, "765494") == 0
        && strcmp(secondStringFirstValueFirstList, "Artem") == 0 && strcmp(secondStringSecondValueFirstList, "956469") == 0
        && strcmp(thirdStringFirstValueFirstList, "Pavel") == 0 && strcmp(thirdStringSecondValueFirstList, "890345") == 0
        && strcmp(fourthStringFirstValueFirstList, "Ruslan") == 0 && strcmp(fourthStringSecondValueFirstList, "2342424") == 0

        && strcmp(firstStringFirstValueSecondList, "Ruslan") == 0 && strcmp(firstStringSecondValueSecondList, "2342424") == 0
        && strcmp(secondStringFirstValueSecondList, "Alex") == 0 && strcmp(secondStringSecondValueSecondList, "765494") == 0
        && strcmp(thirdStringFirstValueSecondList, "Pavel") == 0 && strcmp(thirdStringSecondValueSecondList, "890345") == 0
        && strcmp(fourthStringFirstValueSecondList, "Artem") == 0 && strcmp(fourthStringSecondValueSecondList, "956469") == 0;

    deletePosition(newPosition);
    deleteList(newFirstList);
    deleteList(newSecondList);
    deleteList(firstList);
    deleteList(secondList);
    return result;
}
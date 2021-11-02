#include "TestMergeSort.h"
#include "MergeSort.h"
#include "List.h"
#include <string.h>

bool testMergeSort()
{
    List* newFirstList = createList();
    int error = 0;
    add(newFirstList, last(newFirstList, &error), (int*)"Pavel", (int*)"890345", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), (int*)"Alex", (int*)"765494", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), (int*)"Artem", (int*)"956469", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }
    add(newFirstList, last(newFirstList, &error), (int*)"Ruslan", (int*)"2342424", &error);
    if (error == 3)
    {
        deleteList(newFirstList);
        return false;
    }

    List* newSecondList = createList();
    add(newSecondList, last(newSecondList, &error), (int*)"Pavel", (int*)"890345", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), (int*)"Alex", (int*)"765494", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), (int*)"Artem", (int*)"956469", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }
    add(newSecondList, last(newSecondList, &error), (int*)"Ruslan", (int*)"2342424", &error);
    if (error == 3)
    {
        deleteList(newSecondList);
        deleteList(newFirstList);
        return false;
    }

    List* firstList = mergeSort(newFirstList, 1, &error);

    const char* firstStringFirstValueFirstList = (char*)firstList->head->firstValue;
    const char* firstStringSecondValueFirstList = (char*)firstList->head->secondValue;

    const char* secondStringFirstValueFirstList = (char*)firstList->head->next->firstValue;
    const char* secondStringSecondValueFirstList = (char*)firstList->head->next->secondValue;

    const char* thirdStringFirstValueFirstList = (char*)firstList->head->next->next->firstValue;
    const char* thirdStringSecondValueFirstList = (char*)firstList->head->next->next->secondValue;

    const char* fourthStringFirstValueFirstList = (char*)firstList->head->next->next->next->firstValue;
    const char* fourthStringSecondValueFirstList = (char*)firstList->head->next->next->next->secondValue;

    List* secondList = mergeSort(newSecondList, 0, &error);

    const char* firstStringFirstValueSecondList = (char*)secondList->head->firstValue;
    const char* firstStringSecondValueSecondList = (char*)secondList->head->secondValue;

    const char* secondStringFirstValueSecondList = (char*)secondList->head->next->firstValue;
    const char* secondStringSecondValueSecondList = (char*)secondList->head->next->secondValue;

    const char* thirdStringFirstValueSecondList = (char*)secondList->head->next->next->firstValue;
    const char* thirdStringSecondValueSecondList = (char*)secondList->head->next->next->secondValue;

    const char* fourthStringFirstValueSecondList = (char*)secondList->head->next->next->next->firstValue;
    const char* fourthStringSecondValueSecondList = (char*)secondList->head->next->next->next->secondValue;

    deleteList(newFirstList);
    deleteList(newSecondList);
    deleteList(firstList);
    deleteList(secondList);

    return strcmp(firstStringFirstValueFirstList, "Alex") == 0 && strcmp(firstStringSecondValueFirstList, "765494") == 0
    && strcmp(secondStringFirstValueFirstList, "Artem") == 0 && strcmp(secondStringSecondValueFirstList, "956469") == 0
    && strcmp(thirdStringFirstValueFirstList, "Pavel") == 0 && strcmp(thirdStringSecondValueFirstList, "890345") == 0
    && strcmp(fourthStringFirstValueFirstList, "Ruslan") == 0 && strcmp(fourthStringSecondValueFirstList, "2342424") == 0

    && strcmp(firstStringFirstValueSecondList, "Ruslan") == 0 && strcmp(firstStringSecondValueSecondList, "2342424") == 0
    && strcmp(secondStringFirstValueSecondList, "Alex") == 0 && strcmp(secondStringSecondValueSecondList, "765494") == 0
    && strcmp(thirdStringFirstValueSecondList, "Pavel") == 0 && strcmp(thirdStringSecondValueSecondList, "890345") == 0
    && strcmp(fourthStringFirstValueSecondList, "Artem") == 0 && strcmp(fourthStringSecondValueSecondList, "956469") == 0;
}
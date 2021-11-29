#include "MergeSort.h"
#include <string.h>
#include <stdlib.h>

bool compareTheHeads(List* firstList, List* secondlist, int number)
{
    return (number == 1) ? strcmp(getHeadFirstValue(firstList), getHeadFirstValue(secondlist)) <= 0
        : strcmp(getHeadSecondValue(firstList), getHeadSecondValue(secondlist)) <= 0;
}

List* merge(List* firstList, List* secondList, int number, Error* error)
{
    List* sortedList = createList();
    while (!isEmpty(firstList) && !isEmpty(secondList))
    {
        if (compareTheHeads(firstList, secondList, number))
        {
            add(sortedList, getHeadFirstValue(firstList), getHeadSecondValue(firstList), error);
            removeFirstElement(firstList, error);
        }
        else
        {
            add(sortedList, getHeadFirstValue(secondList), getHeadSecondValue(secondList), error);
            removeFirstElement(secondList, error);
        }
    }
    while (!isEmpty(firstList))
    {
        add(sortedList, getHeadFirstValue(firstList), getHeadSecondValue(firstList), error);
        removeFirstElement(firstList, error);
    }
    while (!isEmpty(secondList))
    {
        add(sortedList, getHeadFirstValue(secondList), getHeadSecondValue(secondList), error);
        removeFirstElement(secondList, error);
    }
    if (*error == EMPTY_LIST || *error == INSUFFICIENT_MEMORY)
    {
        deleteList(sortedList);
        deleteList(firstList);
        deleteList(secondList);
        return NULL;
    }
    free(firstList);
    free(secondList);
    return sortedList;
}

List* mergeSort(List* list, int number, Error* error)
{
    if (isEmpty(list))
    {
        return list;
    }
    if (isOneElement(list))
    {
        return list;
    }
    const int leftBorderOfList = numberOfElements(list) / 2;
    const int rightBorderOfList = numberOfElements(list);
    List* leftHalfOfTheList = createList();
    List* rightHalfOfTheList = createList();
    for (int i = 1; i <= leftBorderOfList; i++)
    {
        add(leftHalfOfTheList, getHeadFirstValue(list), getHeadSecondValue(list), error);
        removeFirstElement(list, error);
    }
    for (int i = leftBorderOfList + 1; i <= rightBorderOfList; i++)
    {
        add(rightHalfOfTheList, getHeadFirstValue(list), getHeadSecondValue(list), error);
        removeFirstElement(list, error);
    }
    if (*error == EMPTY_LIST || *error == INSUFFICIENT_MEMORY)
    {
        deleteList(leftHalfOfTheList);
        deleteList(rightHalfOfTheList);
        deleteList(list);
        return NULL;
    }
    free(list);
    List* firstList = mergeSort(leftHalfOfTheList, number, error);
    List* secondList = mergeSort(rightHalfOfTheList, number, error);
    List* answer = merge(firstList, secondList, number, error);
    return answer;
}
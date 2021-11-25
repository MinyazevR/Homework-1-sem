#include "MergeSort.h"
#include <string.h>
#include "stdlib.h"

bool compareTheHeads(List* firstList, List* secondlist, int number)
{
    if (number == 1)
    {
        return strcmp(getHeadFirstValue(firstList), getHeadFirstValue(secondlist)) <= 0;
    }
    else
    {
        return strcmp(getHeadSecondValue(firstList), getHeadSecondValue(secondlist)) <= 0;
    }
}

List* merge(List* firstList, List* secondList, int number, int* error)
{
    List* sortedList = createList();
    while (!isEmpty(firstList) && !isEmpty(secondList))
    {
        if (compareTheHeads(firstList, secondList, number))
        {
            add(sortedList, getHeadFirstValue(firstList), getHeadSecondValue(firstList), error);
            if (*error == 3)
            {
                deleteList(sortedList);
                deleteList(firstList);
                deleteList(secondList);
                return NULL;
            }
            removeFirstElement(firstList, error);
            if (*error == 2)
            {
                deleteList(sortedList);
                deleteList(firstList);
                deleteList(secondList);
                return NULL;
            }
        }
        else
        {
            add(sortedList, getHeadFirstValue(secondList), getHeadSecondValue(secondList), error);
            removeFirstElement(secondList, error);
            if (*error == 2)
            {
                deleteList(sortedList);
                deleteList(firstList);
                deleteList(secondList);
                return NULL;
            }
        }
    }
    while (!isEmpty(firstList))
    {
        add(sortedList, getHeadFirstValue(firstList), getHeadSecondValue(firstList), error);
        if (*error == 3)
        {
            deleteList(sortedList);
            deleteList(firstList);
            deleteList(secondList);
            return NULL;
        }
        removeFirstElement(firstList, error);
        if (*error == 2)
        {
            deleteList(firstList);
            deleteList(secondList);
            return NULL;
        }
    }
    while (!isEmpty(secondList))
    {
        add(sortedList, getHeadFirstValue(secondList), getHeadSecondValue(secondList), error);
        if (*error == 3)
        {
            deleteList(sortedList);
            deleteList(firstList);
            deleteList(secondList);
            return NULL;
        }
        removeFirstElement(secondList, error);
        if (*error == 2)
        {
            deleteList(sortedList);
            deleteList(firstList);
            deleteList(secondList);
            return NULL;
        }
    }
    free(firstList);
    free(secondList);
    return sortedList;
}

List* mergeSort(List* list, int number, int* error)
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
        if (*error == 3)
        {
            deleteList(leftHalfOfTheList);
            deleteList(rightHalfOfTheList);
            deleteList(list);
            return NULL;
        }
        removeFirstElement(list, error);
        if (*error == 2)
        {
            deleteList(leftHalfOfTheList);
            deleteList(rightHalfOfTheList);
            deleteList(list);
            return NULL;
        }
    }
    for (int i = leftBorderOfList + 1; i <= rightBorderOfList; i++)
    {
        add(rightHalfOfTheList, getHeadFirstValue(list), getHeadSecondValue(list), error);
        if (*error == 3)
        {
            deleteList(leftHalfOfTheList);
            deleteList(rightHalfOfTheList);
            deleteList(list);
            return NULL;
        }
        removeFirstElement(list, error);
        if (*error == 2)
        {
            deleteList(leftHalfOfTheList);
            deleteList(rightHalfOfTheList);
            deleteList(list);
            return NULL;
        }
    }
    free(list);
    List* firstList = mergeSort(leftHalfOfTheList, number, error);
    List* secondList = mergeSort(rightHalfOfTheList, number, error);
    List* answer = merge(firstList, secondList, number, error);
    return answer;
}
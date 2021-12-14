#include "MergeList.h"
#include <stdbool.h>
#include <stdlib.h>

List* merge(List* firstList, List* secondList, Error* error)
{
    List* sortedList = createList();
    while (!isEmpty(firstList))
    {
        add(sortedList, getHeadValue(firstList), error);
        removeFirstElement(firstList, error);
    }
    while (!isEmpty(secondList))
    {
        add(sortedList, getHeadValue(secondList), error);
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
#include "CircleOfMurders.h"
#include "CyclicList.h"

int findSurvivorPosition(int numberOfWarriors, int frequencyOfMurders, int* error)
{
    if (numberOfWarriors == 0)
    {
        *error = 2;
        return 0;
    }
    if (frequencyOfMurders == 0)
    {
        *error = 2;
        return 0;
    }
    List* newList = createList();
    int errorCode = 0;
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        add(newList, i, &errorCode);
        if (errorCode == 3)
        {
            deleteList(newList);
            *error = 3;
            return 0;
        }
    }
    Position* firstPosition = first(newList, &errorCode);
    if (errorCode == 3)
    {
        deleteList(newList);
        *error = 3;
        return 0;
    }
    int counter = 1;
    while (returnFirstElement(newList) != returnLastElement(newList))
    {
        if (counter % frequencyOfMurders == 0)
        {
            removeElement(newList, &firstPosition, &errorCode);
            if (errorCode == 1)
            {
                free(firstPosition);
                deleteList(newList);
                *error = 1;
                return 0;
            }
            previous(firstPosition);
        }
        next(firstPosition);
        counter++;
    }
    const int answer = returnFirstElementValue(newList);
    deleteList(newList);
    return answer;
}
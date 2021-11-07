#include "CircleOfMurders.h"
#include "CyclicList.h"
#include <stdlib.h>

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
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        add(newList, i, error);
        if (*error == 3)
        {
            deleteList(newList);
            return 0;
        }
    }
    Position* firstPosition = first(newList, error);
    if (*error == 3)
    {
        deleteList(newList);
        return 0;
    }
    int counter = 1;
    while (numberOfElements(newList) != 1)
    {
        if (counter % frequencyOfMurders == 0)
        {
            removeElement(newList, firstPosition, error);
            if (*error == 1)
            {
                freePosition(firstPosition);
                deleteList(newList);
                return 0;
            }
        }
        else
        {
            next(firstPosition);
        }
        counter++;
    }
    const int answer = returnFirstElementValue(newList);
    freePosition(firstPosition);
    deleteList(newList);
    return answer;
}
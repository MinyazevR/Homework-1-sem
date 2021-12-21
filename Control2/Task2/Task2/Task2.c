#include "../../List/List/List.h"
#include "ReadFile.h"
#include <string.h>
#include <stdlib.h>

List* removeRepeatElement(List* list, Error* error)
{
    List* newList = createList(error);
    Position* position = first(list, error);
    Position* newPosition = first(list, error);
    while(!isLastElement(position))
    {
        newPosition = position;
        while (!isLastElement(newPosition))
        {
            if (strcmp(getValue(position), getValue(newPosition)) == 0 && newPosition != position)
            {
                next(position);
                break;
            }
            newPosition = next(newPosition);
        }
        if (strcmp(getValue(position), getValue(newPosition)) == 0 && newPosition != position)
        {
            next(position);
            continue;
        }
        add(newList, getValue(position), error);
        position = next(position);
        print(newList);
    }
    free(position);
    free(newPosition);
    return newList;
}

int main()
{
    Error error = 0;
    List* list = createList(&error);
    readFile("Text.txt", list);
    List* newList = removeRepeatElement(list, &error);
    print(newList);
}
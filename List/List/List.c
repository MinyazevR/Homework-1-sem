#include "List.h"
#include <stdio.h>

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    ListElement* position = list->head;
    while (list->head != NULL)
    {
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(list);
}

void deletePosition(Position* position, int* error)
{
    *error = 0;
    if (position == NULL)
    {
        *error = 5;
        return;
    }
    free(position);
}

void removeElement(Position* position, List* list, int* error)
{
    *error = 0;
    if (position->position == NULL || position->position->next == NULL)
    {
        *error = 1;
        return;
    }
    position->position->next = position->position->next->next;
    free(position);
}

void removeFirstElement(Position* position, List* list, int* error)
{
    *error = 0;
    if (position->position == NULL)
    {
        *error = 2;
        return;
    }
    list->head = position->position->next;
    free(position);
}

Position* first(List* list, int* error)
{
    *error = 0;
    Position* positionFirst = malloc(sizeof(Position));
    if (positionFirst == NULL)
    {
        *error = 3;
        return NULL;
    }
    positionFirst->position = list->head;
    return positionFirst;
}

Position* next(Position* position)
{
    position->position = position->position->next;
    return position;
}

bool last(Position* position)
{
    return position->position == NULL;
}

int get(List* list, Position* position, int* error)
{
    *error = 0;
    if (position == NULL)
    {
        *error = 5;
        return 0;
    }
    return position->position->value;
}

Position* findPosition(int value, List* list, int* error)
{
    int errorCode = 0;
    if (list->head == NULL)
    {
        return first(list, &errorCode);
    }
    Position* firstPosition = first(list, &errorCode);
    if (errorCode == 3)
    {
        *error = 3;
        return NULL;
    }
    Position* secondPosition = first(list, &errorCode);
    if (errorCode == 3)
    {
        *error = 3;
        return NULL;
    }
    int i = 0;
    while (get(list, firstPosition, &errorCode) < value && firstPosition->position->next != NULL)
    {
        if (i >= 1)
        {
            secondPosition->position = secondPosition->position->next;
        }
        firstPosition->position = firstPosition->position->next;
        i++;
    }
    if (get(list, firstPosition, &errorCode) < value)
    {
        *error = 6;
        return NULL;
    }
    free(firstPosition);
    return secondPosition;
}

void add(List* list, int value, int* error)
{
    int errorCode = 0;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        *error = 3;
        return;
    }
    Position* firstPosition = first(list, &errorCode);
    if (errorCode == 3)
    {
        *error = 3;
        return;
    }
    newElement->value = value;
    if (firstPosition->position == NULL)
    {
        list->head = newElement;
        return;
    }
    int i = 0;
    if (value < list->head->value)
    {
        newElement->next = list->head;
        list->head = newElement;
        return;
    }
    Position* secondPosition = first(list, &errorCode);
    if (errorCode == 3)
    {
        *error = 3;
        return;
    }
    while (get(list, firstPosition, &errorCode) < value && firstPosition->position->next != NULL)
    {
        if (i >= 1)
        {
            secondPosition->position = secondPosition->position->next;
        }
        firstPosition->position = firstPosition->position->next;
        i++;
    }
    if (firstPosition->position->next == NULL && get(list, firstPosition, &errorCode) < value)
    {
        newElement->next = NULL;
        firstPosition->position->next = newElement;
        return;
    }
    newElement->next = secondPosition->position->next;
    secondPosition->position->next = newElement;
}

void print(List* list)
{
    int error = 0;
    for (Position* i = first(list, &error); !last(i); i = next(i))
    {
        printf("%d ", get(list, i, &error));
    }
}
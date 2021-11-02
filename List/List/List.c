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

void removeElement(ListElement* element, List* list, int* error)
{
    *error = 0;
    if (element == NULL || element->next == NULL)
    {
        *error = 1;
        return;
    }
    ListElement* temporary = element->next;
    element->next = element->next->next;
    free(temporary);
}

void removeFirstElement(List* list, int* error)
{
    *error = 0;
    if (list->head == NULL)
    {
        *error = 2;
        return;
    }
    ListElement* temporary = list->head;
    list->head = list->head->next;
    free(temporary);
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

ListElement* findPosition(int value, List* list, int* error)
{
    int errorCode = 0;
    if (list->head == NULL)
    {
        return list->head;
    }
    ListElement* firstTemporary = list->head;
    ListElement* secondTemporary = list->head;
    int i = 0;
    while (firstTemporary->value < value && firstTemporary->next != NULL)
    {
        if (i >= 1)
        {
            secondTemporary = secondTemporary->next;
        }
        firstTemporary = firstTemporary->next;
        i++;
    }
    if (firstTemporary->value < value)
    {
        *error = 6;
        return NULL;
    }
    return secondTemporary;
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
    newElement->value = value;
    if (list->head == NULL)
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
    ListElement* firstTemporary = list->head;
    ListElement* secondTemporary = list->head;
    while (firstTemporary->value < value && firstTemporary->next != NULL)
    {
        if (i >= 1)
        {
            secondTemporary = secondTemporary->next;
        }
        firstTemporary = firstTemporary->next;
        i++;
    }
    if (firstTemporary->next == NULL && firstTemporary->value < value)
    {
        newElement->next = NULL;
        firstTemporary->next = newElement;
        return;
    }
    newElement->next = secondTemporary->next;
    secondTemporary->next = newElement;
}

void print(List* list)
{
    int error = 0;
    for (Position* i = first(list, &error); !last(i); i = next(i))
    {
        printf("%d ", get(list, i, &error));
    }
}
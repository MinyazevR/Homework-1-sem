#include "CyclicList.h"
#include <stdio.h>

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    ListElement* position = list->head;
    while (list->head != list->tail)
    {
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(position);
    free(list);
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

Position* previous(Position* position)
{
    position->position = position->position->previous;
    return position;
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
        list->tail = newElement;
        list->tail->previous = list->head;
        list->head->next = list->tail;
        return;
    }
    newElement->previous = list->tail;
    list->tail->next = newElement;
    newElement->next = list->head;
    list->tail = newElement;
}

void removeElement(List* list, Position* position, int* error)
{
    if (list->head == NULL || list->tail == NULL)
    {
        *error = 1;
        return;
    }
    if (position->position == list->head)
    {
        if (list->tail == list->head)
        {
            list->tail = NULL;
            list->head = NULL;
            return;
        }
        list->tail->next = list->head->next;
        list->head->next->previous = list->tail;
        list->head = list->head->next;
        return;
    }
    if (position->position == list->tail)
    {
        list->tail->previous->next = list->head;
        list->head->previous = list->tail->previous;
        list->tail = list->tail->previous;
        return;
    }
    position->position->previous->next = position->position->next;
    position->position->next->previous = position->position->previous;
    position->position->previous = position->position;
    position->position = position->position->next;
}
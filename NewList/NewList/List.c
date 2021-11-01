#include "List.h"
#include <stdio.h>
#include <string.h>

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    if (list->head == NULL)
    {
        return;
    }
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

void removeFirstElement(List* list, int* error)
{
    *error = 0;
    if (list-> head == NULL)
    {
        *error = 2;
        return;
    }
    list->head = list->head->next;
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

Position* last(List* list, int* error)
{
    *error = 0;
    Position* positionFirst = malloc(sizeof(Position));
    if (positionFirst == NULL)
    {
        *error = 3;
        return NULL;
    }
    positionFirst->position = list->tail;
    return positionFirst;
}

Position* next(Position* position)
{
    position->position = position->position->next;
    return position;
}

bool isLast(Position* position)
{
    return position->position == NULL;
}

int numberOfElements(List* list, int* error)
{
    Position* position = first(list, &*error);
    if (*error == 3)
    {
        return 0;
    }
    int counter = 1;
    if (list->head == NULL)
    {
        return 0;
    }
    while (position->position->next != NULL)
    {
        position->position = position->position->next;
        counter++;
    }
    return counter;
}

int* getHeadFirstValue(List* list)
{
    return list->head->firstValue;
}

int* getHeadSecondValue(List* list)
{
    return list->head->secondValue;
}

void add(List* list, Position* position, int* firstValue, int* secondValue, int* error)
{
    int* fValue = calloc(100, sizeof(int));
    if (fValue == NULL)
    {
        *error = 3;
        return;
    }
    int counter = 0;
    while (firstValue[counter])
    {
        fValue[counter] = firstValue[counter];
        counter++;
    }
    counter = 0;
    int* sValue = calloc(100, sizeof(int));
    if (sValue == NULL)
    {
        *error = 3;
        return;
    }
    while (secondValue[counter])
    {
        sValue[counter] = secondValue[counter];
        counter++;
    }
    int errorCode = 0;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        *error = 3;
        return;
    }
    newElement->firstValue = fValue;
    newElement->secondValue = sValue;
    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
        list->tail = list->head;
        return;
    }
    position->position->next = newElement;
    list->tail = list->tail->next;
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

bool isOneElement(List* list)
{
    return list->head->next == NULL;
}

void print(List * list)
{
    int error = 0;
    for (Position* position = first(list, &error); !isLast(position); position = next(position))
    {
        printf("%s - ", (char*)(position->position->firstValue));
        printf("%s", (char*)(position->position->secondValue));
        printf("\n");
    }
}
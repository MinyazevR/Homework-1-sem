#include "List.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


// Structure containing pointers to the beginning and end of the list
typedef struct List
{
    int size;
    struct ListElement* head;
    struct ListElement* tail;
} List;

// A structure containing a pointer to the next list item and a value variable for the list items
typedef struct ListElement
{
    char* firstValue;
    char* secondValue;
    struct ListElement* next;
} ListElement;

// contains a pointer to a ListElement
typedef struct Position
{
    ListElement* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    if (list->head == NULL)
    {
        list->size = 0;
        free(list);
        return;
    }
    ListElement* position = list->head;
    while (position != NULL)
    {
        list->head = list->head->next;
        free(position->secondValue);
        free(position->firstValue);
        free(position);
        position = list->head;
    }
    list->size = 0;
    free(list);
}

void deletePosition(Position* position)
{
    free(position);
}

void removeFirstElement(List* list, int* error)
{
    *error = 0;
    if (list->head == NULL)
    {
        *error = 2;
        return;
    }
    ListElement* position = list->head;
    list->head = list->head->next;
    list->size--;
    free(position->secondValue);
    free(position->firstValue);
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

Position* last(List* list, int* error)
{
    *error = 0;
    Position* positionLast = malloc(sizeof(Position));
    if (positionLast == NULL)
    {
        *error = 3;
        return NULL;
    }
    positionLast->position = list->tail;
    return positionLast;
}

Position* next(Position* position)
{
    position->position = position->position->next;
    return position;
}

bool isLastElement(Position* position)
{
    return position->position->next == NULL;
}

int numberOfElements(List* list)
{
    return list->size;
}

char* getHeadFirstValue(List* list)
{
    if (list->head == NULL)
    {
        return NULL;
    }
    return list->head->firstValue;
}

char* getHeadSecondValue(List* list)
{
    if (list->head == NULL)
    {
        return NULL;
    }
    return list->head->secondValue;
}

char* getFirstValue(Position* position)
{
    if (position->position == NULL)
    {
        return NULL;
    }
    return position->position->firstValue;
}

char* getSecondValue(Position* position)
{
    if (position->position == NULL)
    {
        return NULL;
    }
    return position->position->secondValue;
}

void add(List* list, Position* position, char* firstValue, char* secondValue, int* error)
{
    char* firstValueCopy = calloc(100, sizeof(char));
    if (firstValueCopy == NULL)
    {
        *error = 3;
        return;
    }
    strcpy(firstValueCopy, firstValue);
    char* secondValueCopy = calloc(100, sizeof(char));
    if (secondValueCopy == NULL)
    {
        free(firstValueCopy);
        *error = 3;
        return;
    }
    strcpy(secondValueCopy, secondValue);
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        free(firstValueCopy);
        free(secondValueCopy);
        *error = 3;
        return;
    }
    newElement->firstValue = firstValueCopy;
    newElement->secondValue = secondValueCopy;
    if (list->head == NULL)
    {
        list->size = 1;
        list->head = newElement;
        list->tail = newElement;
        list->tail = list->head;
        return;
    }
    list->size++;
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

void print(List* list)
{
    int error = 0;
    for (Position* position = first(list, &error); !isLastElement(position); position = next(position))
    {
        printf("%s - ", position->position->firstValue);
        printf("%s", position->position->secondValue);
        printf("\n");
    }
}
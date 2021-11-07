#include "List.h"
#include <stdio.h>
#include <string.h>


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

// A structure containing a pointer to the position of a list item
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
    ListElement* position = list->head;
    while (position != NULL)
    {
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(list);
}

void deletePosition(Position* position)
{
    free(position);
}

void removeFirstElement(List* list, int* error)
{
    if (list->head == NULL)
    {
        return;
    }
    ListElement* position = list->head;
    list->head = list->head->next;
    list->size--;
    free(position->firstValue);
    free(position->secondValue);
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
    return position->position->next == NULL;
}

int numberOfElements(List* list, int* error)
{
    return list->size;
}

int* getHeadFirstValue(List* list)
{
    return list->head->firstValue;
}

int* getHeadSecondValue(List* list)
{
    return list->head->secondValue;
}

void add(List* list, Position* position, char* firstValue, char* secondValue, int* error)
{
    char* firstValueCopy = calloc(strlen(firstValue), sizeof(char));
    if (firstValueCopy == NULL)
    {
        *error = 3;
        return;
    }
    strcpy(firstValueCopy, firstValue);
    int* secondValueCopy = calloc(strlen(secondValue), sizeof(int));
    if (secondValueCopy == NULL)
    {
        free(firstValueCopy);
        *error = 3;
        return;
    }
    strcpy(secondValueCopy, firstValue);
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
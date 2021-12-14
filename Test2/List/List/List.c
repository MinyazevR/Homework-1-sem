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

// Structure containing a pointer to the next list item and a value variable for the list items
typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

// Structure containing a pointer to a ListElement
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

void removeFirstElement(List* list, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    if (list->head == NULL)
    {
        *error = EMPTY_LIST;
        return;
    }
    if (list->head == list->tail)
    {
        list->size = 0;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    ListElement* element = list->head;
    list->head = list->head->next;
    list->size--;
    free(element);

}

Position* first(List* list, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return NULL;
    }
    Position* positionFirst = malloc(sizeof(Position));
    if (positionFirst == NULL)
    {
        *error = EMPTY_LIST;
        return NULL;
    }
    positionFirst->position = list->head;
    return positionFirst;
}

Position* last(List* list, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return NULL;
    }
    Position* positionLast = malloc(sizeof(Position));
    if (positionLast == NULL)
    {
        *error = EMPTY_LIST;
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

int getHeadValue(List* list)
{
    if (list->head == NULL)
    {
        return 0;
    }
    return list->head->value;
}

int getValue(Position* position)
{
    if (position->position == NULL)
    {
        return 0;
    }
    return position->position->value;
}

void add(List* list, const int value, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
        return;
    }
    newElement->value = value;
    if (list->head == NULL)
    {
        list->size = 1;
        list->head = newElement;
        list->tail = newElement;
        return;
    }
    list->size++;
    list->tail->next = newElement;
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
    ListElement* element = list->head;
    while (element != NULL)
    {
        printf("%d ", element->value);
        element = element->next;
    }
}

bool compareList(List* firstList, List* secondList)
{
    ListElement* firstElement = firstList->head;
    ListElement* secondElement = secondList->head;
    if (numberOfElements(firstList) != numberOfElements(secondList))
    {
        return false;
    }
    while (firstElement != NULL)
    {
        if (firstElement->value != secondElement->value)
        {
            return false;
        }
        firstElement = firstElement->next;
        secondElement = secondElement->next;
    }
    return true;
}

const char* decodingError(Error error)
{
    if (error == EMPTY_LIST)
    {
        return "Error in the program";
    }
    if (error == INSUFFICIENT_MEMORY)
    {
        return "Memory not allocated";
    }
    return NULL;
}

bool inList(List* list, int value)
{
    ListElement* element = list->head;
    while (element != NULL)
    {
        if (element->value == value)
        {
            return true;
        }
        element = element->next;
    }
    return false;
}
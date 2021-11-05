#include "CyclicList.h"
#include <stdio.h>

// Structure containing pointers to the "first" and "last" list item
typedef struct List
{
    struct ListElement* head;
    struct ListElement* tail;
} List;

// Structure containing pointers to the next and previous list item and a value variable for list items
typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

// Structure containing a pointer to the position of a list item
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

void invariant(ListElement* element)
{
    element->next->previous = element;
    element->previous->next = element;
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
        list->tail = newElement;
        list->tail->next = list->head;
        list->head->previous = list->tail;
        return;
    }
    newElement->next = list->head;
    newElement->previous = list->tail;
    invariant(newElement);
    list->tail = list->tail->next;
}

int returnFirstElementValue(List* list)
{
    return list->head->value;
}

void removeElement(List* list, Position** position, int* error)
{
    if (list->head == NULL || list->tail == NULL)
    {
        *error = 1;
        return;
    }
    if ((*position)->position == list->head)
    {
        if (list->tail == list->head)
        {
            list->tail = NULL;
            list->head = NULL;
            free(list->head);
            return;
        }
        ListElement* element = list->head;
        list->head = list->head->next;
        list->head->previous = list->tail;
        invariant(list->head);
        (*position)->position = list->head;
        free(element);
        return;
    }
    if ((*position)->position == list->tail)
    {
        ListElement* element = list->tail;
        list->tail = list->tail->previous;
        list->tail->next = list->head;
        invariant(list->tail);
        (*position)->position = list->head;
        free(element);
        return;
    }
    ListElement* element = (*position)->position;
    (*position)->position = (*position)->position->next;
    (*position)->position->previous = (*position)->position->previous->previous;
    free(element);
    invariant((*position)->position);
}

int get(Position* position)
{
    return position->position->value;
}

ListElement* returnFirstElement(List* list)
{
    return list->head;
}

ListElement* returnLastElement(List* list)
{
    return list->tail;
}
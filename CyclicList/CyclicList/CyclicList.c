#include "CyclicList.h"
#include <stdio.h>
#include <stdlib.h>

// Structure containing pointers to the "first" and "last" list item
typedef struct List
{
    int size;
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

// A structure that stores a pointer to a list item
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
    list->size = 0;
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

void attach(ListElement* element)
{
    element->next->previous = element;
    element->previous->next = element;
}

void add(List* list, int value, int* error)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));   
    if (newElement == NULL)
    {
        *error = 3;
        return;
    }
    newElement->value = value;
    if (list->head == NULL)
    {
        list->size = 1;
        list->head = newElement;
        list->tail = newElement;
        list->tail->next = list->head;
        list->head->previous = list->tail;
        return;
    }
    list->size++;
    newElement->next = list->head;
    newElement->previous = list->tail;
    attach(newElement);
    list->tail = list->tail->next;
}

int returnFirstElementValue(List* list)
{
    return list->head->value;
}

void removeElement(List* list, Position* position, int* error)
{
    if (list->head == NULL || position == NULL)
    {
        *error = 1;
        return;
    }
    Position* newPosition = position;
    if (position->position == list->head)
    {
        if (list->tail == list->head)
        {
            free(list->head);
            free(position);
            list->tail = NULL;
            list->head = NULL;
            list->size = 0;
            return;
        }
        ListElement* element = list->head;
        list->head = list->head->next;
        list->head->previous = list->tail;
        attach(list->head);
        position->position = list->head;
        free(element);
        list->size--;
        return;
    }
    if (position->position == list->tail)
    {
        ListElement* element = list->tail;
        list->tail = list->tail->previous;
        list->tail->next = list->head;
        attach(list->tail);
        position->position = list->head;
        free(element);
        list->size--;
        return;
    }
    ListElement* element = position->position;
    position->position = position->position->next;
    position->position->previous = position->position->previous->previous;
    free(element);
    list->size--;
    attach(position->position);
}

int get(Position* position)
{
    return position->position->value;
}

int numberOfElements(List* list)
{
    return list->size;
}

void freePosition(Position* position)
{
    free(position);
}
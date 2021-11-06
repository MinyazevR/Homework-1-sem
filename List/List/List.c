#include "List.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// A structure containing a pointer to the head of the list
typedef struct List
{
    struct ListElement* head;
} List;

// A structure containing a pointerû to the next and previous list item and a value variable for the list items
typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

// A structure that stores a pointer to a list item
typedef struct Position
{
    struct ListElement* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    ListElement* element = list->head;
    while (element != NULL)
    {
        list->head = list->head->next;
        free(element);
        element = list->head;
    }
    free(list);
}

void removeElement(Position* position, List* list)
{
    if (position == NULL)
    {
        return;
    }
    ListElement* temporary = position->position;
    if (position->position == list->head)
    {
        list->head = list->head->next; 
        free(temporary);
        free(position);
        return;
    }
    if (position->position->next == NULL)
    {
        position->position->previous->next = NULL;
        free(temporary);
        free(position);
        return;
    }
    position->position->previous->next = position->position->next;
    position->position->next->previous = position->position->previous;
    free(temporary);
    free(position);
}

Position* first(List* list, int* error)
{
    Position* position  = malloc(sizeof(Position));
    if (position == NULL)
    {
        *error = 3;
        return NULL;
    }
    position->position = list->head;
    return position;
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

bool last(Position* position)
{
    return position->position->next == NULL;
}

int get(List* list, Position* position, int* error)
{
    *error = 0;
    if (position->position == NULL)
    {
        *error = 6;
        return 0;
    }
    return position->position->value;
}

Position* findPosition(int value, List* list, int* error)
{
    int errorCode = 0;
    if (list->head == NULL)
    {
        *error = 6;
        return NULL;
    }
    if (value < list->head->value)
    {
        *error = 6;
        return NULL;
    }
    Position* position = first(list, error);
    if (*error == 3)
    {
        return NULL;
    }
    while (position->position->value < value && position->position->next != NULL)
    {
        next(position);
    }
    if (position->position->value != value)
    {
        *error = 6;
        return NULL;
    }
    return position;
}

void add(List* list, int value, int* error)
{
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL)
    {
        *error = 3;
        return;
    }
    element->value = value;
    if (list->head == NULL)
    {
        list->head = element;
        element->next = NULL;
        return;
    }
    if (value <= list->head->value)
    {
        element->next = list->head;
        list->head->previous = element;
        list->head = element;
        return;
    }
    ListElement* firstElement = list->head;
    while (firstElement->value < value && firstElement->next != NULL)
    {
        firstElement = firstElement->next;
    }
    if (firstElement->next == NULL && firstElement->value < value)
    {
        element->previous = firstElement;
        firstElement->next = element;
        element->next = NULL;
        return;
    }
    element->next = firstElement;
    element->previous = firstElement->previous;
    firstElement->previous = element;
    firstElement->previous->previous->next = element;
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

void freePosition(Position* position)
{
    free(position);
}
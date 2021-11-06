#include "List.h"
#include <stdio.h>
#include <malloc.h>

// A structure containing a pointer to the head of the list
typedef struct List
{
    struct ListElement* head;
} List;

// A structure containing a pointer to the next list item and a value variable for the list items
typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

// A structure containing a pointer to the next list item and a value variable for the list items
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
    while (list->head != NULL)
    {
        list->head = list->head->next;
        free(element);
        element = list->head;
    }
    free(list);
}

void removeElement(Position* position, List* list, int* error)
{
    *error = 0;
    if (position->position == NULL || position->position->next == NULL)
    {
        *error = 1;
        return;
    }
    ListElement* temporary = position->position->next;
    position->position->next = position->position->next->next;
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

Position* first(List* list)
{
    Position* position = malloc(sizeof(Position));
    if (position == NULL)
    {
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

bool last(Position* position)
{
    return position->position->next == NULL;
}

int get(List* list, Position* position, int* error)
{
    *error = 0;
    if (position->position == NULL)
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
        return NULL;
    }
    ListElement* firstElement = list->head;
    ListElement* secondElement = list->head;
    if (value < list->head->value)
    {
        *error = 6;
        return NULL;
    }
    int i = 0;
    while (firstElement->value < value && firstElement->next != NULL)
    {
        if (i >= 1)
        {
            secondElement = secondElement->next;
        }
        firstElement = firstElement->next;
        i++;
    }
    if (firstElement->value != value)
    {
        *error = 6;
        return NULL;
    }
    Position* position = malloc(sizeof(Position));
    if (position == NULL)
    {
        return NULL;
    }
    position->position = secondElement;
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
    ListElement* element = list->head;
    while (element != NULL)
    {
        printf("%d ", element->value);
        element = element->next;
    }
}
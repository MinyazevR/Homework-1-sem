#include "List.h"
#include <stdio.h>

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

ListElement* first(List* list)
{
    ListElement* element = list->head;
    return element;
}

ListElement* next(ListElement* element)
{
    element = element->next;
    return element;
}

bool last(ListElement* element)
{
    return element == NULL;
}

int get(List* list, ListElement* element, int* error)
{
    *error = 0;
    if (element == NULL)
    {
        *error = 5;
        return 0;
    }
    return element->value;
}

ListElement* findPosition(int value, List* list, int* error)
{
    int errorCode = 0;
    if (list->head == NULL)
    {
        return list->head;
    }
    ListElement* firstElement = list->head;
    ListElement* secondElement = list->head;
    int i = 0;
    if (value < list->head->value)
    {
        *error = 6;
        return NULL;
    }
    while (firstElement->value < value && firstElement->next != NULL)
    {
        if (i >= 1)
        {
            secondElement = secondElement->next;
        }
        firstElement = firstElement->next;
        i++;
    }
    if (firstElement->value < value)
    {
        *error = 6;
        return NULL;
    }
    return secondElement;
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

int findOrdinalNumberOfElementByValue(List* list, int value)
{
    ListElement* firstElement = list->head;
    if (value < list->head->value)
    {
        return 0;
    }
    int counter = 1;
    while (firstElement != NULL && firstElement->value != value)
    {
        firstElement = firstElement->next;
        counter++;
    }
    if (firstElement == NULL)
    {
        return 0;
    }
    return counter;
}
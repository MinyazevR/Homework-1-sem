#include "SinglyLinkedListForHashTable.h"
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
    int numberOfDuplicateValues;
    char* value;
    struct ListElement* next;
} ListElement;

// Structure containing a pointer to a ListElement
typedef struct Position
{
    ListElement* position;
} Position;

List* createList(Error* error)
{
    List* list = calloc(1, sizeof(List));
    if (list == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
    }
    return list;
}

void deleteList(List* list)
{
    ListElement* position = list->head;
    while (position != NULL)
    {
        list->head = list->head->next;
        free(position->value);
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
        free(list->head->value);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    ListElement* element = list->head;
    list->head = list->head->next;
    list->size--;
    free(element->value);
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

char* getHeadValue(List* list)
{
    if (list->head == NULL)
    {
        return NULL;
    }
    return list->head->value;
}

void add(List* list, const char* value, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    if (list->head == NULL)
    {
        char* valueCopy = calloc(strlen(value) + 1, sizeof(char));
        if (valueCopy == NULL)
        {
            *error = INSUFFICIENT_MEMORY;
            return;
        }
        strcpy(valueCopy, value);
        ListElement* newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            free(valueCopy);
            *error = INSUFFICIENT_MEMORY;
            return;
        }
        newElement->value = valueCopy;
        list->size = 1;
        list->head = newElement;
        list->tail = newElement;
        list->head->numberOfDuplicateValues = 1;
        return;
    }
    ListElement* head = list->head;
    while (head != NULL)
    {
        if (strcmp(value, head->value) == 0)
        {
            head->numberOfDuplicateValues++;
            *error = ELEMENT_REPEATS;
            return;
        }
        head = head->next;
    }
    if (head == NULL)
    {
        char* valueCopy = calloc(strlen(value) + 1, sizeof(char));
        if (valueCopy == NULL)
        {
            *error = INSUFFICIENT_MEMORY;
            return;
        }
        strcpy(valueCopy, value);
        ListElement* newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            free(valueCopy);
            *error = INSUFFICIENT_MEMORY;
            return;
        }
        newElement->value = valueCopy;
        list->size++;
        list->tail->next = newElement;
        list->tail = list->tail->next;
        newElement->numberOfDuplicateValues = 1;
    }
}

char* getValue(Position* position)
{
    return position->position->value;
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
        printf("%s - %d\n", element->value, element->numberOfDuplicateValues);
        element = element->next;
    }
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

bool inList(List* list, const char* value)
{
    ListElement* element = list->head;
    while (element != NULL)
    {
        if (strcmp(value, element->value) == 0)
        {
            return true;
        }
        element = element->next;
    }
    return false;
}

int returnNumberOfDuplicateValues(List* list, const char* value)
{
    ListElement* element = list->head;
    while (element != NULL)
    {
        if (strcmp(value, element->value) == 0)
        {
            return element->numberOfDuplicateValues;
        }
        element = element->next;
    }
    return 0;
}
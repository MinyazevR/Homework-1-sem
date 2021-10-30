#pragma once
#include <stdbool.h>
#include <malloc.h>

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

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for the first position
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(List* list, Position* position, int* error);

// Function for moving to the next position
Position* next(Position* position);

// Function for moving to the previous position
Position* previous(Position* position);
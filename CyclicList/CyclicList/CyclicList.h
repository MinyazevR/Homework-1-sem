#pragma once
#include <stdbool.h>
#include <malloc.h>

// Structure containing pointers to the "first" and "last" list item
typedef struct List List;

// Structure containing pointers to the next and previous list item and a value variable for list items
typedef struct ListElement ListElement;

// Structure containing a pointer to the position of a list item
typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for the first position
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(List* list, Position** position, int* error);

// Function for moving to the next position
Position* next(Position* position);

// Function for moving to the previous position
Position* previous(Position* position);

// Function that returns the value of the first element
int returnFirstElementValue(List* list);

// Function that returns the value of an element
int get(Position* position);

// Function that returns the first element
ListElement* returnFirstElement(List* list);

// Function that returns the last element
ListElement* returnLastElement(List* list);

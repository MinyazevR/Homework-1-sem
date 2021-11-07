#pragma once

// Structure that represents cyclic list
typedef struct List List;

// Structure for implementing a cyclic list
typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for finding a pointer to the first element
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(List* list, Position* position, int* error);

// Function for finding a pointer to the next element
Position* next(Position* position);

// Function for finding a pointer to the previous element
Position* previous(Position* position);

// Function that returns the value of the first element
int returnFirstElementValue(List* list);

// Function that returns the value of an element
int get(Position* position);

// Function for finding the number of items in the list
int numberOfElements(List* list);

// Function for freeing up memory
void freePosition(Position* position);


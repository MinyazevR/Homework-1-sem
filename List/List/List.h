#pragma once

// Structure that represents list
typedef struct List List;

// Structure describing the position of an item in the list
typedef struct Position Position;

typedef enum Error
{
    NOT_ERROR,
    EMPTY_LIST,
    INSUFFICIENT_MEMORY,
    ELEMENT_IS_MISSING,
    POSITION_FOUND
} Error;
// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, Error* error);

// Function for finding a pointer to the first element
Position* first(List* list, Error* error);

// Function to remove an item from the list
void removeElement(Position* position, List* list);

// Function for finding a pointer to the next element
Position* next(Position* position);

// Function for finding a pointer to an element
Position* findPosition(int value, List* list, Error* error);

// Function for finding an element
int get(List* list, Position*  position, Error* error);

// Function for printing a list
void print(List* list);

// Function for finding a pointer to the previous element
Position* previous(Position* position);

// Function for freeing up memory
void freePosition(Position* position);

// Function to return the size of the list
int returnSize(List* list);
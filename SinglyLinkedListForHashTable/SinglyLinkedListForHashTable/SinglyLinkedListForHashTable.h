#pragma once
#include <stdbool.h>

// Structure that represents list
typedef struct List List;

// This is a structure describing the position of an item in the list.
typedef struct Position Position;

// Enum type for working with errors
typedef enum Error
{
    NOT_ERROR,
    EMPTY_LIST,
    INSUFFICIENT_MEMORY,
    ELEMENT_REPEATS
} Error;

// Function for creating a list
List* createList(Error* error);

// Function for deleting a list
void deleteList(List* list);

// Function for freeing up memory
void deletePosition(Position* position);

// Function for adding an item to a list
void add(List* list, const char* value, Error* error);

// function to find a position to the first element
Position* first(List* list, Error* error);

// Function for finding a position to the next element
Position* next(Position* position);

// Function for checking an item for being at the end of the list
bool isLastElement(Position* position);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, Error* error);

// Function for finding the number of items in the list
int numberOfElements(List* list);

// Function for checking the emptiness of the list
bool isEmpty(List* list);

// Function that returns a value for the first element
char* getHeadValue(List* list);

// Function that returns a value of element
char* getValue(Position* position);

// Function for error decoding
const char* decodingError(Error error);

// Function for determining the location of an item in the list
bool inList(List* list, const char* value);

// Function for counting the number of duplicate elements
int returnNumberOfDuplicateValues(List* list, const char* value);
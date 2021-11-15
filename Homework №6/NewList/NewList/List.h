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
    INSUFFICIENT_MEMORY
}Error;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for freeing up memory
void deletePosition(Position* position);

// Function for adding an item to a list
void add(List* list, const char* firstValue, const char* secondValue , Error* error);

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

// Function for checking the list for the content of a single element
bool isOneElement(List* list);

// Function that returns a value for the first element
char* getHeadFirstValue(List* list);

// Function that returns a value for the first element
char* getHeadSecondValue(List* list);

// Function for finding a position to the last element
Position* last(List* list, Error* error);

// Returns the value of any element
char* getFirstValue(Position* position);

// Returns the value of any element
char* getSecondValue(Position* position);

// Function for comparing lists
bool compareList(List* firstList, List* secondList);

// Function for error decoding
const char* decodingError(Error error);
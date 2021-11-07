#pragma once
#include <stdbool.h>
#include <malloc.h>

// Structure containing pointers to the beginning and end of the list
typedef struct List List;

typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for deleting a position
void deletePosition(Position* position);

// Function for adding an item to a list
void add(List* list, Position* position, char* firstValue, char* secondValue , int* error);

// Function for the first position
Position* first(List* list, int* error);

// Function for moving to the next position
Position* next(Position* position);

// Function for checking an item for being at the end of the list
bool isLast(Position* position);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, int* error);

// Function for finding the number of items in the list
int numberOfElements(List* list, int* error);

// Function for checking the emptiness of the list
bool isEmpty(List* list);

// Function for checking the list for the content of a single element
bool isOneElement(List* list);

// Function that returns a value for the first element
int* getHeadFirstValue(List* list);

// Function that returns a value for the first element
int* getHeadSecondValue(List* list);

// Function for finding the position of the last element
Position* last(List* list, int* error);

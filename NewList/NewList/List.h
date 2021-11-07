#pragma once
#include <stdbool.h>

// Structure that represents list
typedef struct List List;

// Structure that represents list
typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for freeing up memory
void deletePosition(Position* position);

// Function for adding an item to a list
void add(List* list, Position* position, char* firstValue, char* secondValue , int* error);

// function to find a pointer to the first element
Position* first(List* list, int* error);

// Function for finding a pointer to the next element
Position* next(Position* position);

// Function for checking an item for being at the end of the list
bool isLastElement(Position* position);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, int* error);

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

// Function for finding a pointer to the last element
Position* last(List* list, int* error);

// Returns the value of any element
char* getFirstValue(Position* position);

// Returns the value of any element
char* getSecondValue(Position* position);
